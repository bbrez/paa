//
// Created by minorro on 3/15/22.
//

#include "BitReader.h"

BitReader::BitReader(std::ifstream &entrada): entrada(entrada){
    this->buffer = entrada.get();
    this->buffer_bits = 8;
}

unsigned char BitReader::read() {
    if(this->buffer_bits == 0){ //no caso de não haver bits a serem lidos, prepara um novo buffer;
        this->entrada.read(reinterpret_cast<char*>(&this->buffer), sizeof(unsigned char));
        if(this->entrada.good()) this->buffer_bits = 8;
        else return 0; //a função só deve retornar 0 ou 1 em casos normais, utilizamos 255 para erro
    }
    unsigned char retorno = 0x80; //liga apenas o bit mais significativo, permitindo a extração do primeiro bit do buffer.
    retorno = this->buffer & retorno; //extrai o bit desejado do buffer;
    this->buffer = this->buffer << 1; //move os bits para esquerda, preparando a proxima leitura
    this->buffer_bits--;
    retorno = retorno >> 7; //o valor retornado pode então set movido para o bit menos significativo para facilitar operações futuras.
    return retorno;
}

bool BitReader::has_next() const {
    return this->entrada.peek() != EOF || this->buffer_bits > 0;
}



