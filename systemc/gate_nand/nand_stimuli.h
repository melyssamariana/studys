#ifndef AND_STIMULI_H
#define AND_STIMULI_H

#include <systemc.h>

SC_MODULE(And_Stimuli)
{
  sc_out<bool> A, B;
  sc_in_clk clk;

  void generate_stimuli()
  {
    wait();
    A.write(0); B.write(0);
    wait();
    A.write(0); B.write(1);
    wait();
    A.write(1); B.write(0);
    wait();
    A.write(1); B.write(1);
    wait();
  }

  SC_CTOR(And_Stimuli)
  {
    SC_THREAD(generate_stimuli);
    sensitive << clk.pos();
  }
};

#endif
