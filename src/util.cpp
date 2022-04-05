//
// Created by bbrez on 2/15/2022.
//

#include "util.h"

#include <algorithm>
#include <sstream>

#include <iostream>

/**
 * @brief verifica se um caractere possui representação gráfica
 * 
 * @param c caractere a ser verificado
 * @return true o caractere possui representação grafica
 * @return false o caractere não possui representação grafica
 */
bool paa::is_printable(unsigned char c) {
	return c > 32;
}

/**
 * @brief verifica se um caractere é um separador
 * 
 * @param c caractere a ser verificado
 * @return true o caractere é um separador
 * @return false o caractere não é um separador
 */
bool paa::is_separator(unsigned char c){
    std::vector<char> separator_list = {' ', ',', '.', '?', '!', ';', '\n', '\t', '\r',
                                        ':', '(', ')', '[', ']', '{', '}', '\'', '\"'};

    auto compare = [c](char comp){
        return c == comp;
    };

    return std::ranges::any_of(separator_list.begin(), separator_list.end(), compare);

//    for(const auto &comp: separator_list){ //mais lento
//        if(comp == c) return true;
//    }
//    return false;
}

/**
 * @brief retorna em string a representação hexadecimal do caractere
 * 
 * @param c caractere a ser convertido
 * @return std::string representação hexadecimal em forma de string
 */
std::string paa::to_hex(unsigned char c) {
    std::stringstream buffer;
    buffer << "\\0x" << std::uppercase << std::hex << (int)c << std::dec;
    return buffer.str();
}

/**
 * @brief lê uma string de um arquivo de entrada
 * 
 * @param file arquivo a ser lido
 * @return std::string string lida do arquivo
 * 
 * @pre o arquivo deve estar  aberto
 * @post a posição de leitura do arquivo avança o tamanho da string lida
 */
std::string paa::read_string(std::ifstream &file) {
    unsigned char tam;
    char *str;
    file.read(reinterpret_cast<char *>(&tam), sizeof(unsigned char)); //ler o tamanho da string
    str = new char[tam+1];
    file.read(str, tam);
    str[tam]='\0';

    std::string retorno(str);

	delete[] str;

    return retorno;
}

/**
 * @brief escreve uma string em um arquivo de saida
 * 
 * @param file arquivo a ser escrito
 * @param str string a ser escrita no arquivo
 * @pre o arquivo deve estar aberto e a string não deve ser vazia
 * @post a string é escrita no arquivo e o arquivo avança o tamanho da string escrita
 */
void paa::write_string(std::ofstream &file, const std::string& str) {
    unsigned char tam = str.length();
    file.write(reinterpret_cast<const char*>(&tam), sizeof(unsigned char));
    file.write(str.c_str(), tam);
}
