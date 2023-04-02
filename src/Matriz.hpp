#ifndef __MATRIZ_HPP
#define __MATRIZ_HPP

#include <iostream>
#include "Caminho.hpp"
#include "Numero.hpp"

using namespace std;

class Matriz{
    private:
        Numero **matriz;
        Caminho sequencia;
        int linha, coluna, tamanhoLinha, tamanhoColuna;
        Matriz *proximo;
        
    public:
        /*************************************************************** INICIO CONSTRUTORES */
        Matriz();
        Matriz(int numeroLinha, int numeroColuna);

        /*************************************************************** FINAL CONSTRUTORES */

        /*************************************************************** INICIO GETTERS AND SETTERS */
        Numero **getMatriz(); 
        void setMatriz(Numero **newMatriz);
        int getTamanhoLinha();
        int getTamanhoColuna();
        void setTamanho(int newTamanhoLinha, int newTamanhoColuna);
        int getLinha();
        void setLinha(int newLinha);
        int getColuna();
        void setColuna(int newColuna);
        Caminho getSequencia();
        void setSequencia(Caminho newSequencia);
        Matriz *getProximo();
        void setProximo(Matriz *newProximo);
        /*************************************************************** FINAL GETTERS AND SETTERS */

        /*************************************************************** INICIO METODOS */
        void addNumber(int number);
        void print();
        void createCaminho();
        /************************************************************** FINAL METODOS */
};
#endif