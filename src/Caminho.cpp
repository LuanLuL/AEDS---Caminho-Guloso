#include "Caminho.hpp"

/************************************************** INICIO CONSTRUTORES */
Caminho::Caminho(){
    this->inicio = NULL;
    this->final = NULL;
    this->somaTotalNumeros = 0;
}

Caminho::Caminho(int number){
    this->inicio = new Numero(number);
    this->final = this->inicio;
    this->somaTotalNumeros = number;
}
/************************************************** FINAL CONSTRUTORES */

/************************************************** INICIO GETTERS AND SETTERS */
Numero *Caminho::getInicio(){
    return this->inicio;
}

void Caminho::setInicio(Numero *newInicio){
    this->inicio = newInicio;
}

Numero *Caminho::getFinal(){
    return this->final;
}

void Caminho::setFinal(Numero *newFinal){
    this->final = newFinal;
}

int Caminho::getSomaTotalNumeros(){
    return this->somaTotalNumeros;
}
/************************************************** FINAL GETTERS AND SETTERS */

/************************************************** INICIO METODOS */
int Caminho::size(){
    if(empty()){
        return 0;
    }
    int tamanho = 0;
    Numero *aux = this->inicio;
    do{
        aux = aux->getProximo();
        tamanho = tamanho + 1;
    }while(aux != NULL);
    return tamanho;
}

int Caminho::search(int number){
    Numero *aux = this->inicio;
    int posicao = 0;
    while(aux != NULL){
        if(aux->getValor() == number){
            break;
        }
        posicao = posicao + 1;
        aux = aux->getProximo();
    }
    if(aux == NULL){
        return -1;
    }
    return posicao;
}

void Caminho::insertInicio(Numero newNumero){
    Numero *newN = new Numero(newNumero.getValor());
    this->somaTotalNumeros = this->somaTotalNumeros + newN->getValor();
    if(empty()){
        this->inicio = newN;
        this->final = newN;
    }
    else{
        newN->setProximo(this->inicio);
        this->inicio = newN;
    }
}

void Caminho::insertFinal(Numero newNumero){
    Numero *newN = new Numero(newNumero.getValor());
    this->somaTotalNumeros = this->somaTotalNumeros + newN->getValor();
    if(empty()){
        this->inicio = newN;
        this->final = newN;
    }
    else{
        this->final->setProximo(newN);
        this->final = newN;
    }
}

void Caminho::removeFinal(){
    this->somaTotalNumeros = this->somaTotalNumeros - this->final->getValor();
    if(this->inicio->getProximo() == NULL){
        delete this->inicio->getProximo();
        this->inicio = NULL;
    }
    else if(this->inicio->getProximo()->getProximo() == NULL){
        delete this->inicio->getProximo();
        this->inicio->setProximo(NULL);
    }
    else{
        Numero *antesDoAnterior = this->inicio;
        Numero *anterior = this->inicio->getProximo();
        Numero *elemento = this->inicio->getProximo()->getProximo();

        while (elemento != NULL)
        {
            Numero *aux = anterior; 
            anterior = elemento;
            antesDoAnterior = aux;
            elemento = elemento->getProximo();
        }
        delete antesDoAnterior->getProximo();
        antesDoAnterior->setProximo(NULL);
        this->final = antesDoAnterior;
    }
}

bool Caminho::empty(){
    return (this->inicio == NULL);
}

void Caminho::print(){
    Numero *aux = this->inicio;
    if(empty()){
        cout << "---> A lista não possui elementos!";
    }
    else{
        while (aux != NULL){
            cout << " " << aux->getValor();
            aux = aux->getProximo();
        }
        cout << " = " << this->somaTotalNumeros;
    }
}
/************************************************** FINAL METODOS */