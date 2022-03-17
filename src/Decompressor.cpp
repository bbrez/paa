//
// Created by minorro on 3/15/22.
//

#include "Decompressor.h"
#include "util.h"
#include "BitReader.h"


void Decompressor::decompress(std::ifstream &infile, std::ofstream &outfile) {
    pos_dados = 0;
    last_bits = 0;
    this->read_header(infile);
    this->read_data(infile, outfile);
}


void Decompressor::read_header(std::ifstream &infile) {
    infile.read(reinterpret_cast<char *>(&this->pos_dados), sizeof(unsigned int));
    infile.read(reinterpret_cast<char *>(&this->last_bits), sizeof(unsigned char));
    while(infile.tellg() < pos_dados){
        auto palavra = read_string(infile);
        auto codigo = read_string(infile);
        this->code_map.emplace(std::pair<std::string, std::string>(codigo, palavra));
    }
}


void Decompressor::read_data(std::ifstream &infile, std::ofstream &outfile) {
    BitReader br(infile, this->last_bits);
    while (br.has_next()) {
        std::string codigo;
        while(!this->code_map.contains(codigo)){
            unsigned char lido = br.read();
            if(lido == 0) codigo.append("0");
            if(lido == 1) codigo.append("1");
        }
        outfile << this->code_map.at(codigo);
    }
}
