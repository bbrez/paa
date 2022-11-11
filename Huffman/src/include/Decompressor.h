//
// Created by bbrez on 3/15/22.
//

#ifndef PAA_DECOMPRESSOR_H
#define PAA_DECOMPRESSOR_H

#include <unordered_map>
#include <string>
#include <fstream>

namespace paa{
    /**
     * @class Decompressor
     * Faz a descompressão de um arquivo criado pela classe Compressor
     */
    class Decompressor {
    public:
        Decompressor() = default;

        /**
         * @brief faz a descompressão do arquivo
         * 
         * @param infile arquivo de entrada
         * @param outfile arquivo de saida
         * 
         * @pre ambos os arquivos abertos e em suas posições iniciais
         * @post arquivo de saida possui o texto descomprimido
         */
        void decompress(std::ifstream &infile, std::ofstream &outfile);

    private:
        std::unordered_map<std::string, std::string> code_map; /** hashmap para onde são lidos os códigos de tradução */
        unsigned int pos_dados{}; /** posição no arquivo de entrada onde começam os dados */
        unsigned char last_bits{}; /** bits significativos do último byte do arquivo */

        /**
         * @brief faz a leitura do cabeçalho do arquivo
         * 
         * @param infile arquivo de entrada
         * 
         * @pre o arquivo deve estar aberto e em sua posição inicial
         * @post o cabeçalho é aberto e os valores necessários são armazenados em variáveis da classe, o arquivo aponta pra posição após o cabeçalho
         */
        void read_header(std::ifstream &infile);

        /**
         * @brief faz a leitura dos dados do arquivo de entrada e escreve no arquivo de saida traduzidos
         * 
         * @param infile arquivo de entrada
         * @param outfile arquivo de saida
         * 
         * @pre os arquivos devem estar abertos, o arquivo de entrada apontando para os dados e o de saida em posição inicial, o hashmap de códigos deve estar preenchido
         * @post o arquivo de saida contem os dados descomprimidos
         */
        void read_data(std::ifstream &infile, std::ofstream &outfile);
    };
};


#endif //PAA_DECOMPRESSOR_H
