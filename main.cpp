#include "FrequencyMap.h"
#include "Compression.h"

#include <iostream>

int main() {

    std::setlocale(LC_ALL, "pt_BR.UTF-8");

	FrequencyMap *fm = FrequencyMap::from_file("lorem.txt", FrequencyMap::MODE::word);
    fm->print();
    Compression c(*fm);
    delete fm;
    c.build_tree();
    c.print_tree();

    return 0;
}
