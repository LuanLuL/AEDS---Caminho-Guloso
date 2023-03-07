#include "Matriz.hpp"

/******************************************************************************************** INICIO CONSTRUTORES */
Matriz::Matriz(){
    this->tamanho = 0;
    this->linha = 0;
    this->coluna = 0;
    this->proximo = NULL;
}

Matriz::Matriz(int tamanahoMatriz){
    this->tamanho = tamanahoMatriz;
    this->matriz = (Numero**) calloc(this->tamanho, sizeof(Numero*));
    for(int i=0;i<this->tamanho;i++){
        this->matriz[i] = (Numero*) calloc(this->tamanho, sizeof(Numero));
    }
    this->linha = 0;
    this->coluna = 0;
    this->proximo = NULL;
}
/******************************************************************************************** FINAL CONSTRUTORES */

/******************************************************************************************** INICIO GETTERS AND SETTERS */
Numero **Matriz::getMatriz(){
    return this->matriz;
}


void Matriz::setMatriz(Numero **newMatriz){
    this->matriz = newMatriz;
}

int Matriz::getTamanho(){
    return this->tamanho;
}

void Matriz::setTamanho(int newTamanho){
    this->tamanho = newTamanho;
    this->matriz = (Numero**) calloc(this->tamanho, sizeof(Numero*));
    for(int i=0;i<this->tamanho;i++){
        this->matriz[i] = (Numero*) calloc(this->tamanho, sizeof(Numero));
    }
    this->linha = 0;
    this->coluna = 0;
}

int Matriz::getLinha(){
    return this->linha;
}

void Matriz::setLinha(int newLinha){
    this->linha = newLinha;
}

int Matriz::getColuna(){
    return this->coluna;
}

void Matriz::setColuna(int newColuna){
    this->coluna = newColuna;
}

Caminho Matriz::getSequencia(){
    return this->sequencia;
}

void Matriz::setSequencia(Caminho newSequencia){
    this->sequencia = newSequencia;
}

Matriz *Matriz::getProximo(){
    return this->proximo;
}

void Matriz::setProximo(Matriz *newProximo){
    this->proximo = newProximo;
}

/******************************************************************************************** FINAL GETTERS AND SETTERS */

/******************************************************************************************** INICIO METODOS */
void Matriz::addNumber(int number){
    try{
        if(this->linha == this->tamanho && this->coluna == this->tamanho){
			throw "../Matriz.cpp::addNumberMatriz ---> Matriz cheia";
		}
        Numero n(number);
        this->matriz[this->linha][this->coluna] = n;
        if(this->coluna == this->tamanho-1){
            this->linha++;
            this->coluna = 0;
        }
        else if(this->coluna != this->tamanho){
            this->coluna++;
        }
    }
    catch(const char *msg){
        cerr << "\n\nERRO...ERRO " << msg << " ...ERRO...ERRO\n\n";
    }
}

void Matriz::print(){
    cout << endl;
    for(int i=0;i<this->tamanho;i++){
        for(int j=0;j<this->tamanho;j++){
            cout << this->matriz[i][j].getValor() << " ";
        }
        cout << "\n";
    }
    cout << "\nCaminho Guloso:";
    this->sequencia.print();
    
    cout << endl;
}

