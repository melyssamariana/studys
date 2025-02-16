#ifndef NOR_H
#define NOR_H

#include <systemc.h>

SC_MODULE(Nor) {
    sc_in<bool> A, B;
    sc_out<bool> Y;

    void process() {
        Y.write(!(A.read() || B.read()));  // Implementação direta de NOR
    }

    SC_CTOR(Nor) {
        SC_METHOD(process);
        sensitive << A << B;
        dont_initialize();
    }
};

#endif
