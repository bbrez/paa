//
// Created by bbrez on 2/15/2022.
//

#include "util.h"

#include <algorithm>

bool is_printable(char c) {
	return c > 32;
}


bool is_separator(char c){
    std::vector<char> separator_list = {' ', ',', '.', '?', '!', ';', '\n', '\t', '\r', ':', '(', ')', '[', ']'};

    auto compare = [c](char comp){
        return c == comp;
    };

    return std::ranges::any_of(separator_list.begin(), separator_list.end(), compare);

//    for(const auto &comp: separator_list){
//        if(comp == c) return true;
//    }
//    return false;
}
