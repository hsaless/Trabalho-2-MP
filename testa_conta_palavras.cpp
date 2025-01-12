
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
    REQUIRE( toWString(teste1) == lePalavra() );


} 


 
