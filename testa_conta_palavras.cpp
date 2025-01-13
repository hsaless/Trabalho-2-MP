
/**
 * \file testa_velha.cpp
 */

#include "conta_palavras.hpp"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"


wstring toWString(const string& str) {
    wstring_convert<codecvt_utf8_utf16<wchar_t>> converter;
    return converter.from_bytes(str);
}


void escreveArquivo(const string& text) {
    wofstream outputFile("texto.txt", ios::out | ios::trunc);
    outputFile.imbue(locale("pt_BR.UTF-8"));
    wstring wtext = toWString(text); 
    outputFile << wtext;
    outputFile.close();
}



TEST_CASE( "Testa ler palavra", "[single-file]" ) {
	string teste1 = "teste";
	escreveArquivo(teste1);
    REQUIRE( toWString(teste1) == leArquivo() );
	escreveArquivo("");


} 

TEST_CASE( "Testa ler mais de uma palavra", "[single-file]" ) {
	string teste2 = "duas palavras";
	escreveArquivo(teste2);
    REQUIRE( toWString(teste2) == leArquivo() );
	escreveArquivo("");


} 

TEST_CASE( "Testa ler mais de uma linha", "[single-file]" ) {
	string teste3 = "linha 1\nlinha 2\nlinha 3";
	escreveArquivo(teste3);
    REQUIRE( toWString(teste3) == leArquivo() );
	escreveArquivo("");


} 

TEST_CASE( "Testa se ele retorna todas as palavras", "[single-file]" ) {
	string teste4 = "esse eh um\n teste para ler\n todas as palavras";
	escreveArquivo(teste4);
	vector<wstring> esperado_t4 = {
        L"esse", 
        L"eh", 
        L"um", 
        L"teste", 
        L"para", 
        L"ler", 
        L"todas", 
        L"as", 
        L"palavras"
    };
    REQUIRE( esperado_t4 == separaPalavras() );
	escreveArquivo("");


}

TEST_CASE( "Testa se ele retorna todas as palavras se tem pontuação na frase", "[single-file]" ) {
	string teste5 = "esse eh um\n teste! para. ler\n todas as palavras";
	escreveArquivo(teste5);
	vector<wstring> esperado_t5 = { 
        L"esse", 
        L"eh", 
        L"um", 
        L"teste", 
        L"para", 
        L"ler", 
        L"todas", 
        L"as", 
        L"palavras"
    };
    REQUIRE( esperado_t5 == separaPalavras() );
	escreveArquivo("");


}

TEST_CASE( "Testa a contagem de cada palavra", "[single-file]" ) {
	string teste6 = "esse eh um\n teste! para. ler\n todas as palavras";
	escreveArquivo(teste6);
	vector<pair<wstring, int>> esperado_t6 = { 
        {L"esse", 1}, 
        {L"eh", 1}, 
        {L"um", 1}, 
        {L"teste", 1}, 
        {L"para", 1}, 
        {L"ler", 1}, 
        {L"todas", 1}, 
        {L"as", 1}, 
        {L"palavras", 1}
    };
    REQUIRE( esperado_t6 == contadorPalavras() );
	escreveArquivo("");


}

TEST_CASE( "Testa a contagem de cada palavra caso tenha a mesma palavra mas com maiusculo", "[single-file]" ) {
	string teste7 = "esse eh um\n teste! para. ler\n todas as Palavras e palavras";
	escreveArquivo(teste7);
	vector<pair<wstring, int>> esperado_t7 = { 
        {L"esse", 1}, 
        {L"eh", 1}, 
        {L"um", 1}, 
        {L"teste", 1}, 
        {L"para", 1}, 
        {L"ler", 1}, 
        {L"todas", 1}, 
        {L"as", 1}, 
        {L"Palavras", 1},
        {L"e", 1},
        {L"palavras", 1}
    };
    REQUIRE( esperado_t7 == contadorPalavras() );
	escreveArquivo("");


}

TEST_CASE( "Testa a contagem de cada palavra caso tenha a mesma palavra repetida algumas vezes", "[single-file]" ) {
	string teste7 = "esse eh um\n teste! para. ler teste\n todas teste as para Palavras teste e palavras Palavras Palavras";
	escreveArquivo(teste7);
	vector<pair<wstring, int>> esperado_t7 = { 
        {L"esse", 1}, 
        {L"eh", 1}, 
        {L"um", 1}, 
        {L"teste", 4}, 
        {L"para", 2}, 
        {L"ler", 1}, 
        {L"todas", 1}, 
        {L"as", 1}, 
        {L"Palavras", 3},
        {L"e", 1},
        {L"palavras", 1}
    };
    REQUIRE( esperado_t7 == contadorPalavras() );
	escreveArquivo("");


}