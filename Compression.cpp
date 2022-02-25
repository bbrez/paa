//
// Created by bbrez on 2/23/2022.
//

#include "Compression.h"

#include <iostream>

#include "util.h"

Compression::Compression(const FrequencyMap& fm) {

    this->prio_queue = new std::priority_queue<tree_node, std::vector<tree_node>, decltype(cmp)>(cmp);
    for (const auto &no: fm.get_map()) {
        tree_node no_arv;
        no_arv.value = no;
        no_arv.is_folha = true;
        no_arv.left = nullptr;
        no_arv.right = nullptr;
        this->prio_queue->push(no_arv);
    }
}

void Compression::print_no(const Compression::tree_node& no) const{
    if(no.is_folha){
        std::cout << "[(" << no.value.second << ", " << no.value.first << "), *, *]";
    } else {
        std::cout << "[" << no.value.second;
        if(no.left != nullptr) print_no(*no.left);
        else std::cout << ", *";
        if(no.right != nullptr) print_no(*no.right);
        else std::cout << ", *";
        std::cout << "]";
    }
}

void Compression::print_tree() const{
    this->print_no(this->prio_queue->top());
}

void Compression::build_tree() {
    auto top_pop = [](auto queue) {
        auto node = queue->top();
        queue->pop();
        return node;
    };

    unsigned int tam_alf = this->prio_queue->size();
    while(this->prio_queue->size()!= 1){
        tree_node z;
        tree_node x = top_pop(this->prio_queue);
        tree_node y = top_pop(this->prio_queue);
        z.is_folha = false;
        z.left = &x;
        z.right = &y;
        z.value.first = "";
        z.value.second = x.value.second + y.value.second;
        this->prio_queue->push(z);
    }
}
