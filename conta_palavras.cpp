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

wstring removePontuacao(const wstring& palavra) {
    size_t fim = palavra.size();
    while (fim > 0 && iswpunct(palavra[fim - 1])) {
        --fim;
    }
    return palavra.substr(0, fim);
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
                palavras.push_back(removePontuacao(palavra_atual));
            }
            palavra_atual = L""; 
        } else {
            palavra_atual.push_back(texto[i]);
        }

        if ((i + 1) == texto_size && !palavra_atual.empty()) {
            palavras.push_back(removePontuacao(palavra_atual));
        }
    }

    return palavras;



}

vector<pair<wstring, int>> contadorPalavras() {
    vector<wstring> palavras = separaPalavras();
    vector<pair<wstring, int>> resultado = {};
    for (const auto& palavra : palavras) {
        auto it = find_if(resultado.begin(), resultado.end(),[&palavra](const pair<wstring, int>& p) {
            return p.first == palavra;
        });

        if (it != resultado.end()) {
            it->second++;
        } else {
            resultado.push_back(make_pair(palavra, 1));
        }
    }

    return resultado;

    
}







