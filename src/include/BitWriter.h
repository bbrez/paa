//
// Created by bbrez on 3/8/22.
//

#ifndef PAA_BITWRITER_H
#define PAA_BITWRITER_H

#include <fstream>

namespace paa {
    /**
     * @class BitWriter
     * Permite a escrita de bits únicos em um arquivo de texto
     */
    class BitWriter {
    public:
        /**
         * @brief Constroi um novo objeto Bit Writer
         * 
         * @param saida arquivo de saida
         * 
         * @pre o arqruivo de saida deve estar aberto na posição de escrita desejada
         * @post o objeto é criado, pronto para a escrita do arquivo passado
         */
        explicit BitWriter(std::ofstream &saida);

        ~BitWriter();

        /**
         * @brief escreve apenas um bit no arquivo
         * 
         * @param bit o bit a ser escrito no arquivo, deve ser passado como um byte contendo apenas 1 ou 0
         * 
         * @pre o arquivo a ser escrito deve estar aberto
         * @post valores só são escritos no arquivo ao completar um byte, então a chamada de close() é importante ao terminar as escritas desejadas
         */
        void write(unsigned char bit);

        /**
         * @brief fecha o arquivo de escrita
         * 
         * @return unsigned char quantidade de bits escritos no último byte
         * 
         * @pre o arquivo a ser escrito deve estar aberto
         * @post o arquivo de entrada em si não é fechado, mas sim trata apropriadamente o fim da escrita de bits
         */
        unsigned char close();

    private:
        unsigned char buffer; /** Buffer de escrita para o arquivo*/
        int buffer_bits; /** Quantidade de bits no arquivo, escreve no arquivo somente quando buffer_bits == 8*/
        std::ofstream &saida; /** Referência do arquivo de saida */
    };
};

#endif //PAA_BITWRITER_H
