//
// Created by bbrez on 3/8/22.
//

#include "BitWriter.h"

using namespace paa;

/**
 * @brief Constroi um novo objeto Bit Writer
 * 
 * @param saida arquivo de saida
 * 
 * @pre o arqruivo de saida deve estar aberto na posição de escrita desejada
 * @post o objeto é criado, pronto para a escrita do arquivo passado
 */
BitWriter::BitWriter(std::ofstream &saida) : saida(saida) {
    this->buffer = 0;
    this->buffer_bits = 0;
}

BitWriter::~BitWriter() {
    this->close();
}

/**
 * @brief escreve apenas um bit no arquivo
 * 
 * @param bit o bit a ser escrito no arquivo, deve ser passado como um byte contendo apenas 1 ou 0
 * 
 * @pre o arquivo a ser escrito deve estar aberto
 * @post valores só são escritos no arquivo ao completar um byte, então a chamada de close() é importante ao terminar as escritas desejadas
 */
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

/**
 * @brief fecha o arquivo de escrita
 * 
 * @return unsigned char quantidade de bits escritos no último byte
 * 
 * @pre o arquivo a ser escrito deve estar aberto
 * @post o arquivo de entrada em si não é fechado, mas sim trata apropriadamente o fim da escrita de bits
 */
unsigned char BitWriter::close() {
    int last_bits = this->buffer_bits;
    while (this->buffer_bits != 0) {
        this->write(0);
    }
    return last_bits; //retorna quantos bits foram escritos no ultimo byte
}
