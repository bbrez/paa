//
// Created by bbrez on 2/15/2022.
//

#include "FrequencyMap.h"

#include <iostream>
#include <vector>
#include "util.h"


FrequencyMap::FrequencyMap(std::ifstream &infile, FileReader::MODE m) {
	this->total = 0;

    FileReader fr(infile, m);
    while(!fr.eof()){
        std::string palavra = fr.get_next();
        if(palavra.length() == 0) continue;
        this->inc(palavra);
    }
}


/**
 * @brief
 *
 * @param s
 */
void FrequencyMap::inc(const std::string& s) {
	if(this->count_map.contains(s)){
		this->count_map.insert_or_assign(s, this->count_map.at(s)+1);
	} else {
		this->count_map.emplace(s, 1);
	}
	this->total++;
}

/**
 * @brief
 *
 */
void FrequencyMap::print() const {

    auto print_no = [](const auto &no){
        std::cout << "[";

        if(no.first.length() == 1) {
            if (!is_printable(no.first.c_str()[0])) {
                std::cout << to_hex(no.first.c_str()[0]);
            } else {
                std::cout << no.first;
            }
        } else {
            std::cout << no.first;
        }

        std::cout << "] = " << no.second << '\n';
    };

    std::vector<std::pair<std::string, int>> node_vector(this->count_map.begin(), this->count_map.end());
    std::sort(node_vector.begin(), node_vector.end());
    for(const auto &no: node_vector) { print_no(no); }
    std::cout << "Total = " << this->total << '\n';
}


const std::unordered_map<std::string, int> &FrequencyMap::get_map() const {
    return this->count_map;
}


int FrequencyMap::get_total() const {
	return this->total;
}
