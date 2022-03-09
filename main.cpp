#include <fstream>
#include <iostream>
#include "FrequencyMap.h"
#include "HuffmanTree.h"
#include "BitWriter.h"

int main() {

    std::setlocale(LC_ALL, "pt_BR.UTF-8");

	FrequencyMap *fm = FrequencyMap::from_file("testfile.txt", FrequencyMap::MODE::word );
    fm->print();
    HuffmanTree ht(*fm);
    delete fm;
    ht.build_tree();
    ht.print_tree();
    //ht.compress("biblia.txt", "biblia.cmp");

//    std::string dados("10101011");
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
