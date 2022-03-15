//
// Created by minorro on 3/15/22.
//

#ifndef PAA_BITREADER_H
#define PAA_BITREADER_H

#include <fstream>

class BitReader {
public:
    explicit BitReader(std::ifstream &entrada);
    ~BitReader() = default;

    unsigned char read();
    bool has_next();
private:
    unsigned char buffer;
    int buffer_bits;
    std::ifstream &entrada;
};


#endif //PAA_BITREADER_H
