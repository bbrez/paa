//
// Created by bbrez on 2/15/2022.
//

#include "FrequencyMap.h"

#include <iostream>
#include <fstream>
#include <regex>

#include <map>

#include "util.h"


FrequencyMap::FrequencyMap() {
	this->total = 0;
}


FrequencyMap::~FrequencyMap() = default;

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
void FrequencyMap::inc(const char c){
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
                std::cout << "\\0x" << std::uppercase << std::hex << (int) no.first.c_str()[0] << std::dec;
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
}

/**
 * @brief 
 * 
 * @param entrada 
 */
void FrequencyMap::parse_as_word(std::ifstream &entrada) {

    std::stringstream buffer("");
    while(!entrada.eof()) {
        char lido = entrada.get();

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

}

/**
 * @brief 
 * 
 * @param entrada 
 */
void FrequencyMap::parse_as_char(std::ifstream &entrada) {
    const int bf_size = 512;

    while(!entrada.eof()) {
        char *buffer = new char[bf_size];
        entrada.read(buffer, bf_size);

        for(const auto &c: std::string(buffer)){
            this->inc(c);
        }

        delete[] buffer;
    }
}

/**
 * @brief 
 * 
 * @param fn nome do arquivo
 * @param m modo de interpretação do arquivo
 * @return FrequencyMap* 
 */
FrequencyMap *FrequencyMap::from_file(const std::string &fn, MODE m) {
    auto *fm = new FrequencyMap();

    std::ifstream entrada(fn);
    if(!entrada.is_open()){
        std::cout << "Erro ao abrir arquivo: [" << fn << "]\n";
        std::abort();
    }

    switch (m) {
        case word:
            fm->parse_as_word(entrada);
            break;
        case character:
            fm->parse_as_char(entrada);
            break;
        default:
            std::cout << "Modo de operação invalido\n";
            std::abort();
    }

    return fm;
}