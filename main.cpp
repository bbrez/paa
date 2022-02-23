#include "FrequencyMap.h"

int main() {
    std::setlocale(LC_ALL, "pt_BR.UTF-8");

	FrequencyMap *fm = FrequencyMap::from_file("biblia-em-txt.txt", FrequencyMap::MODE::word);
    fm->print();
    return 0;
}
