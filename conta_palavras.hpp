#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <codecvt>
#include <locale>
#include <vector>
#include <regex>
 
std::string leArquivo();

std::string removePontuacaoENumeros(const std::string& palavra);

std::vector<std::string> separaPalavras();

std::vector<std::pair<std::string, int>> contadorPalavras(); 