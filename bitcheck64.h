#ifndef BITCHECK64_H
#define BITCHECK64_H


#include <stdio.h>
#include <stdint.h>

const uint64_t maxvalue64=0xffffffffffffffff; // 18446744073709551615

class BitCheck64{
private:
    uint64_t flags;
    bool checkBitNumber(uint8_t bitNumber);
public:
    BitCheck64(): flags(0x0000000000000000) {}
    BitCheck64(uint64_t flags): flags(flags) {}
    BitCheck64(BitCheck64 const& fl): flags(fl.flags) {}
    void setTrue(uint8_t bitNumber);
    void setFalse(uint8_t bitNumber);
    void changeBit(uint8_t bitNumber);
    bool checkBit(uint8_t bitNumber);
};

#endif // BITCHECK64_H
