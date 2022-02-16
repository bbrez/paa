//
// Created by bbrez on 2/15/2022.
//

#include "FrequencyMap.h"

#include <iostream>
#include <fstream>

#include "util.h"


FrequencyMap::FrequencyMap() {
	this->total = 0;
}

FrequencyMap::~FrequencyMap() = default;

void FrequencyMap::inc(char c) {
	if(this->count_map.contains(c)){
		this->count_map.insert_or_assign(c, this->count_map.at(c)+1);
	} else {
		this->count_map.emplace(c, 1);
	}
	this->total++;
}

void FrequencyMap::print() const {

	auto print_no = [](const auto &no){
		std::cout << "[";
		if(is_printable(no.first))
			std::cout << no.first;
		else
			std::cout << "\\0x" << std::uppercase << std::hex << (int)no.first << std::dec;
		std::cout << "] = " << no.second << '\n';
	};

	for(const auto &no: this->count_map) { print_no(no); }
}

void FrequencyMap_from_file(std::string fn) {
	auto *fm = new FrequencyMap();

    std::ifstream entrada(fn);
	if(!entrada.is_open()) std::cout << "Erro ao abrir arquivo" << std::endl;

	while(!entrada.eof()){
		char *buffer = new char[512];
		entrada.read(buffer, 512);

		for(int i = 0; i < entrada.gcount() ; ++i){
			fm->inc(buffer[i]);
		}

		delete[] buffer;
	}

	fm->print();
}
