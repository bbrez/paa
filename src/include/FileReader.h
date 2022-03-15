//
// Created by minorro on 3/14/22.
//

#ifndef PAA_FILEREADER_H
#define PAA_FILEREADER_H


#include <fstream>
#include <sstream>

class FileReader {
public:
    typedef enum MODE {
        character,
        word
    } MODE;

    FileReader(std::ifstream &infile, MODE m);

    bool eof() const;
    std::string get_next();

private:

    MODE m;
    std::ifstream &infile;
    std::stringstream buffer;

    std::string get_char();
    std::string get_word();
};


#endif //PAA_FILEREADER_H
