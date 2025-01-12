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

wstring lePalavra() {
    wifstream inputFile("texto.txt"); 
    wstring palavra;  

    if (inputFile.is_open()) { 
        inputFile >> palavra;
    } 

    return palavra;  
}



