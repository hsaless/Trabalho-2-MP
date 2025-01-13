/**
 * \file  conta_palavras.cpp
 */

 
#include "conta_palavras.hpp"


/** 
 * @brief verifica situacao do jogo da velha  
 * @author Programador 
 * @param  velha descreve o parametro
 * 
 *  Descrever o que a funcao faz
 */ 

wstring leArquivo() {
    wifstream inputFile("texto.txt"); 
    wstring linha;  
	wstring texto;

    if (inputFile.is_open()) { 
		bool flag = true;
        while (getline(inputFile, linha)) {
            if (!flag) {
                texto += L"\n";  
            }
            texto += linha;  
            flag = false;  
        }
    } 

    return texto;  
}

vector<wstring> separaPalavras(){
    vector<wstring> palavras = {};

    return palavras;

}



