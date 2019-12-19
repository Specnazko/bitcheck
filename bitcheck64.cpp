#include "bitcheck64.h"


bool BitCheck64::checkBitNumber(uint8_t bitNumber){
    if(bitNumber<64) return true;
    return false;
}


void BitCheck64::setTrue(uint8_t bitNumber){
    if(checkBitNumber(bitNumber)){
        flags= flags | (uint64_t(1)<<bitNumber);
    }
}


void BitCheck64::setFalse(uint8_t bitNumber){
    if(checkBitNumber(bitNumber)){
        flags= flags & (maxvalue64 - (uint64_t(1)<<bitNumber));
    }
}


void BitCheck64::changeBit(uint8_t bitNumber){
    if(checkBitNumber(bitNumber)){
        flags= flags ^ (uint64_t(1)<<bitNumber);
    }
}


bool BitCheck64::checkBit(uint8_t bitNumber){
    if(checkBitNumber(bitNumber)){
        if(flags & (uint64_t(1)<<bitNumber)) return true;
    }
    return 0;
}
