#include <iostream>
#include "FrequencyMap.h"
#include "HuffmanCode.h"
#include "BitWriter.h"
#include "Compressor.h"

int main() {

    std::setlocale(LC_ALL, "pt_BR.UTF-8");

//    if(!entrada.is_open()){
//        std::cout << "Erro ao abrir arquivo: [" << "test_file.txt" << "]\n";
//        std::abort();
//    }

    std::ifstream entrada("pi.txt");
    std::ofstream saida("comp.dat", std::ios::binary);

	FrequencyMap fm(entrada, FileReader::MODE::character);
    fm.print();
    entrada.close();
    HuffmanCode hc(fm);
    hc.build_tree();
    Compressor c(hc);


    entrada.open("pi.txt");
    c.compress(entrada, FileReader::MODE::character, saida);
    entrada.close();
    saida.close();


//    std::string dados("011000100110000101110100011000010111010001100001");
//
//    std::ofstream saida("comp.dat", std::ios::binary);
//    BitWriter bw(saida);
//
//    for(const auto &c: dados){
//        if(c == '0') bw.write(0);
//        else if(c == '1') bw.write(1);
//        else std::cout << "erro\n";
//    }
//    bw.close();
//    saida.close();


    return 0;
}
