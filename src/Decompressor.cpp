//
// Created by minorro on 3/15/22.
//

#include "Decompressor.h"
#include "util.h"

void Decompressor::decompress(std::ifstream &infile, std::ofstream &outfile) {
    this->read_header(infile);
    this->read_data(infile, outfile);
}

void Decompressor::read_header(std::ifstream &infile) {
    long pos_dados;
    unsigned char last_bits;
    infile.read(reinterpret_cast<char *>(&pos_dados), sizeof(long));
    infile.read(reinterpret_cast<char *>(&last_bits), sizeof(unsigned char));
    while(infile.tellg() < pos_dados){
        auto palavra = read_string(infile);
        auto codigo = read_string(infile);
        this->code_map.emplace(std::pair<std::string, std::string>(codigo, palavra));
    }
}

void Decompressor::read_data(std::ifstream &infile, std::ofstream &outfile) {

}
