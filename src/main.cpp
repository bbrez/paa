#include <iostream>

#include "FrequencyMap.h"
#include "HuffmanCode.h"
#include "Compressor.h"
#include "Decompressor.h"

int main() {

    std::setlocale(LC_ALL, "pt_BR.UTF-8");

    std::ifstream entrada("pi.txt");
    std::ofstream saida("comp.dat", std::ios::binary);

    std::cout << "primeira leitura" << '\n';
	FrequencyMap fm(entrada, FileReader::MODE::character);
    fm.print();
    entrada.close();
    HuffmanCode hc(fm);
    hc.build_tree();
    Compressor c(hc);


    std::cout << "compressão" << '\n';
    entrada.open("pi.txt");
    c.compress(entrada, FileReader::MODE::character, saida);
    entrada.close();
    saida.close();

    std::cout << "descompressão" << '\n';
    entrada.open("comp.dat");
    saida.open("res.txt");
    Decompressor dc;
    dc.decompress(entrada, saida);
}
