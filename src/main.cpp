#include <iostream>
#include "FrequencyMap.h"
#include "HuffmanCode.h"
#include "BitWriter.h"

int main() {

//    std::setlocale(LC_ALL, "pt_BR.UTF-8");
//
//	FrequencyMap fm("test_file.txt", FrequencyMap::MODE::word);
//    fm.print();
//    HuffmanCode ht(fm);
    //ht.compress("biblia.txt", "biblia.cmp");


    std::string dados("011000100110000101110100011000010111010001100001");

    std::ofstream saida("comp.dat", std::ios::binary);
    BitWriter bw(saida);

    for(const auto &c: dados){
        if(c == '0') bw.write(0);
        else if(c == '1') bw.write(1);
        else std::cout << "erro\n";
    }
    bw.close();
    saida.close();

    return 0;
}
