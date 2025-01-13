#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <codecvt>
#include <locale>
#include <vector>
#include <regex>
using namespace std;
 
wstring leArquivo( );
 
vector<wstring> separaPalavras();

vector<pair<wstring, int>> contadorPalavras();