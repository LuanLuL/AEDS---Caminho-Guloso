#ifndef __CAMINHO_HPP
#define __CAMINHO_HPP

#include <iostream>
#include "Numero.hpp"

using namespace std;

class Caminho{
    private:
        Numero *inicio;
        Numero *final;
        int somaTotalNumeros;
        
    public:
        /************************************************** INICIO CONSTRUTORES */
        Caminho();
        Caminho(int number);
        /************************************************** FINAL CONSTRUTORES */

        /************************************************** INICIO GETTERS AND SETTERS */
        Numero *getInicio();
        void setInicio(Numero *newInicio);
        Numero *getFinal();
        void setFinal(Numero *newFinal);
        int getSomaTotalNumeros();
        /************************************************** FINAL GETTERS AND SETTERS */

        /************************************************** INICIO METODOS */
        int size();
        int search(int number);
        void insertInicio(Numero newNumero);
        void insertFinal(Numero newNumero);
        void removeFinal();
        bool empty();
        void print();
        /************************************************** FINAL METODOS */
        
};
#endif