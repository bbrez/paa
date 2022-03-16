//
// Created by minorro on 3/15/22.
//

#ifndef PAA_DECOMPRESSOR_H
#define PAA_DECOMPRESSOR_H

#include <unordered_map>
#include <string>
#include <fstream>

class Decompressor {
public:
    Decompressor() = default;
    void decompress(std::ifstream &infile, std::ofstream &outfile);
private:
    std::unordered_map<std::string, std::string> code_map;

    void read_header(std::ifstream &infile);
    void read_data(std::ifstream &infile, std::ofstream &outfile);
};


#endif //PAA_DECOMPRESSOR_H
