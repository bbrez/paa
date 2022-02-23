//
// Created by bbrez on 2/23/2022.
//

#include "Compression.h"

#include <iostream>

#include "util.h"

Compression::Compression(FrequencyMap fm) {
    for (const auto &no: fm.get_map()) {
        this->prio_queue.push(no);
    }
}

void Compression::print() {

    auto print_no = [](const auto &no){
        std::cout << "[";

        if(no.first.length() == 1) {
            if (!is_printable(no.first.c_str()[0])) {
                std::cout << "\\0x" << std::uppercase << std::hex << (int) no.first.c_str()[0] << std::dec;
            } else {
                std::cout << no.first;
            }
        } else {
            std::cout << no.first;
        }

        std::cout << "] = " << no.second << '\n';
    };


    while(!this->prio_queue.empty()){
        print_no(this->prio_queue.top());
        this->prio_queue.pop();
    }
}
