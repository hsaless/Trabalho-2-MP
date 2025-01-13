
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