#include <iostream>
#include <locale>
#include <string>
#include <fstream>
#include "ListMatrizes.hpp"
#include "Matriz.hpp"

using namespace std;

ListMatrizes lerMatrizesQuadradas(string txt){
    ListMatrizes returnListMatrizes;
    try{
        fstream inFile;
        inFile.open(txt.c_str());
        if(!inFile){
            throw "../main.cpp::lerTxt ---> Não foi possível abrir o arquivo de entrada";
        }
        string numberStr;
        int aux = 0, tamanhoLinha = 0, tamanhoColuna = 0, aux2 =0, numberInt, limite = 0;
        Matriz m;
        while (!inFile.eof()){
            if(aux == 0){
                getline(inFile, numberStr);
                if(aux2 == 0){
                    tamanhoLinha = atoi(&numberStr.at(0));
                    tamanhoColuna = atoi(&numberStr.at(2));
                    aux2 = aux2 + 1;
                }
                Matriz newM(tamanhoLinha, tamanhoColuna);
                m = newM;
                aux = aux + 1;
            }
            else{
                inFile >> numberStr;
                numberInt = atoi(numberStr.c_str());
                m.addNumber(numberInt);
                limite++;
                if(limite == (m.getTamanhoLinha() * m.getTamanhoColuna())){
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

ListMatrizes lerMatrizesQuadradasVariadas(string txt){
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
                Matriz newM(numberInt, numberInt);
                m = newM;
            }
            else{
                numberInt = atoi(numberStr.c_str());
                m.addNumber(numberInt);
                limite++;
                if(limite == (m.getTamanhoLinha() * m.getTamanhoColuna())){
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

ListMatrizes lerMatrizesDinamicas(string txt){
    ListMatrizes returnListMatrizes;
    try{
        fstream inFile;
        inFile.open(txt.c_str());
        if(!inFile){
            throw "../main.cpp::lerTxt ---> Não foi possível abrir o arquivo de entrada";
        }
        string numberStr;
        int aux = 0, tamanhoLinha = 0, tamanhoColuna = 0, numberInt, limite = 0;
        Matriz m;
        while (!inFile.eof()){
            if(aux == 0){
                getline(inFile, numberStr);
                if(numberStr.size() < 1){
                    getline(inFile, numberStr);
                }
                tamanhoLinha = atoi(&numberStr.at(0));
                tamanhoColuna = atoi(&numberStr.at(2));
                Matriz newM(tamanhoLinha, tamanhoColuna);
                m = newM;
                aux = aux + 1;
            }
            else{
                inFile >> numberStr;
                numberInt = atoi(numberStr.c_str());
                m.addNumber(numberInt);
                limite++;
                if(limite == (m.getTamanhoLinha() * m.getTamanhoColuna())){
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
    int resposta = 0;
    do{
        cout << "\nAquivos disponíveis:\n\n";
        cout << "\t1 - input.data\n\t2 - input_2.data\n\t3 - input_3.data\n\t4 - Sair";
        cout << "\n\nEscolha o arquivo de entrada: ";
        cin >> resposta;
        switch (resposta){
            case 1:
            {
                listaM = lerMatrizesQuadradas("input.data");
                listaM.print();
                cout << "\n*********************************\n";
                break;
            } 
            case 2:
                {
                    listaM = lerMatrizesQuadradasVariadas("input_2.data");
                    listaM.print();
                    cout << "\n*********************************\n";
                    break;
                }
            case 3:
                {
                    listaM = lerMatrizesDinamicas("input_3.data");
                    listaM.print();
                    cout << "\n*********************************\n";
                    break;
                }
            case 4:
                {
                    cout << "\nSaindo...";
                    break;
                }
            default:
                 cout << "\nERRO...ERRO... Opção invalida ...ERRO...ERRO\n";
                 cout << "\n*********************************\n";
                break;
        }
    }while(resposta != 4);
    cout << "\n\n************* FIM *************\n\n"; 
    return 0;
}