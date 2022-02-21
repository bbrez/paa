//
// Created by bbrez on 2/15/2022.
//

#include "FrequencyMap.h"

#include <iostream>
#include <fstream>
#include <functional>

#include "util.h"


FrequencyMap::FrequencyMap() {
	this->total = 0;
}

FrequencyMap::~FrequencyMap() = default;

void FrequencyMap::inc(const std::string& s) {
	if(this->count_map.contains(s)){
		this->count_map.insert_or_assign(s, this->count_map.at(s)+1);
	} else {
		this->count_map.emplace(s, 1);
	}
	this->total++;
}

void FrequencyMap::print() const {

    auto print_no = [](const auto &no){
        std::cout << "[";

        if(no.first.length() == 1) {
            if (!is_printable(no.first.c_str()[0])) {
                std::cout << "\\0x" << std::uppercase << std::hex << (int) no.first.c_str()[0] << std::dec;
            } else {
                std::cout << no.first;
            }
        } else {
            std::cout << no.first;
        }

        std::cout << "] = " << no.second << '\n';
    };

	for(const auto &no: this->count_map) { print_no(no); }
}


void FrequencyMap::parse_as_word(char *buffer) {

}


void FrequencyMap::parse_as_char(char *buffer, int bf_size) {
    for(int i = 0 ; i < bf_size ; ++i){
        this->inc(std::string(1, buffer[i]));
    }
}

FrequencyMap *FrequencyMap::from_file(const std::string &fn, MODE m) {
	auto *fm = new FrequencyMap();

    std::ifstream entrada(fn);
	if(!entrada.is_open()) std::cout << "Erro ao abrir arquivo" << std::endl;

	while(!entrada.eof()){
		char *buffer = new char[512];
		entrada.read(buffer, 512);


		if(m == FrequencyMap::MODE::character){
            fm->parse_as_char(buffer, entrada.gcount());
        } else if (m == FrequencyMap::MODE::word){
            fm->parse_as_word(buffer);
        }

		delete[] buffer;
	}

    return fm;
}
