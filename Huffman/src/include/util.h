//
// Created by bbrez on 2/15/2022.
//

#ifndef PAA_UTIL_H
#define PAA_UTIL_H

#include <string>
#include <fstream>

namespace paa {
    /**
     * @brief verifica se um caractere possui representação gráfica
     * 
     * @param c caractere a ser verificado
     * @return true o caractere possui representação grafica
     * @return false o caractere não possui representação grafica
     */
    bool is_printable(unsigned char c);

    /**
     * @brief verifica se um caractere é um separador
     * 
     * @param c caractere a ser verificado
     * @return true o caractere é um separador
     * @return false o caractere não é um separador
     */
    bool is_separator(unsigned char c);

    /**
     * @brief retorna em string a representação hexadecimal do caractere
     * 
     * @param c caractere a ser convertido
     * @return std::string representação hexadecimal em forma de string
     */
    std::string to_hex(unsigned char c);

    /**
     * @brief lê uma string de um arquivo de entrada
     * 
     * @param file arquivo a ser lido
     * @return std::string string lida do arquivo
     * 
     * @pre o arquivo deve estar  aberto
     * @post a posição de leitura do arquivo avança o tamanho da string lida
     */
    std::string read_string(std::ifstream &file);

    /**
     * @brief escreve uma string em um arquivo de saida
     * 
     * @param file arquivo a ser escrito
     * @param str string a ser escrita no arquivo
     * @pre o arquivo deve estar aberto e a string não deve ser vazia
     * @post a string é escrita no arquivo e o arquivo avança o tamanho da string escrita
     */
    void write_string(std::ofstream &file, const std::string &str);
};

#endif //PAA_UTIL_H
