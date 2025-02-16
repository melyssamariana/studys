#include <systemc.h>
#ifndef NAND_H
#define NAND_H

SC_MODULE(Nand)
{
  sc_in<bool> A, B;
  sc_out<bool> S;

  void process() {
        S.write(!(A.read() && B.read()));  
    }

  SC_CTOR(Nand) {
        SC_METHOD(process);
        sensitive << A << B;
        dont_initialize();  // Evita ativação desnecessária na inicialização
    }

};

#endif
