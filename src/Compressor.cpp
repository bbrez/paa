//
// Created by minorro on 3/14/22.
//

#include <iostream>
#include "Compressor.h"
#include "BitWriter.h"

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

/**
 *
 * @param outfile
 */
void Compressor::write_header(std::ofstream &outfile) {
    long offset_dados = 0;
    unsigned char last_bits = 0;
    outfile.write(reinterpret_cast<const char*>(&offset_dados), sizeof(long)); //guarda um espaço de 8 bytes para escrever onde começam os dados
    outfile.write(reinterpret_cast<const char*>(&last_bits), sizeof(unsigned char)); //guarda um espaço de 1 byte para guardar quantos bits do ultimo byte são relevantes
    for(const auto &par: hc.get_code_map()){
        unsigned char tam_palavra = par.first.length(), tam_codigo = par.second.length();
        outfile.write(reinterpret_cast<const char*>(&tam_palavra), sizeof(unsigned char));
        outfile << par.first;
        outfile.write(reinterpret_cast<const char*>(&tam_codigo), sizeof(unsigned char));
        outfile << par.second;
    }
    offset_dados = outfile.tellp();
    outfile.seekp(0);
    outfile.write(reinterpret_cast<const char*>(&offset_dados), sizeof(long));
    outfile.seekp(offset_dados);
}

/**
 *
 * @param infile
 * @param m
 * @param outfile
 */
void Compressor::write_data(std::ifstream &infile, FileReader::MODE m, std::ofstream &outfile) {
    BitWriter bw(outfile);
    FileReader fr(infile, m);
    infile.seekg(0);
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
    std::cout << "escrito " << bits/8 << " bytes\n";
    unsigned char last_bytes = bw.close();
    outfile.seekp(sizeof(long));
    outfile.write(reinterpret_cast<const char*>(&last_bytes), sizeof(unsigned char));
}

void Compressor::read_header(std::ifstream &infile) {
    long pos_dados;
    unsigned char last_bits;
    infile.read(reinterpret_cast<char *>(&pos_dados), sizeof(long));
    infile.read(reinterpret_cast<char *>(&last_bits), sizeof(unsigned char));
    while(infile.tellg() < pos_dados){
        unsigned char tam_palavra, tam_codigo;
        char *rd_palavra, *rd_codigo;

        infile.read(reinterpret_cast<char *>(&tam_palavra), sizeof(unsigned char));
        rd_palavra = new char[tam_palavra];
        infile.read(rd_palavra, tam_palavra);
        rd_palavra[tam_palavra]=0;

        infile.read(reinterpret_cast<char *>(&tam_codigo), sizeof(unsigned char));
        rd_codigo = new char[tam_codigo];
        infile.read(rd_codigo, tam_codigo);
        rd_codigo[tam_codigo]=0;

        this->codemap.emplace(std::pair<std::string, std::string>(rd_codigo, rd_palavra));
    }
}

void Compressor::decompress(std::ifstream &infile, std::ofstream &outfile) {
    this->read_header(infile);
}
