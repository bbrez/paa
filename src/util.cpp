//
// Created by bbrez on 2/15/2022.
//

#include "util.h"

#include <algorithm>
#include <sstream>


bool paa::is_printable(unsigned char c) {
	return c > 32;
}


bool paa::is_separator(unsigned char c){
    std::vector<char> separator_list = {' ', ',', '.', '?', '!', ';', '\n', '\t', '\r',
                                        ':', '(', ')', '[', ']', '{', '}', '\'', '\"'};

    auto compare = [c](char comp){
        return c == comp;
    };

    return std::ranges::any_of(separator_list.begin(), separator_list.end(), compare);

//    for(const auto &comp: separator_list){ //mais lento
//        if(comp == c) return true;
//    }
//    return false;
}

std::string paa::to_hex(unsigned char c) {
    std::stringstream buffer;
    buffer << "\\0x" << std::uppercase << std::hex << (int)c << std::dec;
    return buffer.str();
}

std::string paa::read_string(std::ifstream &file) {
    unsigned char tam;
    char *str;
    file.read(reinterpret_cast<char *>(&tam), sizeof(unsigned char)); //ler o tamanho da string
    str = new char[tam];
    file.read(str, tam);
    str[tam]='\0';

    std::string retorno(str);
    delete[] str;
    return retorno;
}

void paa::write_string(std::ofstream &file, const std::string& str) {
    unsigned char tam = str.length();
    file.write(reinterpret_cast<const char*>(&tam), sizeof(unsigned char));
    file.write(str.c_str(), tam);
}
