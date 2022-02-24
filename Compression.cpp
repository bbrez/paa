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
        this->prio_queue->push(no_arv);
    }
}

void Compression::build_tree() {
    auto top_pop = [](auto queue) {
        auto node = queue->top();
        queue->pop();
        return node;
    };

    unsigned int tam_alf = this->prio_queue->size();
    for(unsigned int i = 0 ; i < tam_alf - 1 ; ++i){
        tree_node z;
        tree_node x = top_pop(this->prio_queue);
        tree_node y = top_pop(this->prio_queue);
        z.left = &x;
        z.right = &y;
        z.value.second = x.value.second + y.value.second;
        this->prio_queue->push(z);
    }
}
