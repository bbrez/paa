//
// Created by minorro on 3/14/22.
//

#include <sstream>
#include "FileReader.h"
#include "util.h"

FileReader::FileReader(std::ifstream &infile, MODE m) : m(m), infile(infile) {}

std::string FileReader::get_next() {
    switch (this->m) {
        case character:
            return this->get_char();
            break;
        case word:
            return this->get_word();
            break;
    }
}

std::string FileReader::get_char() {
    return std::string();
}

std::string FileReader::get_word() {
    std::stringstream buffer("");
    while(!this->infile.eof()){
        unsigned char lido = this->infile.get();
        if(!this->infile.good()) break; //Se tiver erro ao ler o arquivo

        if(!is_separator(lido)){ //se o caractere lido não for separador
            buffer << lido; //coloca no buffer
        } else { //se for separador
            this->infile.unget(); //retorna o caractere ao buffer
            break; //para o loop
        }
    }

    return buffer.str(); //retorna o buffer formado;
}

