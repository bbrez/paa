//
// Created by minorro on 3/15/22.
//

#include "BitReader.h"

using namespace paa;

/**
 * @brief Constroi um novo objeto Bit Reader
 * 
 * @param entrada arquivo de entrada
 * @param last_bits quantidade significativa de bits do ultimo byte
 *
 * @pre o arquivo de entrada deve estar aberto na posição de leitura desejada e last_bits deve ser 0 <= valor >=  8
 * @post o objeto é criado, pronto para leitura do arquivo passado
 */
BitReader::BitReader(std::ifstream &entrada, unsigned char last_bits): last_bits(last_bits), entrada(entrada){
    this->buffer = entrada.get();
    this->buffer_bits = 8;
}

/**
 * @brief lê um apenas um bit do arquivo
 * 
 * @return unsigned char o bit lido do arquivo na posição menos significativa de um byte
 * 
 * @pre o arquivo a ser lido deve estar aberto e não deve ter acabado
 * @post o valor retornado sempre será 1 ou 0 e o arquivo pode possivelmente ter acabado e deve ser verificado com has_next()
 */
unsigned char BitReader::read() {
    if(this->buffer_bits == 0){ //no caso de não haver bits a serem lidos, prepara um novo buffer;
        this->entrada.read(reinterpret_cast<char*>(&this->buffer), sizeof(unsigned char));
        if(this->entrada.good()) this->buffer_bits = 8;
    }
    unsigned char retorno = 0x80; //liga apenas o bit mais significativo, permitindo a extração do primeiro bit do buffer.
    retorno = this->buffer & retorno; //extrai o bit desejado do buffer;
    this->buffer = this->buffer << 1; //move os bits para esquerda, preparando a proxima leitura
    this->buffer_bits--;
    retorno = retorno >> 7; //o valor retornado pode então set movido para o bit menos significativo para facilitar operações futuras.
    return retorno;
}

/**
 * @brief verifica se ainda existem bits a serem lidos
 * 
 * @return true existe um bit a ser lido no buffer ou no arquivo
 * @return false não existem mais bits a serem lidos tanto no buffer quanto no arquivo
 * 
 * @pre o  arquivo deve estar aberto
 * @post não são feitas modificações no estado do programa
 */
bool BitReader::has_next() const {
    if(this->entrada.peek() != EOF) return true;
    if(this->buffer > this-> last_bits) return true;
    return false;
}



