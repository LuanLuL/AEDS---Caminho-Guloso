#include <iostream>
#include <locale>
#include <string>
#include <fstream>
#include "ListMatrizes.hpp"
#include "Matriz.hpp"

using namespace std;

ListMatrizes lerTxtP1(string txt){
    ListMatrizes returnListMatrizes;
    try{
        fstream inFile;
        inFile.open(txt.c_str());
        if(!inFile){
            throw "../main.cpp::lerTxt ---> Não foi possível abrir o arquivo de entrada";
        }
        string numberStr;
        int aux = 0, numberInt, limite = 0;
        Matriz m;
        while (!inFile.eof()){
            inFile >> numberStr;
            if(aux == 0){
                aux = aux + 1;
                numberInt = atoi(numberStr.c_str());
                Matriz newM(numberInt);
                m = newM;
            }
            else{
                numberInt = atoi(numberStr.c_str());
                m.addNumber(numberInt);
                limite++;
                if(limite == (m.getTamanho() * m.getTamanho())){
                    aux = 0;
                    limite = 0;
                    m.createCaminho();
                    returnListMatrizes.insertFinal(m);
                }
            }
        }
        inFile.close();
    }
    catch(const char *msg){
        cerr << "\n\nERRO...ERRO... " << msg << " ...ERRO...ERRO\n\n";
    }
    return returnListMatrizes;
}

ListMatrizes lerTxtP2(string txt){
    ListMatrizes returnListMatrizes;
    try{
        fstream inFile;
        inFile.open(txt.c_str());
        if(!inFile){
            throw "../main.cpp::lerTxt ---> Não foi possível abrir o arquivo de entrada";
        }
        string numberStr;
        int aux = 0, tamanho = 0, aux2 =0, numberInt, limite = 0;
        Matriz m;
        while (!inFile.eof()){
            if(aux == 0){
                getline(inFile, numberStr);
                if(aux2 == 0){
                    tamanho = atoi(&numberStr.at(0));
                    aux2 = aux2 + 1;
                }
                Matriz newM(tamanho);
                m = newM;
                aux = aux + 1;
            }
            else{
                inFile >> numberStr;
                numberInt = atoi(numberStr.c_str());
                m.addNumber(numberInt);
                limite++;
                if(limite == (m.getTamanho() * m.getTamanho())){
                    aux = 0;
                    limite = 0;
                    m.createCaminho();
                    returnListMatrizes.insertFinal(m);
                }
            }
        }
        inFile.close();
    }
    catch(const char *msg){
        cerr << "\n\nERRO...ERRO... " << msg << " ...ERRO...ERRO\n\n";
    }
    return returnListMatrizes;
}

int main(){
    setlocale(LC_ALL, "Portuguese");
    cout << "\n************* INICIO *************\n";
    ListMatrizes listaM;
    string nomeArqTxtEntrada;
    cout << "\nDigite o nome do arquivo de entrada (com extesão): ";
    cin >> nomeArqTxtEntrada;
    char padraoDinamico;
    bool resposta = false;
    do{
        cout << "\nO arquivo de entrada está no padrão dinamico? [Y/N]";
        cin >> padraoDinamico;
        switch (padraoDinamico){
            case 'Y':
            case 'y':
            {
                listaM = lerTxtP1(nomeArqTxtEntrada);
                resposta = true;
                break;
            } 
            case 'N':
            case 'n':
                {
                    listaM = lerTxtP2(nomeArqTxtEntrada);
                    resposta = true;
                    break;
                }
            
            default:
                break;
        }
    }while(resposta == false);
    listaM.print();
    cout << "\n************* FIM *************\n\n";
    return 0;
}