//
// Created by bbrez on 2/23/2022.
//

#ifndef PAA_COMPRESSION_H
#define PAA_COMPRESSION_H

#include <string>
#include <queue>

#include "FrequencyMap.h"

class Compression {
public:
    explicit Compression(const FrequencyMap& fm);
    ~Compression() = default;

    void build_tree();
    void print_tree() const;

private:
    struct tree_node {
        bool is_folha;
        std::pair<std::string, int> value;
        struct tree_node *left, *right;
    };

    constexpr static auto cmp = [](const tree_node& left, const tree_node& right){
        return left.value.second > right.value.second;
    };

    std::priority_queue<tree_node, std::vector<tree_node>, decltype(cmp)> *prio_queue;

    void print_no(const tree_node& no) const;
};


#endif //PAA_COMPRESSION_H
