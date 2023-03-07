#include "Numero.hpp"

/************************************************** INICIO CONSTRUTORES */
Numero::Numero(){
    this->proximo = NULL;
    this->control = false;
}

Numero::Numero(int number){
    this->valor = number;
    this->proximo = NULL;
    this->control = false;
}
/************************************************** FINAL CONSTRUTORES */

/************************************************** INICIO GETTERS AND SETTERS */
int Numero::getValor(){
    return this->valor;
}

void Numero::setValor(int newValor){
    this->valor = newValor;
}

Numero *Numero::getProximo(){
    return this->proximo;
}

void Numero::setProximo(Numero *newProximo){
    this->proximo = newProximo;
}

bool Numero::getControl(){
    return this->control;
}

void Numero::setControl(bool newControl){
    this->control = newControl;
}
/************************************************** FINAL GETTERS AND SETTERS */