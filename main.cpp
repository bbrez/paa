#include "FrequencyMap.h"
#include "Compression.h"

#include <iostream>
#include <locale>

int main() {

    //std::cout << std::setlocale(LC_ALL, "pt_BR.UTF-8") << '\n';

	FrequencyMap *fm = FrequencyMap::from_file("biblia-em-txt.txt", FrequencyMap::MODE::character);
    Compression c(*fm);
    c.print();

    delete fm;
    return 0;
}
