//
// Created by bbrez on 2/23/2022.
//

#include "HuffmanCode.h"

#include <iostream>


HuffmanCode::HuffmanCode(const FrequencyMap& fm) {

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
	this->print_tree();
}


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


void HuffmanCode::print_tree() const{
    this->print_no(this->prio_queue->top());
    std::cout << '\n';
}


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

void HuffmanCode::generate_codes(tree_node *node, const std::string& current_code) {
    node->codigo = current_code;
    if(node->left != nullptr) HuffmanCode::generate_codes(node->left, current_code + '0');
    if(node->right != nullptr) HuffmanCode::generate_codes(node->right, current_code + '1');
    if(node->is_folha) this->codes.emplace(std::pair<std::string, std::string>(node->value.first, node->codigo));
}

std::string HuffmanCode::get_code(const std::string& palavra) const {
    return this->codes.at(palavra);
}

std::unordered_map<std::string, std::string> HuffmanCode::get_code_map() const {
    return this->codes;
}

