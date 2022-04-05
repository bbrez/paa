//
// Created by bbrez on 2/23/2022.
//

#include "HuffmanCode.h"

#include <iostream>

using namespace paa;

/**
 * @brief Constroi um novo objeto HuffmanCode
 * 
 * @param fm mapa de frequência em que o código é baseado
 * @pre mapa de frequência criado adequadamente
 * @post código de Huffman montado e pronto para uso
 */
HuffmanCode::HuffmanCode(const FrequencyMap& fm) {
	//função de comparação para a lista de prioridade
	std::function<bool(HuffmanCode::tree_node*, HuffmanCode::tree_node*)> cmp = [](tree_node *left, tree_node *right) {
		return left->value.second > right->value.second;
	};

    this->prio_queue = new std::priority_queue<tree_node*, std::vector<tree_node*>, decltype(cmp)>(cmp);
    for (const auto &no: fm.get_map()) {
        auto *no_arv = new tree_node;
        no_arv->value = no;
        no_arv->is_folha = true;
        no_arv->left = nullptr;
        no_arv->right = nullptr;
        this->prio_queue->push(no_arv);
    }

	this->build_tree();
	//this->print_tree();
}

/**
 * @brief deleta um nó e seus filhos
 * 
 * @param no nó a ser deletado
 * 
 * @pre o nó deve existir
 * @post nó e seus filhos deletados
 */
void HuffmanCode::delete_no(HuffmanCode::tree_node *no) {
    if(!no->is_folha){
        delete_no(no->left);
        delete_no(no->right);
    }
    delete no;
}


HuffmanCode::~HuffmanCode() {
    while(!prio_queue->empty()){
        delete_no(prio_queue->top());
        prio_queue->pop();
    }
}

/**
 * @brief mostra um nó no terminal e seus filhos
 * 
 * @param no nó a ser mostrado
 * 
 * @pre o nó deve existir
 * @post o nó é escrito no terminal e uma chamada recursiva é feita para seus filhos
 */
void HuffmanCode::print_no(const HuffmanCode::tree_node *no) const {
    if (no->is_folha) {
        std::cout << "[palavra:'" << no->value.first << "', cod: " << no->codigo << "]";
//        std::cout << "['" << no->value.first <<  "', *, *]";
    } else {
        std::cout << "[" << no->value.second << ", ";
        if(no->left != nullptr) print_no(no->left);
        else std::cout << ", *";
        if(no->right != nullptr) print_no(no->right);
        else std::cout << ", *";
        std::cout << "]";
    }
}

/**
 * @brief mostra no terminal a arvore do código de Huffman
 * @post a arvore do código de huffman é escrita no terminal
 */
void HuffmanCode::print_tree() const{
    this->print_no(this->prio_queue->top());
    std::cout << '\n';
}

/**
 * @brief cria a arvore com os códigos de huffman
 * 
 * @pre as palavras devem ser inseridas como nós na fila de prioridade e marcadas como folhas
 * @post a arvore é montada e é o único nó na fila de prioridade
 */
void HuffmanCode::build_tree() {
    auto top_pop = [](auto queue) {
        auto node = queue->top();
        queue->pop();
        return node;
    };

    while(this->prio_queue->size()!= 1){
        auto *z = new tree_node;
        auto x = top_pop(this->prio_queue);
        auto y = top_pop(this->prio_queue);
        z->is_folha = false;
        z->left = x;
        z->right = y;
        z->value.first = "";
        z->value.second = x->value.second + y->value.second;
        this->prio_queue->push(z);
    }

    this->generate_codes(this->prio_queue->top(), "");
}

/**
 * @brief gera os códigos de Huffman para a arvore, deve ser chamado com o nó raiz e uma string vazia
 * 
 * @param node nó da arvore a ser calculado
 * @param current_code código atual na arvore
 */
void HuffmanCode::generate_codes(tree_node *node, const std::string& current_code) {
    node->codigo = current_code;
    if(node->left != nullptr) HuffmanCode::generate_codes(node->left, current_code + '0');
    if(node->right != nullptr) HuffmanCode::generate_codes(node->right, current_code + '1');
    if(node->is_folha) this->codes.emplace(std::pair<std::string, std::string>(node->value.first, node->codigo));
}

/**
 * @brief getter do código de Huffman de uma palavra
 * 
 * @param palavra palavra a ser procurada no mapa de códigos
 * @return std::string código da palavra
 * 
 * @pre a palavra deve existir no mapa de códigos
 * @post função não altera o estado do programa
 */
std::string HuffmanCode::get_code(const std::string& palavra) const {
    return this->codes.at(palavra);
}

/**
 * @brief getter do mapa de códigos
 * 
 * @return std::unordered_map<std::string, std::string> 
 * 
 * @post função não altera o estado do programa
 */
std::unordered_map<std::string, std::string> HuffmanCode::get_code_map() const {
    return this->codes;
}

