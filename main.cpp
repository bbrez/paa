#include <iostream>

#include "FrequencyMap.h"

int main() {
	FrequencyMap *fm = FrequencyMap::from_file("lorem.txt", FrequencyMap::MODE::character);
    fm->print();
    return 0;
}
