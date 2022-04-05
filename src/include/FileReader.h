//
// Created by bbrez on 3/14/22.
//

#ifndef PAA_FILEREADER_H
#define PAA_FILEREADER_H


#include <fstream>
#include <sstream>

namespace paa {
    /**
     * @class FileReader
     * Auxilia a leitura do arquivo no modo desejado
     */
    class FileReader {
    public:
        /**
         * @brief enum MODE
         * indica a seleção de modos disponíveis para leitura
         */
        typedef enum MODE {
            character, // modo de leitura por caractere
            word // modo de leitura por palavra
        } MODE;

        /**
         * @brief Constroi um novo objeto FileReader
         * 
         * @param infile arquivo que será lido
         * @param m modo de leitura do arquiv
         * 
         * @pre arquivo deve estar aberto e o modo deve ser válido
         * @post o objeto é criado, pronto para leitura de um arquivo
         */
        FileReader(std::ifstream &infile, MODE m);

        /**
         * @brief verifica se o arquivo acabou
         * 
         * @return true o arquivo acabou
         * @return false o arquivo ainda não acabou
         * 
         * @pre o arquivo deve estar aberto
         * @post função não modifica o estado do programa
         */
        bool eof() const;

        /**
         * @brief lê a próxima palavra ou caractere do arquivo
         * 
         * @return std::string dados lidos
         * @pre o arquivo deve estar aberto e não acabado
         * @post o arquivo pode ter acabado após a leitura e deve ser verificado
         */
        std::string get_next();

    private:

        MODE m; //armazena o modo de leitura sendo utilizado
        std::ifstream &infile; //arquivo de leitura
        std::stringstream buffer; //buffer para leitura

        /**
         * @brief lê um caractere do arquivo
         * 
         * @return std::string caractere lido
         * @pre o arquivo deve estar aberto e não acabado
         * @post o arquivo pode ter acabado após a leitura e deve ser verificado
         */
        std::string get_char();

        /**
         * @brief lê uma palavra do arquivo
         * 
         * @return std::string palavra lida
         * @pre o arquivo deve estar aberto e não acabado
         * @post o arquivo pode ter acabado após a leitura e deve ser verificado
         */
        std::string get_word();
    };
};


#endif //PAA_FILEREADER_H
