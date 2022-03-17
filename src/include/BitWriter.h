//
// Created by minorro on 3/8/22.
//

#ifndef PAA_BITWRITER_H
#define PAA_BITWRITER_H

#include <fstream>

namespace paa {
    class BitWriter {
    public:
        explicit BitWriter(std::ofstream &saida);

        ~BitWriter();

        void write(unsigned char bit);

        unsigned char close();

    private:
        unsigned char buffer;
        int buffer_bits;
        std::ofstream &saida;
    };
};

#endif //PAA_BITWRITER_H
