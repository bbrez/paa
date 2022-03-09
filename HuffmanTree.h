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
    ~HuffmanTree();

    void build_tree();
    void print_tree() const;

    void compress(const std::string& ifn, const std::string& ofn) const;
private:

    struct tree_node {
        bool is_folha;
        std::string codigo;
        std::pair<std::string, int> value;
        struct tree_node *left, *right;
    };
    constexpr static auto cmp = [](tree_node *left, tree_node *right){
        return left->value.second > right->value.second;
    };

    std::priority_queue<tree_node*, std::vector<tree_node*>, decltype(cmp)> *prio_queue;

    void print_no(const tree_node *no) const;
    void delete_no(tree_node *no);

    static void generate_codes(tree_node *node, const std::string& current_code);
};


#endif //PAA_HUFFMANTREE_H
