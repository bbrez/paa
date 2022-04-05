//
// Created by minorro on 3/14/22.
//

#include <iostream>

#include "Compressor.h"
#include "BitWriter.h"
#include "util.h"

using namespace paa;

/**
 * @brief Constroi um novo objeto Compressor
 * 
 * @param hc Objeto HuffmanCode com o código de cada letra ou palavra que será utilizado na compressão
 * 
 * @pre o objeto HuffmanCode deve possuir um código bem formado
 * @post o objeto é criado, pronto para compressão de um arquivo
 */
Compressor::Compressor(const HuffmanCode& hc) : hc(hc) {}

/**
 * @brief faz a compressão do arquivo
 * 
 * @param infile arquivo de onde é lido os dados a serem comprimidos
 * @param m o modo em que o arquivo está sendo comprimido
 * @param outfile arquivo onde será escrito os dados comprimidos
 * 
 * @pre os arquivos devem estar abertos e em seu inicio, o modo de leitura deve ser um valor adequado
 */
void Compressor::compress(std::ifstream &infile, FileReader::MODE m, std::ofstream &outfile) {
    write_header(outfile);
    write_data(infile, m, outfile);
}

/**
 * @brief escreve o cabeçalho do arquivo comprimido
 * 
 * @param outfile arquivo em que será escrito o cabeçalho
 * 
 * @pre o arquivo a ser escrito está aberto e em seu inicio, o código de huffman está preenchido
 * @post o arquivo de saida possui o cabeçalho escrito e aponta para a posição seguindo ele
 */
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

/**
 * @brief escreve os dados do arquivo comprimido
 * 
 * @param infile arquivo em que serão lidas as palavras
 * @param m modo em que serão lidas as palavras
 * @param outfile arquivo em que serão escritos os dados
 * 
 * @pre ambos arquivos abertos, arquivo de entrada no inicio, arquivo de saida posicionado após o cabeçalho, modo de leitura valido
 * @post o arquivo de saida tem os dados escritos e pode ser fechado
 */
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

    //std::cout << "escrito " << bits/8 << " bytes e " << bits%8 << " bits\n";
    unsigned char last_bytes = bw.close();
    outfile.seekp(sizeof(unsigned int));
    outfile.write(reinterpret_cast<const char*>(&last_bytes), sizeof(unsigned char));
}
