//
// Created by bbrez on 3/15/22.
//

#ifndef PAA_BITREADER_H
#define PAA_BITREADER_H

#include <fstream>


namespace paa {
    /**
     * @class BitReader
     * Permite a leitura de bits únicos de um arquivo de texto
     */
    class BitReader {
    public:
        /**
         * @brief Constroi um novo objeto Bit Reader
         * 
         * @param entrada arquivo de entrada
         * @param last_bits quantidade significativa de bits do ultimo byte
         *
         * @pre o arquivo de entrada deve estar aberto na posição de leitura desejada e last_bits deve ser 0 <= valor >=  8
         * @post o objeto é criado, pronto para leitura do arquivo passado
         */
        explicit BitReader(std::ifstream &entrada, unsigned char last_bits);

        ~BitReader() = default;

        /**
         * @brief lê um apenas um bit do arquivo
         * 
         * @return unsigned char o bit lido do arquivo na posição menos significativa de um byte
         * 
         * @pre o arquivo a ser lido deve estar aberto e não deve ter acabado
         * @post o valor retornado sempre será 1 ou 0 e o arquivo pode possivelmente ter acabado e deve ser verificado com has_next()
         */
        unsigned char read();

        /**
         * @brief verifica se ainda existem bits a serem lidos
         * 
         * @return true existe um bit a ser lido no buffer ou no arquivo
         * @return false não existem mais bits a serem lidos tanto no buffer quanto no arquivo
         * 
         * @pre o  arquivo deve estar aberto
         * @post não são feitas modificações no estado do programa
         */
        bool has_next() const;

    private:
        unsigned char buffer; /** Buffer de leitura do arquivo, apenas um byte porquê estamos trabalhando com bits */
        unsigned char last_bits; /** Quantidade de bits significativos no ultimo byte do arquivo  */
        int buffer_bits; /** Quantidade de bits que podem ser lidos do buffer ainda */
        std::ifstream &entrada; /** Referência do arquivo de entrada */
    };
}

#endif //PAA_BITREADER_H
