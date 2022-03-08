#include "FrequencyMap.h"
#include "HuffmanTree.h"

int main() {

    std::setlocale(LC_ALL, "pt_BR.UTF-8");

	FrequencyMap *fm = FrequencyMap::from_file("big-pi.txt", FrequencyMap::MODE::character);
    fm->print();
    HuffmanTree ht(*fm);
    delete fm;
    ht.build_tree();
    ht.print_tree();
    //ht.compress("biblia.txt", "biblia.cmp");
    return 0;
}
