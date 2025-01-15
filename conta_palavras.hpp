#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <codecvt>
#include <locale>
#include <vector>
#include <regex>
#include <unordered_map>

std::wstring stringToWstring(const std::string& str);

std::string wstringToString(const std::wstring& wstr);
 
std::string leArquivo();

std::string removePontuacaoENumeros(const std::string& palavra);

std::vector<std::string> separaPalavras();

std::vector<std::pair<std::string, int>> contadorPalavras(); 

std::vector<std::pair<std::string, int>> ordenadorPalavras(std::vector<std::pair<std::string, int>>& contPalavras);