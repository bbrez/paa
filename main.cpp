#include "FrequencyMap.h"
#include "HuffmanTree.h"

#include <iostream>

int main() {

    //std::setlocale(LC_ALL, "pt_BR.UTF-8");

	FrequencyMap *fm = FrequencyMap::from_file("pi.txt", FrequencyMap::MODE::character);
    fm->print();
    HuffmanTree ht(*fm);
    delete fm;
    ht.build_tree();
    ht.print_tree();
    ht.compress("pi.txt", "pi.cmp");
    return 0;
}
