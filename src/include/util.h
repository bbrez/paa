//
// Created by bbrez on 2/15/2022.
//

#ifndef PAA_UTIL_H
#define PAA_UTIL_H

#include <string>
#include <fstream>

bool is_printable(unsigned char c);
bool is_separator(unsigned char c);

std::string to_hex(unsigned char c);

std::string read_string(std::ifstream &file);
void write_string(std::ofstream &file, const std::string& str);

#endif //PAA_UTIL_H
