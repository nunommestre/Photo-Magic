/* Copyright [2021] Nuno Mestre
 * 09/24/2021
 * Class for my FibLFSR implementation used in PhotoMagic to randomize pixels
 * and their colors using the Fibonancci Sequence
 */
#include "FibLFSR.h"
#include <string>
#include <iostream>

FibLFSR::FibLFSR(std::string seed) : data(new int[16]) {
    for (int i = 0; i < 16; i++) {
        data[i] = (seed[i] == '1') ? 1 : 0;
    }
}
int FibLFSR::step() {
    int new_bit = data[0] ^ data[2] ^ data[3] ^ data[5];

    for (int i = 0; i < 15; i++) {
        data[i] = data[i + 1];
    }
    data[15] = new_bit;

    return data[15];
}
int FibLFSR::generate(int k) {
    int decVal = 0;
        //  Every time step = one the one will multiply by two every step
        for (int i = 0; i < k; i++) {
                decVal = (2 * decVal) + step();
        }

        return decVal;
}

FibLFSR::~FibLFSR() {
    delete[] data;
    data = nullptr;
}


std::ostream& operator<<(std::ostream& out, const FibLFSR& object) {
    for (int i = 0; i < 16; i++) {
        out << object.data[i];
    }

    return out;
}
