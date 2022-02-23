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
    Compression() = default;
    explicit Compression(FrequencyMap fm);
    ~Compression() = default;

    void print();
private:
    std::priority_queue<std::pair<std::string, int>> prio_queue;
};


#endif //PAA_COMPRESSION_H
