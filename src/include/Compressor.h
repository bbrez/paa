//
// Created by minorro on 3/14/22.
//

#ifndef PAA_COMPRESSOR_H
#define PAA_COMPRESSOR_H


#include "HuffmanCode.h"

class Compressor {
public:
    explicit Compressor(const HuffmanCode& hc);

    void compress(std::ifstream infile, std::ofstream outfile);
private:

    HuffmanCode hc;
};


#endif //PAA_COMPRESSOR_H
