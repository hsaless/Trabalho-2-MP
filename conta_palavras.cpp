/**
 * \file conta_palavras.cpp
 */

#include "conta_palavras.hpp"


/**
 * @brief a função le uma string e transforma ela em wstring. 
 * 
 *  - o input é uma string qualquer.
 *
 * @return std::wstring a string convertida em wstring.
 */
std::wstring stringToWstring(const std::string& str) {
  std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
  return converter.from_bytes(str);
}

/**
 * @brief a função le uma wstring e transforma ela em string.
 * 
 *  - o input é uma wstring qualquer.
 *
 * @return std::string a wstring convertida em string.
 */
std::string wstringToString(const std::wstring& wstr) {
  std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
  return converter.to_bytes(wstr);
}

/**
 * @brief a le o que conteúdo de um arquivo.txt.
 * 
 *  - não tem input mas é usado o arquivo texto.txt.
 *
 * @return std::string a string contendo o conteúdo do texto.
 */
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

/**
 * @brief a função lê uma string e retorna a mesma string sem números e pontuação.
 * 
 *  @param std::string string que vai ter seus pontos e números removidos.
 *
 * @return std::string a string tendo as pontuações e números retirados.
 */
std::string removePontuacaoENumeros(const std::string& palavra) {
  std::string palavra_nova = "";
  for (int i = 0; i < palavra.size(); i++) {
    if (!isdigit(palavra[i]) && !ispunct(palavra[i])) {
      palavra_nova += palavra[i];
    }
  }
  return palavra_nova;
}

/**
 * @brief a função lê uma string e retorna um vetor com as palavras separadas da string lida no arquivo.
 * 
 *  - não tem input.
 *
 * @return std::vector<std::string> um vetor contendo em cada posição sua uma palavra do arquivo na ordem que elas aparecem.
 */
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
        if (!palavra_atual.empty()) {
          palavras.push_back(palavra_atual);
        }
      }
      palavra_atual = "";
    } else {
      palavra_atual.push_back(texto[i]);
    }

    if ((i + 1) == texto_size && !palavra_atual.empty()) {
      palavra_atual = removePontuacaoENumeros(palavra_atual);
      if (!palavra_atual.empty()) {
        palavras.push_back(palavra_atual);
      }
    }
  }

  return palavras;
}

/**
 * @brief Conta a ocorrência de cada palavra no arquivo.
 *
 *  -  diferencia os acentos e entre maiúscula e minúscula.
 *
 * @return std::vector<std::pair<std::string, int>> um vetor de pair 
 * em que em cada pair o primeiro elemento é a palavra e o segundo o número de ocorrências dela.
 */
std::vector<std::pair<std::string, int>> contadorPalavras() {
  std::vector<std::string> palavras = separaPalavras();
  std::vector<std::pair<std::string, int>> resultado = {};
  for (const auto& palavra : palavras) {
    auto it = find_if(resultado.begin(), resultado.end(),
                      [&palavra](const std::pair<std::string, int>& p) {
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

/**
 * @brief Normaliza uma palavra retirando o acento de um caracter e deixando ele minúsculo.
 *
 * @param std::string uma string contendo uma única palavra.
 *
 * @return std::string a string contendo a palavra normalizada sem acentos e sem letras maiúsuclas.
 */
std::string normalizaPalavra(const std::string& palavra) {
  std::unordered_map<wchar_t, wchar_t> letras = {
      {L'á', L'a'}, {L'à', L'a'}, {L'â', L'a'}, {L'ã', L'a'},
      {L'ä', L'a'}, {L'é', L'e'}, {L'è', L'e'}, {L'ê', L'e'},
      {L'ë', L'e'}, {L'í', L'i'}, {L'ì', L'i'}, {L'î', L'i'},
      {L'ï', L'i'}, {L'ó', L'o'}, {L'ò', L'o'}, {L'ô', L'o'},
      {L'õ', L'o'}, {L'ö', L'o'}, {L'ú', L'u'}, {L'ù', L'u'},
      {L'û', L'u'}, {L'ü', L'u'}, {L'ç', L'c'}, {L'Á', L'a'},
      {L'À', L'a'}, {L'Â', L'a'}, {L'Ã', L'a'}, {L'Ä', L'a'},
      {L'É', L'e'}, {L'È', L'e'}, {L'Ê', L'e'}, {L'Ë', L'e'},
      {L'Í', L'i'}, {L'Ì', L'i'}, {L'Î', L'i'}, {L'Ï', L'i'},
      {L'Ó', L'o'}, {L'Ò', L'o'}, {L'Ô', L'o'}, {L'Õ', L'o'},
      {L'Ö', L'o'}, {L'Ú', L'u'}, {L'Ù', L'u'}, {L'Û', L'u'},
      {L'Ü', L'u'}, {L'Ç', L'c'}};

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

/**
 * @brief Ordena o vetor de pair contendo cada palavra e a quantidade de suas ocorrências por ordem alfabética.
 *
 * @param std::vector<std::pair<std::string, int>> um vetor de pair em que o primeiro elemento é uma palavra
 * e o segundo elemento é a quantidade de ocorrências da palavra.
 *
 * @return std::vector<std::pair<std::string, int>> um vetor de pair ordenado alfabeticamente.
 */
std::vector<std::pair<std::string, int>> ordenadorPalavras(
    std::vector<std::pair<std::string, int>>& contPalavras) {
  std::vector<std::tuple<std::string, std::string, int>> resultado;
  for (int i = 0; i < contPalavras.size(); ++i) {
    std::string palavraOriginal = contPalavras[i].first;
    int valor = contPalavras[i].second;
    std::string palavraNormalizada = normalizaPalavra(palavraOriginal);
    resultado.push_back({palavraNormalizada, palavraOriginal, valor});
  }
  std::sort(resultado.begin(), resultado.end());
  std::vector<std::pair<std::string, int>> contPalavrasOrdenado;
  for (int i = 0; i < resultado.size(); ++i) {
    std::string palavraOriginal = std::get<1>(resultado[i]);
    int valor = std::get<2>(resultado[i]);

    contPalavrasOrdenado.push_back({palavraOriginal, valor});
  }
  return contPalavrasOrdenado;
}

/**
 * @brief Formata o vetor de pair contendo cada palavra e sua ocorrência para o formato desejado.
 *
 * @param std::vector<std::pair<std::string, int>> um vetor de pair ordenado em ordem alfabética.
 *
 * @return std::string uma string contendo as palavras e seu número de ocorrência ordenadas alfabéticamente e formatadas para resposta.
 */
std::string formataResposta(
    std::vector<std::pair<std::string, int>> palavrasOrdenadas) {
  std::string resposta_formatada = "";
  for (int i = 0; i < palavrasOrdenadas.size(); i++) {
    std::string palavra = palavrasOrdenadas[i].first;
    std::string valor = std::to_string(palavrasOrdenadas[i].second);
    resposta_formatada += palavra + ": " + valor + "\n";
  }
  return resposta_formatada;
}