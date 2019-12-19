#include "bitcheck64.h"

#include <iostream>

using namespace std;

class hack64{
public:
    uint64_t flags;
};

int main(int argc, char *argv[]){
    BitCheck64 *flags=new BitCheck64(0x00ff00ff00ff00ff);

    for(uint8_t i=0; i<16; i++){
        flags->setTrue(i);
    }
    //0x00ff00ff00ff(ffff)

    for(uint8_t i=16; i<32; i++){
        flags->setFalse(i);
    }
    //0x00ff00ff(0000)ffff

    for(uint8_t i=48; i<64; i++){
        flags->changeBit(i);
    }
    //0x(ff00)00ff0000ffff

    hack64* haha= (hack64*)(void*)flags;
    cout<<hex<<haha->flags<<endl<<dec;
    for(uint8_t j=0; j<4; j++){
        for(uint8_t i=0; i<4; i++){
            for(uint8_t k=0; k<4; k++){
                cout<<(flags->checkBit(63-j*16-4*i-k) ? 1:0);
            }
            cout<<' ';
        }
        cout<<endl;
    }
}
