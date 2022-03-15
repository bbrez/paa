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
    outfile.write(reinterpret_cast<const char*>(&offset_dados), sizeof(long)); //guarda um espaço para escrever onde começam os dados;
    for(const auto &par: hc.get_code_map()){
        outfile << par.first.length();
        outfile << par.first;
        outfile << par.second.length();
        outfile << par.second;
    }
    offset_dados = outfile.tellp();
    outfile.seekp(0);
    outfile << offset_dados;
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
    bw.close();
}

void Compressor::decompress(std::ifstream &infile, std::ofstream &outfile) {

}
