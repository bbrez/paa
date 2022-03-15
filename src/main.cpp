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

    std::ifstream entrada("test_file.txt");
    std::ofstream saida("comp.dat", std::ios::binary);

	FrequencyMap fm(entrada, FileReader::MODE::word);
    fm.print();
    entrada.close();
    HuffmanCode hc(fm);
    hc.build_tree();
    Compressor c(hc);


    entrada.open("test_file.txt");
    c.compress(entrada, FileReader::MODE::word, saida);
    entrada.close();
    saida.close();

    entrada.open("comp.dat", std::ios::binary);
    saida.open("saida.txt");
    c.decompress(entrada, saida);
    return 0;
}
