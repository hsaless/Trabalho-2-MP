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

    if (inputFile.is_open()) { 
        getline(inputFile, linha);
    } 

    return linha;  
}



