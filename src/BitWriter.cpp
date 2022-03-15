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
        this->saida << this->buffer;
        this->buffer = 0;
        this->buffer_bits = 0;
    }
}

unsigned char BitWriter::close() {
    int last_bits = this->buffer_bits;
    while (this->buffer_bits != 0) {
        this->write(0);
    }
    return last_bits; //retorna quantos bits foram escritos no ultimo byte
}
