//
// Created by bbrez on 2/15/2022.
//

#ifndef PAA_FREQUENCYMAP_H
#define PAA_FREQUENCYMAP_H

#include <string>
#include <map>

class FrequencyMap {
private:
	std::map<char, int> count_map;
	int total;

public:
	FrequencyMap();
	~FrequencyMap();

	void inc(char c);
	void print() const;
};

void FrequencyMap_from_file(std::string fn);

#endif //PAA_FREQUENCYMAP_H
