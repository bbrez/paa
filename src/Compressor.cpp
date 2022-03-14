//
// Created by minorro on 3/14/22.
//

#include <fstream>
#include "Compressor.h"
#include "BitWriter.h"

Compressor::Compressor(const HuffmanCode& hc) : hc(hc) {}

void Compressor::compress(std::ifstream infile, std::ofstream outfile) {
    BitWriter bw(outfile);
    while(!infile.eof()){
        std::string palavra;
        infile >> palavra;
        std::string codigo = this->hc.get_code(palavra);
        for(const auto &bit: codigo){
            bw.write(bit);
        }
    }
}


