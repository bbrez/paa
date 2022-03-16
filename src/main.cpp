#include <iostream>

#include "FrequencyMap.h"
#include "HuffmanCode.h"
#include "Compressor.h"

int main() {

    std::setlocale(LC_ALL, "pt_BR.UTF-8");

    std::ifstream entrada("test_file.txt");
    std::ofstream saida("comp.dat", std::ios::binary);

	FrequencyMap fm(entrada, FileReader::MODE::character);
    fm.print();
    entrada.close();
    HuffmanCode hc(fm);
    hc.build_tree();
    Compressor c(hc);


    entrada.open("test_file.txt");
    c.compress(entrada, FileReader::MODE::character, saida);
    entrada.close();
    saida.close();

}
