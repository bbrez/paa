#include "FrequencyMap.h"

int main() {
	FrequencyMap *fm = FrequencyMap::from_file("bible.txt", FrequencyMap::MODE::character);
    fm->print();
    return 0;
}
