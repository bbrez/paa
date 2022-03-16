//
// Created by minorro on 3/14/22.
//

#include <iostream>

#include "Compressor.h"
#include "BitWriter.h"
#include "util.h"

Compressor::Compressor(const HuffmanCode& hc) : hc(hc) {}

/**
 * @pre infile aberto como arquivo texto e pronto para leitura
 * @pre outfile aberto como arquivo binario e pronto para escrita
 * @param infile
 * @param m
 * @param outfile
 * @post os arquivos utilizados devem ser fechados
 */
void Compressor::compress(std::ifstream &infile, FileReader::MODE m, std::ofstream &outfile) {
    write_header(outfile);
    write_data(infile, m, outfile);
}


void Compressor::write_header(std::ofstream &outfile) {
    unsigned int offset_dados = 0;
    unsigned char last_bits = 0;

    //ofstream.write(), combinado com o reinterpret_cast para char* funciona como o fwrite de C, escrevendo a representação binária da variavel passada no arquivo
    outfile.write(reinterpret_cast<const char*>(&offset_dados), sizeof(unsigned int)); //guarda um espaço de 8 bytes para escrever onde começam os dados
    outfile.write(reinterpret_cast<const char*>(&last_bits), sizeof(unsigned char)); //guarda um espaço de 1 byte para guardar quantos bits do ultimo byte são relevantes

    for(const auto &par: hc.get_code_map()){
        write_string(outfile, par.first);
        write_string(outfile, par.second);
  }

    offset_dados = outfile.tellp();
    outfile.seekp(0);
    outfile.write(reinterpret_cast<const char*>(&offset_dados), sizeof(unsigned int));
    outfile.seekp(offset_dados);
}


void Compressor::write_data(std::ifstream &infile, FileReader::MODE m, std::ofstream &outfile) {
    BitWriter bw(outfile);
    FileReader fr(infile, m);

    int bits = 0;

    while(!fr.eof()){
        std::string palavra = fr.get_next();
        if(palavra.length() == 0) continue;
        for(const auto &c: hc.get_code(palavra)){
            ++bits;
            if(c == '0') bw.write(0);
            if(c == '1') bw.write(1);
        }
    }

    std::cout << "escrito " << bits/8 << " bytes e " << bits%8 << " bits\n";
    unsigned char last_bytes = bw.close();
    outfile.seekp(sizeof(unsigned int));
    outfile.write(reinterpret_cast<const char*>(&last_bytes), sizeof(unsigned char));
}
