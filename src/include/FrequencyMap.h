//
// Created by bbrez on 2/15/2022.
//

#ifndef PAA_FREQUENCYMAP_H
#define PAA_FREQUENCYMAP_H

#include <string>
#include <unordered_map>

#include "FileReader.h"

namespace paa {
    /**
     * @class FrequencyMap
     * Classe que calcula as frequências de palavras ou caracteres em um arquivo de texto
     */
    class FrequencyMap {
    public:

        FrequencyMap() = delete;

        /**
         * @brief Constroi um novo objeto FrequencyMap
         * 
         * @param infile arquivo a ser lido
         * @param m modo de leitura do arquivo
         * 
         * @pre o arquivo deve ser aberto e o modo deve ser válido
         * @post o objeto é criado, pronto para utilização, com as frequências já calculadas
         */
        explicit FrequencyMap(std::ifstream &infile, FileReader::MODE m);

        ~FrequencyMap() = default;

        /**
         * @brief escreve no terminal a representação do mapa de frequência
         * 
         * @pre o mapa de frequência deve ser bem formado
         * @post o mapa de frequencia é escrito no terminal
         */
        void print() const;

        /**
         * @brief Getter do mapa de frequências
         * 
         * @return const std::unordered_map<std::string, int>& referência do mapa de frequência
         * 
         * @post função não altera o estado do programa
         */
        const std::unordered_map<std::string, int> &get_map() const;

    private:
        /**
         * @brief função de incremento de uma palavra no mapa de frequência
         * 
         * @param s palavra a ser incrementada
         * 
         * @post a palavra é incrementada se já existia no mapa, se não existia é inserida com valor 1
         */
        void inc(const std::string &s);

        std::unordered_map<std::string, int> count_map; //hashmap não ordenado das frequências de palavras
        int total; //total de palavras lidas

    };
};
#endif //PAA_FREQUENCYMAP_H
