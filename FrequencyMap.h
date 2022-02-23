//
// Created by bbrez on 2/15/2022.
//

#ifndef PAA_FREQUENCYMAP_H
#define PAA_FREQUENCYMAP_H

#include <string>
#include <map>

class FrequencyMap {
public:
    typedef enum MODE {
        character,
        word
    } MODE;

	explicit FrequencyMap();
	~FrequencyMap();

	void inc(const std::string& s);
    void inc(char c);
	void print() const;

    static FrequencyMap* from_file(const std::string &fn, MODE m);

private:

    std::map<std::string, int> count_map;
    int total;

    void parse_as_word(std::ifstream &entrada);
    void parse_as_char(std::ifstream &entrada);
};

#endif //PAA_FREQUENCYMAP_H
