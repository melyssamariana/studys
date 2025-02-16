#ifndef LATCH_SR_H
#define LATCH_SR_H

#include <systemc.h>
#include "../gate_nor/nor.h"

SC_MODULE(LatchSR) {
    sc_in<bool> S, R;  
    sc_out<bool> Q, QB; 

    sc_signal<bool> nor1_out, nor2_out;

    Nor nor1, nor2;

    void update_outputs() {
        Q.write(nor1_out.read());  
        QB.write(nor2_out.read()); 
    }

    SC_CTOR(LatchSR)
        : nor1("NOR1"), nor2("NOR2") {

        // NOR1 (S, QB) -> nor1_out (Q)
        nor1.A(S);
        nor1.B(nor2_out);
        nor1.Y(nor1_out);

        // Conexões da NOR2 (R, Q) -> nor2_out (QB)
        nor2.A(R);
        nor2.B(nor1_out);
        nor2.Y(nor2_out);

        // Adiciona um método para atualizar as saídas Q e QB
        SC_METHOD(update_outputs);
        sensitive << nor1_out << nor2_out; // Atualiza sempre que houver mudança
    }
};

#endif
