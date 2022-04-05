//
// Created by bbrez on 2/23/2022.
//

#ifndef PAA_HUFFMANCODE_H
#define PAA_HUFFMANCODE_H

#include <string>
#include <queue>
#include <functional>

#include "FrequencyMap.h"

namespace paa {

    /**
     * @class HuffmanCode 
     * Classe que cria um código de Huffman a partir do mapa de frequências de um arquivo
     */
    class HuffmanCode {
    public:
        /**
         * @brief Constroi um novo objeto HuffmanCode
         * 
         * @param fm mapa de frequência em que o código é baseado
         * @pre mapa de frequência criado adequadamente
         * @post código de Huffman montado e pronto para uso
         */
        explicit HuffmanCode(const paa::FrequencyMap &fm);

        ~HuffmanCode();

        /**
         * @brief mostra no terminal a arvore do código de Huffman
         * @post a arvore do código de huffman é escrita no terminal
         */
        void print_tree() const;

        /**
         * @brief getter do código de Huffman de uma palavra
         * 
         * @param palavra palavra a ser procurada no mapa de códigos
         * @return std::string código da palavra
         * 
         * @pre a palavra deve existir no mapa de códigos
         * @post função não altera o estado do programa
         */
        std::string get_code(const std::string &palavra) const;

        /**
         * @brief getter do mapa de códigos
         * 
         * @return std::unordered_map<std::string, std::string> 
         * 
         * @post função não altera o estado do programa
         */
        std::unordered_map<std::string, std::string> get_code_map() const;

    private:

        /**
         * @brief estrutura auxiliar para a criação do código de Huffman
         */
        struct tree_node {
            bool is_folha;
            std::string codigo;
            std::pair<std::string, int> value;
            struct tree_node *left, *right;
        };

        /** @brief fila de prioridade para auxiliar na criação do código de Huffman*/
        std::priority_queue<HuffmanCode::tree_node *, std::vector<HuffmanCode::tree_node *>, std::function<bool(tree_node*, tree_node*)>> *prio_queue;

        /** @brief hashmap não ordenado com os códigos de Huffman da palavra */
        std::unordered_map<std::string, std::string> codes;

        /**
         * @brief cria a arvore com os códigos de huffman
         * 
         * @pre as palavras devem ser inseridas como nós na fila de prioridade e marcadas como folhas
         * @post a arvore é montada e é o único nó na fila de prioridade
         */
        void build_tree();

        /**
         * @brief mostra um nó no terminal e seus filhos
         * 
         * @param no nó a ser mostrado
         * 
         * @pre o nó deve existir
         * @post o nó é escrito no terminal e uma chamada recursiva é feita para seus filhos
         */
        void print_no(const tree_node *no) const;

        /**
         * @brief deleta um nó e seus filhos
         * 
         * @param no nó a ser deletado
         * 
         * @pre o nó deve existir
         * @post nó e seus filhos deletados
         */
        void delete_no(tree_node *no);

        /**
         * @brief gera os códigos de Huffman para a arvore, deve ser chamado com o nó raiz e uma string vazia
         * 
         * @param node nó da arvore a ser calculado
         * @param current_code código atual na arvore
         */
        void generate_codes(tree_node *node, const std::string &current_code);
    };
};

#endif //PAA_HUFFMANCODE_H
