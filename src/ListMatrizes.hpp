#ifndef __LISTMATRIZES_HPP
#define __LISTMATRIZES_HPP

#include <iostream>
#include "Matriz.hpp"

using namespace std;

class ListMatrizes{
    private:
        Matriz *inicio;
        Matriz *final;
        int somaTotalCaminhos;
        
    public:
        /************************************************** INICIO CONSTRUTORES */
        ListMatrizes();
        ListMatrizes(Matriz firstMatriz);
        /************************************************** FINAL CONSTRUTORES */

        /************************************************** INICIO GETTERS AND SETTERS */
        Matriz *getInicio();
        void setInicio(Matriz *newInicio);
        Matriz *getFinal();
        void setFinal(Matriz *newFinal);
        int getSomaTotalCaminhos();
        /************************************************** FINAL GETTERS AND SETTERS */

        /************************************************** INICIO METODOS */
        int size();
        void insertInicio(Matriz newMatriz);
        void insertFinal(Matriz newMatriz);
        void removeFinal();
        bool empty();
        void print();
        /************************************************** FINAL METODOS */
        
};
#endif