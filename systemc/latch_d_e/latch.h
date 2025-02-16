#ifndef LATCH_H
#define LATCH_H

#include <systemc.h>

SC_MODULE(Latch) {
    sc_in<bool> E, D;  // Entradas: Enable (E) e Data (D)
    sc_out<bool> Q, QB; // Saídas: Q e QB

    void process() {
        if (E.read()) { // Se Enable (E) = 1, atualiza
            Q.write(D.read());
            QB.write(!D.read());
        }
    }

    SC_CTOR(Latch) {
        SC_METHOD(process);
        sensitive << E << D; // O latch é sensível às mudanças em E e D
    }
};

#endif
