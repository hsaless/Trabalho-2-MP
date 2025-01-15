/**
 * \file testa_velha.cpp
 */

#include "conta_palavras.hpp"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

void escreveArquivo(const std::string& text) {
    std::ofstream outputFile("texto.txt", std::ios::out | std::ios::trunc);
    outputFile.imbue(std::locale("pt_BR.UTF-8"));
    outputFile << text;
    outputFile.close();
}

TEST_CASE("Testa ler palavra", "[single-file]") {
    std::string teste1 = "teste";
    escreveArquivo(teste1);
    REQUIRE(teste1 == leArquivo());
    escreveArquivo("");
}

TEST_CASE("Testa ler mais de uma palavra", "[single-file]") {
    std::string teste2 = "duas palavras";
    escreveArquivo(teste2);
    REQUIRE(teste2 == leArquivo());
    escreveArquivo("");
}

TEST_CASE("Testa ler mais de uma linha", "[single-file]") {
    std::string teste3 = "linha 1\nlinha 2\nlinha 3";
    escreveArquivo(teste3);
    REQUIRE(teste3 == leArquivo());
    escreveArquivo("");
}

TEST_CASE("Testa se ele retorna todas as palavras", "[single-file]") {
    std::string teste4 = "esse eh um\n teste para ler\n todas as palavras";
    escreveArquivo(teste4);
    std::vector<std::string> esperado_t4 = {
        "esse", "eh", "um", "teste", "para", "ler", "todas", "as", "palavras"};
    REQUIRE(esperado_t4 == separaPalavras());
    escreveArquivo("");
}

TEST_CASE("Testa se ele retorna todas as palavras se tem pontuação na frase", "[single-file]") {
    std::string teste5 = "esse é um\n teste! para. ler\n todas as palavras";
    escreveArquivo(teste5);
    std::vector<std::string> esperado_t5 = {
        "esse", "é", "um", "teste", "para", "ler", "todas", "as", "palavras"};
    REQUIRE(esperado_t5 == separaPalavras());
    escreveArquivo("");
}

TEST_CASE("Testa a contagem de cada palavra", "[single-file]") {
    std::string teste6 = "esse eh um\n teste! para. ler\n todas as palavras";
    escreveArquivo(teste6);
    std::vector<std::pair<std::string, int>> esperado_t6 = {
        {"esse", 1}, {"eh", 1}, {"um", 1}, {"teste", 1}, {"para", 1},
        {"ler", 1}, {"todas", 1}, {"as", 1}, {"palavras", 1}};
    REQUIRE(esperado_t6 == contadorPalavras());
    escreveArquivo("");
}

TEST_CASE("Testa a contagem de cada palavra caso tenha a mesma palavra mas com maiusculo", "[single-file]") {
    std::string teste8 = "esse eh um\n teste! para. ler\n todas as Palavras e palavras";
    escreveArquivo(teste8);
    std::vector<std::pair<std::string, int>> esperado_t8 = {
        {"esse", 1}, {"eh", 1}, {"um", 1}, {"teste", 1}, {"para", 1},
        {"ler", 1}, {"todas", 1}, {"as", 1}, {"Palavras", 1}, {"e", 1}, {"palavras", 1}};
    REQUIRE(esperado_t8 == contadorPalavras());
    escreveArquivo("");
}

TEST_CASE("Testa a contagem de cada palavra caso tenha a mesma palavra repetida algumas vezes", "[single-file]") {
    std::string teste9 = "esse eh um\n teste! para. ler teste\n todas teste as para Palavras teste e palavras Palavras Palavras";
    escreveArquivo(teste9);
    std::vector<std::pair<std::string, int>> esperado_t9 = {
        {"esse", 1}, {"eh", 1}, {"um", 1}, {"teste", 4}, {"para", 2},
        {"ler", 1}, {"todas", 1}, {"as", 1}, {"Palavras", 3}, {"e", 1}, {"palavras", 1}};
    REQUIRE(esperado_t9 == contadorPalavras());
    escreveArquivo("");
}

TEST_CASE("Testa se o retorno da contagem de cada palavra é ordenada sem maiuscula e acento", "[single-file]") {
    std::string teste9 = "esse eh um\n teste! para. ler teste\n todas teste as para teste e palavras";
    escreveArquivo(teste9);
    std::vector<std::pair<std::string, int>> esperado_t9 = {
        {"as", 1}, {"e", 1}, {"eh", 1}, {"esse", 1}, {"ler", 1},
        {"palavras", 1}, {"para", 2}, {"teste", 4}, {"todas", 1}, {"um", 1}};

    auto resultado = contadorPalavras();


    REQUIRE(esperado_t9 == ordenadorPalavras(resultado));
    escreveArquivo("");
}

TEST_CASE("Testa se difere números de palavras", "[single-file]") {
    std::string teste10 = "esse é um\n teste! para. 23 01923 2342 ler\n todas as 232palavras";
    escreveArquivo(teste10);
    std::vector<std::string> esperado_t10 = {
        "esse", "é", "um", "teste", "para", "ler", "todas", "as", "palavras"};
    REQUIRE(esperado_t10 == separaPalavras());
    escreveArquivo("");
}

TEST_CASE("Testa se o retorno da contagem de cada palavra é ordenada com maiuscula e sem acento", "[single-file]") {
    std::string teste11 = "esse eh um\n teste! para. ler teste\n Todas teste As para teste e palavras";
    escreveArquivo(teste11);
    std::vector<std::pair<std::string, int>> esperado_t11 = {
        {"As", 1}, {"e", 1}, {"eh", 1}, {"esse", 1}, {"ler", 1},
        {"palavras", 1}, {"para", 2}, {"teste", 4}, {"Todas", 1}, {"um", 1}};

    auto resultado = contadorPalavras();


    REQUIRE(esperado_t11 == ordenadorPalavras(resultado));
    escreveArquivo("");
}
