//
// Created by bbrez on 2/15/2022.
//

#include "util.h"

#include <algorithm>
#include <sstream>

bool is_printable(unsigned char c) {
	return c > 32;
}


bool is_separator(unsigned char c){
    std::vector<char> separator_list = {' ', ',', '.', '?', '!', ';', '\n', '\t', '\r',
                                        ':', '(', ')', '[', ']', '{', '}', '\'', '\"'};

    auto compare = [c](char comp){
        return c == comp;
    };

    return std::ranges::any_of(separator_list.begin(), separator_list.end(), compare);

//    for(const auto &comp: separator_list){
//        if(comp == c) return true;
//    }
//    return false;
}

std::string to_hex(unsigned char c) {
    std::stringstream buffer;
    buffer << "\\0x" << std::uppercase << std::hex << (int)c << std::dec;
    return buffer.str();
}
