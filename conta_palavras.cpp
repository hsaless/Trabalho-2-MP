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
    wstring texto = leArquivo();
    int texto_size = texto.size();

    wstring palavra_atual = L"";
    bool ehLetra;

    for (int i = 0; i < texto_size; i++) {
        ehLetra = (texto[i] != L' ') && (texto[i] != L'\n');

        if (!ehLetra) {
            if (!palavra_atual.empty()) {
                palavras.push_back(palavra_atual);
            }
            palavra_atual = L""; 
        } else {
            palavra_atual.push_back(texto[i]);
        }

        if ((i + 1) == texto_size && !palavra_atual.empty()) {
            palavras.push_back(palavra_atual);
        }
    }

    return palavras;



}



