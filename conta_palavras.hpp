/**
 * \file conta_palavras.cpp
 */

#include "conta_palavras.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <codecvt>
#include <locale>
#include <vector>
#include <regex>
#include <unordered_map>
#include <tuple>

/**
 * @brief a função le uma string e transforma ela em wstring. 
 * 
 *  - o input é uma string qualquer.
 *
 * @return std::wstring a string convertida em wstring.
 */
std::wstring stringToWstring(const std::string& str);

/**
 * @brief a função le uma wstring e transforma ela em string.
 * 
 *  - o input é uma wstring qualquer.
 *
 * @return std::string a wstring convertida em string.
 */
std::string wstringToString(const std::wstring& wstr);

/**
 * @brief a le o que conteúdo de um arquivo.txt.
 * 
 *  - não tem input mas é usado o arquivo texto.txt.
 *
 * @return std::string a string contendo o conteúdo do texto.
 */
std::string leArquivo();

/**
 * @brief a função lê uma string e retorna a mesma string sem números e pontuação.
 * 
 *  @param std::string string que vai ter seus pontos e números removidos.
 *
 * @return std::string a string tendo as pontuações e números retirados.
 */
std::string removePontuacaoENumeros(const std::string& palavra);

/**
 * @brief a função lê uma string e retorna um vetor com as palavras separadas da string lida no arquivo.
 * 
 *  - não tem input.
 *
 * @return std::vector<std::string> um vetor contendo em cada posição sua uma palavra do arquivo na ordem que elas aparecem.
 */
std::vector<std::string> separaPalavras();

/**
 * @brief Conta a ocorrência de cada palavra no arquivo.
 *
 *  -  diferencia os acentos e entre maiúscula e minúscula.
 *
 * @return std::vector<std::pair<std::string, int>> um vetor de pair 
 * em que em cada pair o primeiro elemento é a palavra e o segundo o número de ocorrências dela.
 */
std::vector<std::pair<std::string, int>> contadorPalavras();

/**
 * @brief Conta a ocorrência de cada palavra no arquivo.
 *
 *  -  diferencia os acentos e entre maiúscula e minúscula.
 *
 * @return std::vector<std::pair<std::string, int>> um vetor de pair 
 * em que em cada pair o primeiro elemento é a palavra e o segundo o número de ocorrências dela.
 */
std::string normalizaPalavra(const std::string& palavra);

/**
 * @brief Ordena o vetor de pair contendo cada palavra e a quantidade de suas ocorrências por ordem alfabética.
 *
 * @param std::vector<std::pair<std::string, int>> um vetor de pair em que o primeiro elemento é uma palavra
 * e o segundo elemento é a quantidade de ocorrências da palavra.
 *
 * @return std::vector<std::pair<std::string, int>> um vetor de pair ordenado alfabeticamente.
 */
std::vector<std::pair<std::string, int>> ordenadorPalavras(
    std::vector<std::pair<std::string, int>>& contPalavras);

/**
 * @brief Formata o vetor de pair contendo cada palavra e sua ocorrência para o formato desejado.
 *
 * @param std::vector<std::pair<std::string, int>> um vetor de pair ordenado em ordem alfabética.
 *
 * @return std::string uma string contendo as palavras e seu número de ocorrência ordenadas alfabéticamente e formatadas para resposta.
 */
std::string formataResposta(
    std::vector<std::pair<std::string, int>> palavrasOrdenadas);
