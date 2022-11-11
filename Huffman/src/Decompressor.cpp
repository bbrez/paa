//
// Created by minorro on 3/15/22.
//

#include "Decompressor.h"
#include "util.h"
#include "BitReader.h"

using namespace paa;

/**
 * @brief faz a descompressão do arquivo
 * 
 * @param infile arquivo de entrada
 * @param outfile arquivo de saida
 * 
 * @pre ambos os arquivos abertos e em suas posições iniciais
 * @post arquivo de saida possui o texto descomprimido
 */
void Decompressor::decompress(std::ifstream &infile, std::ofstream &outfile) {
    pos_dados = 0;
    last_bits = 0;
    this->read_header(infile);
    this->read_data(infile, outfile);
}

/**
 * @brief faz a leitura do cabeçalho do arquivo
 * 
 * @param infile arquivo de entrada
 * 
 * @pre o arquivo deve estar aberto e em sua posição inicial
 * @post o cabeçalho é aberto e os valores necessários são armazenados em variáveis da classe, o arquivo aponta pra posição após o cabeçalho
 */
void Decompressor::read_header(std::ifstream &infile) {
    infile.read(reinterpret_cast<char *>(&this->pos_dados), sizeof(unsigned int));
    infile.read(reinterpret_cast<char *>(&this->last_bits), sizeof(unsigned char));
    while(infile.tellg() < pos_dados){
        auto palavra = read_string(infile);
        auto codigo = read_string(infile);
        this->code_map.emplace(std::pair<std::string, std::string>(codigo, palavra));
    }
}

/**
 * @brief faz a leitura dos dados do arquivo de entrada e escreve no arquivo de saida traduzidos
 * 
 * @param infile arquivo de entrada
 * @param outfile arquivo de saida
 * 
 * @pre os arquivos devem estar abertos, o arquivo de entrada apontando para os dados e o de saida em posição inicial, o hashmap de códigos deve estar preenchido
 * @post o arquivo de saida contem os dados descomprimidos
 */
void Decompressor::read_data(std::ifstream &infile, std::ofstream &outfile) {
    BitReader br(infile, this->last_bits);
    while (br.has_next()) {
        std::string codigo;
        while(!this->code_map.contains(codigo)){
            unsigned char lido = br.read();
            if(lido == 0) codigo.append("0");
            if(lido == 1) codigo.append("1");
        }
        outfile << this->code_map.at(codigo);
    }
}
