#include "FrequencyMap.h"

int main() {
    std::setlocale(LC_ALL, "pt_BR.UTF-8");

	FrequencyMap *fm = FrequencyMap::from_file("bible.txt", FrequencyMap::MODE::character);
    fm->print();

    delete fm;
    return 0;
}
