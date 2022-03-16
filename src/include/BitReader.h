//
// Created by minorro on 3/15/22.
//

#ifndef PAA_BITREADER_H
#define PAA_BITREADER_H

#include <fstream>

class BitReader {
public:
    explicit BitReader(std::ifstream &entrada, unsigned char last_bits);
    ~BitReader() = default;

    unsigned char read();
    [[nodiscard]] bool has_next() const;
private:
    unsigned char buffer;
    unsigned char last_bits;
    int buffer_bits;
    std::ifstream &entrada;
};


#endif //PAA_BITREADER_H
