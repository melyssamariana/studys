#include <systemc.h>
#include "and.h"
#include "and_stimuli.h"

int sc_main(int argc, char* argv[])
{
    sc_signal<bool> A, B, Y;
    sc_clock clk("clk", 10, SC_NS);

    And and_gate("AND");
    and_gate.A(A);
    and_gate.B(B);
    and_gate.Y(Y);

    And_Stimuli and_stimuli("Stimuli");
    and_stimuli.A(A);
    and_stimuli.B(B);
    and_stimuli.clk(clk);

    // Abre o arquivo de ondas
    sc_trace_file *wf = sc_create_vcd_trace_file("waves_and");
    sc_trace(wf, clk, "clk");
    sc_trace(wf, A, "A");
    sc_trace(wf, B, "B");
    sc_trace(wf, Y, "Y");

    sc_start(50, SC_NS); // Executa a simulação

    // Fecha arquivo de ondas
    sc_close_vcd_trace_file(wf);
    
    return 0;
}
