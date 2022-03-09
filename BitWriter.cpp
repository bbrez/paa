//
// Created by bbrez on 3/8/22.
//

#include "BitWriter.h"

BitWriter::BitWriter(std::ofstream &saida) : saida(saida) {
    this->buffer = 0;
    this->buffer_bits = 0;
}

BitWriter::~BitWriter() {
    this->close();
}

void BitWriter::write(unsigned char bit) {
    this->buffer = this->buffer << 1;
    this->buffer = this->buffer | bit;
    this->buffer_bits++;

    if(this->buffer_bits == 8){
        saida << this->buffer;
        this->buffer = 0;
        this->buffer_bits = 0;
    }
}

void BitWriter::close() {
    while (this->buffer_bits != 0) {
        this->write(0);
    }
}
