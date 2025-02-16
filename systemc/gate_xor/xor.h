#ifndef XOR_H
#define XOR_H

#include <systemc.h>
#include "../gate_nand/nand.h"

SC_MODULE(Xor) {
    sc_in<bool> A, B;
    sc_out<bool> Y;

    // Internal signals
    sc_signal<bool> nand1_out, nand2_out, nand3_out, nand4_out;

    // Single instance of NAND gates (reused)
    Nand nand1, nand2, nand3, nand4;

    void compute() {
        Y.write(nand4_out.read());  // Atualiza a saída com a última NAND
    }

    SC_CTOR(Xor) 
        : nand1("NAND1"), nand2("NAND2"), nand3("NAND3"), nand4("NAND4") {

        // Conectando as NANDs para formar XOR
        nand1.A(A);
        nand1.B(B);
        nand1.S(nand1_out);

        nand2.A(A);
        nand2.B(nand1_out);
        nand2.S(nand2_out);

        nand3.A(B);
        nand3.B(nand1_out);
        nand3.S(nand3_out);

        nand4.A(nand2_out);
        nand4.B(nand3_out);
        nand4.S(nand4_out);

        // Método para atualizar a saída final
        SC_METHOD(compute);
        sensitive << nand4_out;
        dont_initialize();
    }
};

#endif
