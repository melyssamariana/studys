#ifndef AND_H
#define AND_H

#include <systemc.h>

SC_MODULE(And)
{
 public: 
  sc_in<bool> A, B;
  sc_out<bool> Y;

  SC_CTOR(And)
  {
    SC_METHOD(process);
    sensitive << A << B;
  }

 private:
  void process() {
    Y.write(A.read() && B.read());
  }
};

#endif