void Matriz::createCaminho(){
    int linhaAux = 0, colunaAux = 0;
    Numero number;

    do{
        number.setValor(this->matriz[linhaAux][colunaAux].getValor());
        this->sequencia.insertFinal(number);
        this->matriz[linhaAux][colunaAux].setControl(true);

        if(linhaAux == 0 && colunaAux ==0){ //      CANTO SUPERIOR ESQUERDO
            if((this->matriz[linhaAux+1][colunaAux+1].getValor() >= this->matriz[linhaAux+1][colunaAux].getValor() || this->matriz[linhaAux+1][colunaAux].getControl()) && (this->matriz[linhaAux+1][colunaAux+1].getValor() >= this->matriz[linhaAux][colunaAux+1].getValor() || this->matriz[linhaAux][colunaAux+1].getControl()) && this->matriz[linhaAux+1][colunaAux+1].getControl() == false){
                //      MAIOR -> DIAGONAL INFERIOR DIREITA
                linhaAux = linhaAux +1;
                colunaAux = colunaAux + 1;
            }
            else if((this->matriz[linhaAux+1][colunaAux].getValor() >= this->matriz[linhaAux+1][colunaAux+1].getValor() || this->matriz[linhaAux+1][colunaAux+1].getControl()) && (this->matriz[linhaAux+1][colunaAux].getValor() >= this->matriz[linhaAux][colunaAux+1].getValor() || this->matriz[linhaAux][colunaAux+1].getControl()) && this->matriz[linhaAux+1][colunaAux].getControl() == false){
                //      MAIOR -> BAIXO
                linhaAux = linhaAux +1;
            }
            else if((this->matriz[linhaAux][colunaAux+1].getValor() >= this->matriz[linhaAux+1][colunaAux+1].getValor() || this->matriz[linhaAux+1][colunaAux+1].getControl()) && (this->matriz[linhaAux][colunaAux+1].getValor() >= this->matriz[linhaAux+1][colunaAux].getValor() || this->matriz[linhaAux+1][colunaAux].getControl()) && this->matriz[linhaAux][colunaAux+1].getControl() == false){
                //      MAIOR -> DIREITA
                colunaAux = colunaAux + 1;
            }
        }
        else if(linhaAux == 0 && colunaAux == this->tamanho-1){ //       CANTO SUPERIOR DIREITO
            if((this->matriz[linhaAux+1][colunaAux].getValor() >= this->matriz[linhaAux+1][colunaAux-1].getValor() || this->matriz[linhaAux+1][colunaAux-1].getControl()) && this->matriz[linhaAux+1][colunaAux].getControl() == false){
                //      MAIOR -> BAIXO
                linhaAux = linhaAux +1;
            }
            else if((this->matriz[linhaAux+1][colunaAux-1].getValor() >= this->matriz[linhaAux+1][colunaAux].getValor() || this->matriz[linhaAux+1][colunaAux].getControl()) && this->matriz[linhaAux+1][colunaAux-1].getControl() == false){
                //      MAIOR -> DIAGONAL INFERIOR ESQUERDA
                linhaAux = linhaAux +1;
                colunaAux = colunaAux -1;
            }
        }
        else if(linhaAux == this->tamanho-1 && colunaAux == 0){ //     CANTO INFERIOR ESQUERDO    
            //      SEGUE APENAS PARA A DIREITA
            colunaAux = colunaAux + 1;
        }
        else if(linhaAux == this->tamanho-1 && colunaAux == this->tamanho){ //      CANTO INFERIOR DIREITO
            //      FINALIZA O CAMINHO
        }
        else if(linhaAux == 0){ //      BORDA SUPERIOR
            if((this->matriz[linhaAux+1][colunaAux+1].getValor() >= this->matriz[linhaAux+1][colunaAux].getValor() || this->matriz[linhaAux+1][colunaAux].getControl()) && (this->matriz[linhaAux+1][colunaAux+1].getValor() >= this->matriz[linhaAux][colunaAux+1].getValor() || this->matriz[linhaAux][colunaAux+1].getControl()) && (this->matriz[linhaAux+1][colunaAux+1].getValor() >= this->matriz[linhaAux+1][colunaAux-1].getValor() || this->matriz[linhaAux+1][colunaAux-1].getControl()) && this->matriz[linhaAux+1][colunaAux+1].getControl() == false){
                //      MAIOR -> DIAGONAL INFERIOR DIREITA
                linhaAux = linhaAux +1;
                colunaAux = colunaAux + 1;
            }
            else if((this->matriz[linhaAux+1][colunaAux].getValor() >= this->matriz[linhaAux][colunaAux+1].getValor() || this->matriz[linhaAux][colunaAux+1].getControl()) && (this->matriz[linhaAux+1][colunaAux].getValor() >= this->matriz[linhaAux+1][colunaAux+1].getValor() || this->matriz[linhaAux+1][colunaAux+1].getControl()) && (this->matriz[linhaAux+1][colunaAux].getValor() >= this->matriz[linhaAux+1][colunaAux-1].getValor() || this->matriz[linhaAux+1][colunaAux-1].getControl()) && this->matriz[linhaAux+1][colunaAux].getControl() == false){
                //      MAIOR -> BAIXO
                linhaAux = linhaAux +1;
            }
            else if((this->matriz[linhaAux][colunaAux+1].getValor() >= this->matriz[linhaAux+1][colunaAux].getValor() || this->matriz[linhaAux+1][colunaAux].getControl()) && (this->matriz[linhaAux][colunaAux+1].getValor() >= this->matriz[linhaAux+1][colunaAux+1].getValor() || this->matriz[linhaAux+1][colunaAux+1].getControl()) && (this->matriz[linhaAux][colunaAux+1].getValor() >= this->matriz[linhaAux+1][colunaAux-1].getValor() || this->matriz[linhaAux+1][colunaAux-1].getControl()) && this->matriz[linhaAux][colunaAux+1].getControl() == false){
                //      MAIOR -> DIREITA
                colunaAux = colunaAux + 1;
            }
            else if((this->matriz[linhaAux+1][colunaAux-1].getValor() >= this->matriz[linhaAux+1][colunaAux].getValor() || this->matriz[linhaAux+1][colunaAux].getControl()) && (this->matriz[linhaAux+1][colunaAux-1].getValor() >= this->matriz[linhaAux][colunaAux+1].getValor() || this->matriz[linhaAux][colunaAux+1].getControl()) && (this->matriz[linhaAux+1][colunaAux-1].getValor() >= this->matriz[linhaAux+1][colunaAux+1].getValor() || this->matriz[linhaAux+1][colunaAux+1].getControl()) && this->matriz[linhaAux+1][colunaAux-1].getControl() == false){
                //      MAIOR -> DIAGONAL INFERIOR ESQUERDA
                linhaAux = linhaAux +1;
                colunaAux = colunaAux -1;
            }
        }
        else if(colunaAux == 0){ //      BORDA ESQUERDA
            if((this->matriz[linhaAux+1][colunaAux+1].getValor() >= this->matriz[linhaAux+1][colunaAux].getValor() || this->matriz[linhaAux+1][colunaAux].getControl()) && (this->matriz[linhaAux+1][colunaAux+1].getValor() >= this->matriz[linhaAux][colunaAux+1].getValor() || this->matriz[linhaAux][colunaAux+1].getControl()) && this->matriz[linhaAux+1][colunaAux+1].getControl() == false){
                //      MAIOR -> DIAGONAL INFERIOR DIREITA
                linhaAux = linhaAux +1;
                colunaAux = colunaAux + 1;
            }
            else if((this->matriz[linhaAux+1][colunaAux].getValor() >= this->matriz[linhaAux][colunaAux+1].getValor() || this->matriz[linhaAux][colunaAux+1].getControl()) && (this->matriz[linhaAux+1][colunaAux].getValor() >= this->matriz[linhaAux+1][colunaAux+1].getValor() || this->matriz[linhaAux+1][colunaAux+1].getControl()) && this->matriz[linhaAux+1][colunaAux].getControl() == false){
                //      MAIOR -> BAIXO
                linhaAux = linhaAux +1;
            }
            else if((this->matriz[linhaAux][colunaAux+1].getValor() >= this->matriz[linhaAux+1][colunaAux+1].getValor() || this->matriz[linhaAux+1][colunaAux+1].getControl()) && (this->matriz[linhaAux][colunaAux+1].getValor() >= this->matriz[linhaAux+1][colunaAux].getValor() || this->matriz[linhaAux+1][colunaAux].getControl()) && this->matriz[linhaAux][colunaAux+1].getControl() == false){
                //      MAIOR -> DIREITA
                colunaAux = colunaAux + 1;
            }
        }
        else if(linhaAux == this->tamanho-1){ //        BORDA INFERIOR
            //      SEGUE APENAS PARA A DIREITA
            colunaAux = colunaAux + 1;    
        }
        else if(colunaAux == this->tamanho-1){ //        BORDA DIREITA
            if((this->matriz[linhaAux+1][colunaAux].getValor() >= this->matriz[linhaAux+1][colunaAux-1].getValor() || this->matriz[linhaAux+1][colunaAux-1].getControl()) && (this->matriz[linhaAux+1][colunaAux].getValor() >= this->matriz[linhaAux][colunaAux-1].getValor() || this->matriz[linhaAux][colunaAux-1].getControl()) && this->matriz[linhaAux+1][colunaAux].getControl() == false){
                //      MAIOR -> BAIXO
                linhaAux = linhaAux +1;
            }
            else if((this->matriz[linhaAux+1][colunaAux-1].getValor() >= this->matriz[linhaAux+1][colunaAux].getValor() || this->matriz[linhaAux+1][colunaAux].getControl()) && (this->matriz[linhaAux+1][colunaAux-1].getValor() >= this->matriz[linhaAux][colunaAux-1].getValor() || this->matriz[linhaAux][colunaAux-1].getControl()) && this->matriz[linhaAux+1][colunaAux-1].getControl() == false){
                //      MAIOR -> DIAGONAL INFERIOR ESQUERDA
                linhaAux = linhaAux +1;
                colunaAux = colunaAux -1;
            }
            else if((this->matriz[linhaAux][colunaAux-1].getValor() >= this->matriz[linhaAux+1][colunaAux].getValor() || this->matriz[linhaAux+1][colunaAux].getControl()) && (this->matriz[linhaAux][colunaAux-1].getValor() >= this->matriz[linhaAux+1][colunaAux-1].getValor() || this->matriz[linhaAux+1][colunaAux-1].getControl()) && this->matriz[linhaAux][colunaAux-1].getControl() == false){
                //      MAIOR -> ESQUERDA
                colunaAux = colunaAux -1;
            }
        }
        else{ //        MEIO DA MATRIZ
            if((this->matriz[linhaAux+1][colunaAux+1].getValor() >= this->matriz[linhaAux][colunaAux+1].getValor() || this->matriz[linhaAux][colunaAux+1].getControl()) && (this->matriz[linhaAux+1][colunaAux+1].getValor() >= this->matriz[linhaAux+1][colunaAux].getValor() || this->matriz[linhaAux+1][colunaAux].getControl()) && (this->matriz[linhaAux+1][colunaAux+1].getValor() >= this->matriz[linhaAux+1][colunaAux-1].getValor() || this->matriz[linhaAux+1][colunaAux-1].getControl()) && (this->matriz[linhaAux+1][colunaAux+1].getValor() >= this->matriz[linhaAux][colunaAux-1].getValor() || this->matriz[linhaAux][colunaAux-1].getControl()) && this->matriz[linhaAux+1][colunaAux+1].getControl() == false){
                //      MAIOR -> DIAGONAL INFERIOR DIREITA
                linhaAux = linhaAux +1;
                colunaAux = colunaAux + 1;
            }
            else if((this->matriz[linhaAux+1][colunaAux].getValor() >= this->matriz[linhaAux+1][colunaAux+1].getValor() || this->matriz[linhaAux+1][colunaAux+1].getControl()) && (this->matriz[linhaAux+1][colunaAux].getValor() >= this->matriz[linhaAux][colunaAux+1].getValor() || this->matriz[linhaAux][colunaAux+1].getControl()) && (this->matriz[linhaAux+1][colunaAux].getValor() >= this->matriz[linhaAux+1][colunaAux-1].getValor() || this->matriz[linhaAux+1][colunaAux-1].getControl()) && (this->matriz[linhaAux+1][colunaAux].getValor() >= this->matriz[linhaAux][colunaAux-1].getValor() || this->matriz[linhaAux][colunaAux-1].getControl()) && this->matriz[linhaAux+1][colunaAux].getControl() == false){
                //      MAIOR -> BAIXO
                linhaAux = linhaAux +1;
            }
            else if((this->matriz[linhaAux][colunaAux+1].getValor() >= this->matriz[linhaAux+1][colunaAux+1].getValor() || this->matriz[linhaAux+1][colunaAux+1].getControl()) && (this->matriz[linhaAux][colunaAux+1].getValor() >= this->matriz[linhaAux+1][colunaAux].getValor() || this->matriz[linhaAux+1][colunaAux].getControl()) && (this->matriz[linhaAux][colunaAux+1].getValor() >= this->matriz[linhaAux+1][colunaAux-1].getValor() || this->matriz[linhaAux+1][colunaAux-1].getControl()) && (this->matriz[linhaAux][colunaAux+1].getValor() >= this->matriz[linhaAux][colunaAux-1].getValor() || this->matriz[linhaAux][colunaAux-1].getControl()) && this->matriz[linhaAux][colunaAux+1].getControl() == false){
                //      MAIOR -> DIREITA
                colunaAux = colunaAux + 1;
            }
            else if((this->matriz[linhaAux+1][colunaAux-1].getValor() >= this->matriz[linhaAux][colunaAux-1].getValor() || this->matriz[linhaAux][colunaAux-1].getControl()) && (this->matriz[linhaAux+1][colunaAux-1].getValor() >= this->matriz[linhaAux][colunaAux+1].getValor() || this->matriz[linhaAux][colunaAux+1].getControl()) && (this->matriz[linhaAux+1][colunaAux-1].getValor() >= this->matriz[linhaAux+1][colunaAux+1].getValor() || this->matriz[linhaAux+1][colunaAux+1].getControl()) && (this->matriz[linhaAux+1][colunaAux-1].getValor() >= this->matriz[linhaAux+1][colunaAux].getValor() || this->matriz[linhaAux+1][colunaAux].getControl()) && this->matriz[linhaAux+1][colunaAux-1].getControl() == false){
                //      MAIOR -> DIAGONAL INFERIOR ESQUERDA
                linhaAux = linhaAux +1;
                colunaAux = colunaAux -1;
            }
            else if((this->matriz[linhaAux][colunaAux-1].getValor() >= this->matriz[linhaAux][colunaAux+1].getValor() || this->matriz[linhaAux][colunaAux+1].getControl()) && (this->matriz[linhaAux][colunaAux-1].getValor() >= this->matriz[linhaAux+1][colunaAux+1].getValor() || this->matriz[linhaAux+1][colunaAux+1].getControl()) && (this->matriz[linhaAux][colunaAux-1].getValor() >= this->matriz[linhaAux+1][colunaAux].getValor() || this->matriz[linhaAux+1][colunaAux].getControl()) && (this->matriz[linhaAux][colunaAux-1].getValor() >= this->matriz[linhaAux+1][colunaAux-1].getValor() || this->matriz[linhaAux+1][colunaAux-1].getControl()) && this->matriz[linhaAux][colunaAux-1].getControl() == false){
                //      MAIOR -> ESQUERDA
                colunaAux = colunaAux -1;
            }
        }
    }while((linhaAux != this->tamanho-1) || (colunaAux != this->tamanho-1));
    number.setValor(this->matriz[linhaAux][colunaAux].getValor());
    this->sequencia.insertFinal(number);
}
/******************************************************************************************** FINAL METODOS */