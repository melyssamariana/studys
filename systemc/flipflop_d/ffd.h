#ifndef FFD_H
#define FFD_H

#include <systemc.h>
#include "../latch_d_e/latch.h"  

SC_MODULE(DFF) {
    sc_in<bool> CK, D;
    sc_out<bool> Q, QB;

    sc_signal<bool> CK_neg, latch_d, latch_d_not;

    // Dois latches D
    Latch latch_in, latch_out;

    void inverter_clock() {
        CK_neg.write(!CK.read());  // Inverte o clock para o latch mestre
    }

    SC_CTOR(DFF) 
        : latch_in("LATCH_IN"), latch_out("LATCH_OUT")
    {
        // Inversor de clock
        SC_METHOD(inverter_clock);
        sensitive << CK;

        // Conexão do primeiro latch (Mestre)
        latch_in.E(CK_neg);
        latch_in.D(D);
        latch_in.Q(latch_d);
        latch_in.QB(latch_d_not);

        // Conexão do segundo latch (Escravo)
        latch_out.E(CK);
        latch_out.D(latch_d);
        latch_out.Q(Q);
        latch_out.QB(QB);
    }
};

#endif
