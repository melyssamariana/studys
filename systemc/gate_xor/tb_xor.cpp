#include <systemc.h>
#include "xor.h"
#include "xor_stimuli.h"

int sc_main(int ac, char *av[])
{
  sc_trace_file *tf;
  // signals
  sc_signal<bool> in1;
  sc_signal<bool> in2;
  sc_signal<bool> out1;
  // instanciate
  Xor xor1("xor1");
  Xor_stimuli stimuli1("stimuli1");
  sc_clock clk ("ID", 10, SC_NS, 0.5, 10, SC_NS, true);
  // link
  xor1.A(in1);
  xor1.B(in2);
  xor1.Y(out1);
  stimuli1.clk(clk);
  stimuli1.s1(in1);
  stimuli1.s2(in2);
  // Waves:
  tf = sc_create_vcd_trace_file("waves");
  tf->set_time_unit(1, SC_NS);
  sc_trace(tf, clk, "clk");
  sc_trace(tf,in1,"in1");
  sc_trace(tf,in2,"in2");
  sc_trace(tf,out1,"out1");
  sc_start(500, SC_NS);
  sc_close_vcd_trace_file(tf);
  return 0;
}
