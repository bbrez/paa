//
// Created by bbrez on 2/15/2022.
//

#ifndef PAA_FREQUENCYMAP_H
#define PAA_FREQUENCYMAP_H

#include <string>
#include <unordered_map>

class FrequencyMap {
public:
    typedef enum MODE {
        character,
        word
    } MODE;

	FrequencyMap() = delete;
	explicit FrequencyMap(const std::string &fn, MODE m);

	~FrequencyMap() = default;

	void inc(const std::string& s);
	void inc(unsigned char c);

	void print() const;

    const std::unordered_map<std::string, int> &get_map() const;
	int get_total() const;

private:

    std::unordered_map<std::string, int> count_map;
    int total;

    void parse_as_word(std::ifstream &entrada);
    void parse_as_char(std::ifstream &entrada);
};

#endif //PAA_FREQUENCYMAP_H
