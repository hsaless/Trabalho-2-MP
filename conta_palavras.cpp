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

std::wstring stringToWstring(const std::string& str) {
    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
    return converter.from_bytes(str);
}

std::string wstringToString(const std::wstring& wstr) {
    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
    return converter.to_bytes(wstr);
}

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




std::string removePontuacaoENumeros(const std::string& palavra) {
    std::string palavra_nova = "";
    for(int i = 0; i < palavra.size(); i++){
        if(!isdigit(palavra[i]) && !ispunct(palavra[i])){
            palavra_nova += palavra[i];
        }
    }
    return palavra_nova;
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
                palavra_atual = removePontuacaoENumeros(palavra_atual);
                if(!palavra_atual.empty()){
                    palavras.push_back(palavra_atual);
                }
                
            }
            palavra_atual = ""; 
        } else {
            palavra_atual.push_back(texto[i]);
        }

        if ((i + 1) == texto_size && !palavra_atual.empty()) {
            palavra_atual = removePontuacaoENumeros(palavra_atual);
            if(!palavra_atual.empty()){
                palavras.push_back(palavra_atual);
            }
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
std::string removeAccentsAndToLower(const std::string& palavra) {
    std::unordered_map<wchar_t, wchar_t> letras = {
        {L'á', L'a'}, {L'à', L'a'}, {L'â', L'a'}, {L'ã', L'a'}, {L'ä', L'a'},
        {L'é', L'e'}, {L'è', L'e'}, {L'ê', L'e'}, {L'ë', L'e'},
        {L'í', L'i'}, {L'ì', L'i'}, {L'î', L'i'}, {L'ï', L'i'},
        {L'ó', L'o'}, {L'ò', L'o'}, {L'ô', L'o'}, {L'õ', L'o'}, {L'ö', L'o'},
        {L'ú', L'u'}, {L'ù', L'u'}, {L'û', L'u'}, {L'ü', L'u'},
        {L'ç', L'c'},
        {L'Á', L'a'}, {L'À', L'a'}, {L'Â', L'a'}, {L'Ã', L'a'}, {L'Ä', L'a'},
        {L'É', L'e'}, {L'È', L'e'}, {L'Ê', L'e'}, {L'Ë', L'e'},
        {L'Í', L'i'}, {L'Ì', L'i'}, {L'Î', L'i'}, {L'Ï', L'i'},
        {L'Ó', L'o'}, {L'Ò', L'o'}, {L'Ô', L'o'}, {L'Õ', L'o'}, {L'Ö', L'o'},
        {L'Ú', L'u'}, {L'Ù', L'u'}, {L'Û', L'u'}, {L'Ü', L'u'},
        {L'Ç', L'c'}
    };

    std::wstring wstr = stringToWstring(palavra);
    std::wstring palavra_final;
    for (wchar_t c : wstr) {
        if (letras.find(c) != letras.end()) {
            palavra_final += letras[c];
        } else {
            palavra_final += std::towlower(c);
        }
    }

    return wstringToString(palavra_final);
}
std::vector<std::pair<std::string, int>> ordenadorPalavras(std::vector<std::pair<std::string, int>>& contPalavras){
    std::sort(contPalavras.begin(), contPalavras.end());

    return contPalavras;
}


