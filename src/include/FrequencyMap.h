//
// Created by bbrez on 2/15/2022.
//

#ifndef PAA_FREQUENCYMAP_H
#define PAA_FREQUENCYMAP_H

#include <string>
#include <unordered_map>

#include "FileReader.h"

namespace paa {
    class FrequencyMap {
    public:

        FrequencyMap() = delete;

        explicit FrequencyMap(std::ifstream &infile, FileReader::MODE m);

        ~FrequencyMap() = default;

        void inc(const std::string &s);

        void print() const;

        const std::unordered_map<std::string, int> &get_map() const;

    private:

        std::unordered_map<std::string, int> count_map;
        int total;

    };
};
#endif //PAA_FREQUENCYMAP_H
