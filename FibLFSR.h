//  Copyright [2021] Nuno Mestre
#ifndef _HOME_NUNO_PSX_FIBLFSR_H_
#define _HOME_NUNO_PSX_FIBLFSR_H_

#include <string>
#include <iostream>

class FibLFSR {
 public:
    explicit FibLFSR(std::string seed);
    int step();
    int generate(int k);
    friend std::ostream& operator<<(std::ostream& out, const FibLFSR& object);
    ~FibLFSR();
 private:
        int* data;
};
#endif  //  _HOME_NUNO_PSX_FIBLFSR_H_
