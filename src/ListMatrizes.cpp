#include "ListMatrizes.hpp"

/************************************************** INICIO CONSTRUTORES */
ListMatrizes::ListMatrizes(){
    this->inicio = NULL;
    this->final = NULL;
    this->somaTotalCaminhos = 0;
}

ListMatrizes::ListMatrizes(Matriz firstMatriz){
    this->inicio = new Matriz(firstMatriz);
    this->final = this->inicio;
    this->somaTotalCaminhos = this->inicio->getSequencia().getSomaTotalNumeros();
}
/************************************************** FINAL CONSTRUTORES */

/************************************************** INICIO GETTERS AND SETTERS */
Matriz *ListMatrizes::getInicio(){
    return this->inicio;
}

void ListMatrizes::setInicio(Matriz *newInicio){
    this->inicio = newInicio;
}

Matriz *ListMatrizes::getFinal(){
    return this->final;
}

void ListMatrizes::setFinal(Matriz *newFinal){
    this->final = newFinal;
}

int ListMatrizes::getSomaTotalCaminhos(){
    return this->somaTotalCaminhos;
}
/************************************************** FINAL GETTERS AND SETTERS */

/************************************************** INICIO METODOS */
int ListMatrizes::size(){
    if(empty()){
        return 0;
    }
    int tamanho = 0;
    Matriz *aux = this->inicio;
    do{
        aux = aux->getProximo();
        tamanho = tamanho + 1;
    }while(aux != NULL);
    return tamanho;
}

void ListMatrizes::insertInicio(Matriz newMatriz){
    Matriz *newM = new Matriz(newMatriz);
    this->somaTotalCaminhos = this->somaTotalCaminhos + newM->getSequencia().getSomaTotalNumeros();
    if(empty()){
        this->inicio = newM;
        this->final = newM;
    }
    else{
        newM->setProximo(this->inicio);
        this->inicio = newM;
    }
}

void ListMatrizes::insertFinal(Matriz newMatriz){
    Matriz *newM = new Matriz(newMatriz);
    this->somaTotalCaminhos = this->somaTotalCaminhos + newM->getSequencia().getSomaTotalNumeros();
    if(empty()){
        this->inicio = newM;
        this->final = newM;
    }
    else{
        this->final->setProximo(newM);
        this->final = newM;
    }
}

void ListMatrizes::removeFinal(){
    this->somaTotalCaminhos = this->somaTotalCaminhos - this->final->getSequencia().getSomaTotalNumeros();
    if(this->inicio->getProximo() == NULL){
        delete this->inicio->getProximo();
        this->inicio = NULL;
    }
    else if(this->inicio->getProximo()->getProximo() == NULL){
        delete this->inicio->getProximo();
        this->inicio->setProximo(NULL);
    }
    else{
        Matriz *antesDoAnterior = this->inicio;
        Matriz *anterior = this->inicio->getProximo();
        Matriz *elemento = this->inicio->getProximo()->getProximo();

        while (elemento != NULL)
        {
            Matriz *aux = anterior; 
            anterior = elemento;
            antesDoAnterior = aux;
            elemento = elemento->getProximo();
        }
        delete antesDoAnterior->getProximo();
        antesDoAnterior->setProximo(NULL);
        this->final = antesDoAnterior;
    }
}

bool ListMatrizes::empty()
{
    return (this->inicio == NULL);
}

void ListMatrizes::print()
{
    Matriz *aux = this->inicio;
    if(empty()){
        cout << "---> A lista não possui elementos!";
    }
    else{
        while (aux != NULL){
            aux->print();
            aux = aux->getProximo();
        }
    }
    cout << "\nA soma total dos caminhos gulosos é: " << this->somaTotalCaminhos << "\n";
}
/************************************************** FINAL METODOS */