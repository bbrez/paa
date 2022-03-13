//
// Created by bbrez on 2/15/2022.
//

#include "FrequencyMap.h"

#include <iostream>
#include <fstream>
#include <regex>

#include <map>

#include "util.h"


FrequencyMap::FrequencyMap(const std::string &fn, FrequencyMap::MODE m) {
	this->total = 0;

	std::ifstream entrada(fn);
	if(!entrada.is_open()){
		std::cout << "Erro ao abrir arquivo: [" << fn << "]\n";
		std::abort();
	}

	switch (m) {
		case word:
			this->parse_as_word(entrada);
			break;
		case character:
			this->parse_as_char(entrada);
			break;
		default:
			std::cout << "Modo de operação invalido\n";
			std::abort();
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
 * @param c
 */
void FrequencyMap::inc(const unsigned char c){
    this->inc(std::string(1, c));
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

/**
 * @brief
 *
 * @param entrada
 */
void FrequencyMap::parse_as_word(std::ifstream &entrada) {

    std::stringstream buffer("");
    while(!entrada.eof()) {
        unsigned char lido = entrada.get();
        if(!entrada.good()) break;

        if(!is_separator(lido)){
            buffer << lido;
        } else {
            if(buffer.str().length() != 0){
                this->inc(buffer.str());
                buffer.str(""); //limpa a string
            }
            this->inc(lido); //cria uma string de um caractere
        }
    }

    if(buffer.str().length() != 0){
        this->inc(buffer.str());
    }

}

/**
 * @brief
 *
 * @param entrada
 */
void FrequencyMap::parse_as_char(std::ifstream &entrada) {
    const int bf_size = 512;

    std::string buffer;
    buffer.resize(bf_size);
    while(!entrada.eof()) {
        //char *buffer = new char[bf_size];
        entrada >> buffer;

        for(const auto &c: buffer){
            this->inc(c);
        }

        buffer.clear();
    }
}


const std::unordered_map<std::string, int> &FrequencyMap::get_map() const {
    return this->count_map;
}

int FrequencyMap::get_total() const {
	return this->total;
}
