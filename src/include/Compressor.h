//
// Created by minorro on 3/14/22.
//

#ifndef PAA_COMPRESSOR_H
#define PAA_COMPRESSOR_H


#include "HuffmanCode.h"

class Compressor {
public:
    explicit Compressor(const HuffmanCode& hc);

    void compress(std::ifstream &infile, FileReader::MODE m, std::ofstream &outfile);
    void decompress(std::ifstream &infile, std::ofstream &outfile);
private:

    HuffmanCode hc;
    std::unordered_map<std::string, std::string> codemap;

    void write_header(std::ofstream& outfile);
    void write_data(std::ifstream &infile, FileReader::MODE m, std::ofstream &outfile);

    void read_header(std::ifstream &infile);
};


#endif //PAA_COMPRESSOR_H
