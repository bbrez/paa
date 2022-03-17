//
// Created by minorro on 3/14/22.
//

#include "FileReader.h"

using namespace paa;

FileReader::FileReader(std::ifstream &infile, MODE m) : m(m), infile(infile) {
    this->buffer.str("");
}

bool FileReader::eof() const {
    return this->infile.peek() == EOF;
}

std::string FileReader::get_next() {
    switch (this->m) { //utiliza o get apropriado para o modo de leitura
        case character:
            return this->get_char();
        case word:
            return this->get_word();
        default:
            return "";
    }
}

std::string FileReader::get_char() {
//    if(this->buffer.eof()){
//        this->buffer.clear();
//        char *rd_bf = new char[512];
//        this->infile.read(rd_bf, 512);
//        this->buffer.write(rd_bf, 512);
//    }
//
//    int c = this->buffer.get();
//    return {static_cast<char>(c)};
    unsigned char lido = this->infile.get();
    if(!this->infile.good()) return std::string("");
    return std::string(1, lido);
}

std::string FileReader::get_word() {
    buffer.str("");
    while(this->infile.peek() != EOF){
        unsigned char lido = this->infile.get();
        if(!this->infile.good()) break; //Se tiver erro ao ler o arquivo

        if(is_separator(lido)){ //se o caractere lido não for separador
            if(this->buffer.str().empty()){ //se o buffer estiver vazio, retorna o separador
                buffer << lido;
                break;
            } else { //se não, temos uma palavra que precisa ser retornada
                this->infile.unget(); //retorna o caractere ao buffer
                break; //para o loop
            }
        } else { //se for separador
            buffer << lido; //coloca no buffer
        }
    }

    return buffer.str(); //retorna o buffer formado;
}

