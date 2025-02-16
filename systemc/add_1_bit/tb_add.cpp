#include <systemc.h>
#include "add1b.h"
#include "add1b_stimuli.h"

int sc_main(int argc, char* argv[]) {
    sc_signal<bool> A, B, Cin, S, Cout;
    sc_clock clk("clk", 10, SC_NS, 0.5, 10, SC_NS, true);

    Adder1b adder("ADDER1B");
    adder.A(A);
    adder.B(B);
    adder.Cin(Cin);
    adder.S(S);
    adder.Cout(Cout);

    Adder1bStimuli stim("STIMULI");
    stim.A(A);
    stim.B(B);
    stim.Cin(Cin);
    stim.S(S);
    stim.Cout(Cout);
    stim.clk(clk);

    // Geração de ondas VCD para análise no GTKWave
    sc_trace_file *tf = sc_create_vcd_trace_file("waves");
    sc_trace(tf, A, "A");
    sc_trace(tf, B, "B");
    sc_trace(tf, Cin, "Cin");
    sc_trace(tf, S, "S");
    sc_trace(tf, Cout, "Cout");

    sc_start(100, SC_NS);
    sc_close_vcd_trace_file(tf);

    return 0;
}
