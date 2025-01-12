
/**
 * \file testa_velha.cpp
 */

#include "conta_palavras.hpp"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

void escreveArquivo(string text) {
    ofstream inputFile("texto.txt");
    inputFile << text;
    inputFile.close();
}


wstring toWString(const string& s) {
    wstring wstr(s.begin(), s.end());
    return wstr;
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

 
