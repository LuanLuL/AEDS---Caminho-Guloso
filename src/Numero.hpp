#ifndef __NUMERO_HPP
#define __NUMERO_HPP

#include <iostream>

using namespace std;

class Numero{
    private:
        int valor;
        bool control;
        Numero *proximo;
    public:
        /************************************************** INICIO CONSTRUTORES */
        Numero();
        Numero(int number);
        /************************************************** FINAL CONSTRUTORES */

        /************************************************** INICIO GETTERS AND SETTERS */
        int getValor();
        void setValor(int newValor);
        Numero *getProximo();
		void setProximo(Numero* newProximo);
        bool getControl();
        void setControl(bool newControl);
        /************************************************** FINAL GETTERS AND SETTERS */
        
};


#endif