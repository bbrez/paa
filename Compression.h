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

private:
    struct tree_node {
        std::pair<std::string, int> value;
        struct tree_node *left = nullptr, *right = nullptr;
    };

    constexpr static auto cmp = [](const tree_node& left, const tree_node& right){
        return left.value.second > right.value.second;
    };

    std::priority_queue<tree_node, std::vector<tree_node>, decltype(cmp)> *prio_queue;
};


#endif //PAA_COMPRESSION_H
