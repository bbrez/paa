//
// Created by bbrez on 3/14/22.
//

#ifndef PAA_COMPRESSOR_H
#define PAA_COMPRESSOR_H


#include "HuffmanCode.h"

namespace paa {
    /**
     * @class Compressor
     * Faz a compressão de um arquivo de entrada para um arquivo de saida utilizando o modo selecionado
     */
    class Compressor {
    public:
        /**
         * @brief Constroi um novo objeto Compressor
         * 
         * @param hc Objeto HuffmanCode com o código de cada letra ou palavra que será utilizado na compressão
         * 
         * @pre o objeto HuffmanCode deve possuir um código bem formado
         * @post o objeto é criado, pronto para compressão de um arquivo
         */
        explicit Compressor(const HuffmanCode &hc);

        /**
         * @brief faz a compressão do arquivo
         * 
         * @param infile arquivo de onde é lido os dados a serem comprimidos
         * @param m o modo em que o arquivo está sendo comprimido
         * @param outfile arquivo onde será escrito os dados comprimidos
         * 
         * @pre os arquivos devem estar abertos e em seu inicio, o modo de leitura deve ser um valor adequado
         */
        void compress(std::ifstream &infile, FileReader::MODE m, std::ofstream &outfile);

    private:

        HuffmanCode hc; /** Objeto que armazena os códigos de compressão de cada palavra */

        /**
         * @brief escreve o cabeçalho do arquivo comprimido
         * 
         * @param outfile arquivo em que será escrito o cabeçalho
         * 
         * @pre o arquivo a ser escrito está aberto e em seu inicio, o código de huffman está preenchido
         * @post o arquivo de saida possui o cabeçalho escrito e aponta para a posição seguindo ele
         */
        void write_header(std::ofstream &outfile);

        /**
         * @brief escreve os dados do arquivo comprimido
         * 
         * @param infile arquivo em que serão lidas as palavras
         * @param m modo em que serão lidas as palavras
         * @param outfile arquivo em que serão escritos os dados
         * 
         * @pre ambos arquivos abertos, arquivo de entrada no inicio, arquivo de saida posicionado após o cabeçalho, modo de leitura valido
         * @post o arquivo de saida tem os dados escritos e pode ser fechado
         */
        void write_data(std::ifstream &infile, FileReader::MODE m, std::ofstream &outfile);
    };
};

#endif //PAA_COMPRESSOR_H
