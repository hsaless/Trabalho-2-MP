/**
 * \file conta_palavras.cpp
 */

#include "conta_palavras.hpp"


/** 
 * @brief verifica situacao do jogo da velha  
 * @author Programador 
 * @param  velha descreve o parametro
 * 
 *  Descrever o que a funcao faz
 */ 

std::string leArquivo() {
    std::ifstream inputFile("texto.txt"); 
    std::string linha;  
    std::string texto;

    if (inputFile.is_open()) { 
        bool flag = true;
        while (getline(inputFile, linha)) {
            if (!flag) {
                texto += "\n";  
            }
            texto += linha;  
            flag = false;  
        }
    } 

    return texto;  
}

std::string removePontuacao(const std::string& palavra) {
    size_t fim = palavra.size();
    while (fim > 0 && ispunct(palavra[fim - 1])) {
        --fim;
    }
    return palavra.substr(0, fim);
}

std::vector<std::string> separaPalavras() {
    std::vector<std::string> palavras = {};
    std::string texto = leArquivo();
    int texto_size = texto.size();

    std::string palavra_atual = "";
    bool ehLetra;

    for (int i = 0; i < texto_size; i++) {
        ehLetra = (texto[i] != ' ') && (texto[i] != '\n');

        if (!ehLetra) {
            if (!palavra_atual.empty()) {
                palavras.push_back(removePontuacao(palavra_atual));
            }
            palavra_atual = ""; 
        } else {
            palavra_atual.push_back(texto[i]);
        }

        if ((i + 1) == texto_size && !palavra_atual.empty()) {
            palavras.push_back(removePontuacao(palavra_atual));
        }
    }

    return palavras;
}

std::vector<std::pair<std::string, int>> contadorPalavras() {
    std::vector<std::string> palavras = separaPalavras();
    std::vector<std::pair<std::string, int>> resultado = {};
    for (const auto& palavra : palavras) {
        auto it = find_if(resultado.begin(), resultado.end(), [&palavra](const std::pair<std::string, int>& p) {
            return p.first == palavra;
        });

        if (it != resultado.end()) {
            it->second++;
        } else {
            resultado.push_back(std::make_pair(palavra, 1));
        }
    }

    return resultado;
}
