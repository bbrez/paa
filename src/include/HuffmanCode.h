//
// Created by bbrez on 2/23/2022.
//

#ifndef PAA_HUFFMANCODE_H
#define PAA_HUFFMANCODE_H

#include <string>
#include <queue>

#include "FrequencyMap.h"

namespace paa {
    class HuffmanCode {
    public:
        explicit HuffmanCode(const paa::FrequencyMap &fm);

        ~HuffmanCode();

        void build_tree();

        void print_tree() const;

        std::string get_code(const std::string &palavra) const;

        std::unordered_map<std::string, std::string> get_code_map() const;

    private:

        struct tree_node {
            bool is_folha;
            std::string codigo;
            std::pair<std::string, int> value;
            struct tree_node *left, *right;
        };

        constexpr static auto cmp = [](tree_node *left, tree_node *right) {
            return left->value.second > right->value.second;
        };

        std::priority_queue<HuffmanCode::tree_node *, std::vector<HuffmanCode::tree_node *>, decltype(HuffmanCode::cmp)> *prio_queue;

        std::unordered_map<std::string, std::string> codes;

        void print_no(const tree_node *no) const;

        void delete_no(tree_node *no);

        void generate_codes(tree_node *node, const std::string &current_code);
    };
};

#endif //PAA_HUFFMANCODE_H
