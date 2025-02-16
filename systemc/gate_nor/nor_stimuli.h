#ifndef NOR_STIMULI_H
#define NOR_STIMULI_H

#include <systemc.h>

SC_MODULE(Nor_stimuli)
{
 public:
  sc_in_clk clk;
  sc_out<bool> s1, s2;

  void stim() {
      while (true) {
          wait(); // Wait for clock edge
          s1.write(1);
          wait();
          s2.write(1);
          wait();
          s1.write(0);
          wait(1, SC_NS);
          s2.write(0);
          wait();
          s1.write(1);
          s2.write(1);
          wait();
          s2.write(0);
          wait();
          s1.write(0);
          wait(8, SC_NS);
      }
  }

  SC_CTOR(Nor_stimuli) {
      SC_THREAD(stim);
      sensitive << clk.pos();
  }
};

#endif
