//
// Created by bbrez on 2/23/2022.
//

#ifndef PAA_HUFFMANTREE_H
#define PAA_HUFFMANTREE_H

#include <string>
#include <queue>

#include "FrequencyMap.h"

class HuffmanTree {
public:
    explicit HuffmanTree(const FrequencyMap& fm);
    explicit HuffmanTree(const std::string fn);
    ~HuffmanTree();

    void build_tree();
    void print_tree() const;

    void compress(std::string ifn, std::string ofn) const;

private:
    struct tree_node {
        bool is_folha;
        std::pair<std::string, int> value;
        struct tree_node *left, *right;
    };

    constexpr static auto cmp = [](tree_node *left, tree_node *right){
        return left->value.second > right->value.second;
    };

    std::priority_queue<tree_node*, std::vector<tree_node*>, decltype(cmp)> *prio_queue;

    void print_no(const tree_node *no) const;
    void delete_no(tree_node *no);
};


#endif //PAA_HUFFMANTREE_H
