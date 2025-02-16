#ifndef NOR_H
#define NOR_H

#include <systemc.h>
#include "../gate_nand/nand.h"

SC_MODULE(Nor)
{
 public: 
  sc_in<bool> A, B;
  sc_out<bool> Y;

  // Internal signals
  sc_signal<bool> nand1_out, nand2_out, nand3_out;

  // Instantiate NAND gates
  Nand nand1, nand2, nand3, nand4;

  SC_CTOR(Nor)
    : nand1("NAND1"), nand2("NAND2"), nand3("NAND3"), nand4("NAND4")
  {

    nand1.A(A);
    nand1.B(A);
    nand1.S(nand1_out);

    nand2.A(B);
    nand2.B(B);
    nand2.S(nand2_out);

    nand3.A(nand1_out);
    nand3.B(nand2_out);
    nand3.S(nand3_out);

    nand4.A(nand3_out);
    nand4.B(nand3_out);
    nand4.S(Y);
  }
};

#endif
