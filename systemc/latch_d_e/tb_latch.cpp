#include <systemc.h>
#include "latch.h"
#include "latch_stimuli.h"

int sc_main(int argc, char* argv[]) {
    sc_signal<bool> E, D, Q, QB; // Sinais internos
    sc_clock clk("clk", 10, SC_NS); // Clock de 10ns

    Latch latch("LATCH"); // Instancia o módulo Latch
    latch.E(E);
    latch.D(D);
    latch.Q(Q);
    latch.QB(QB);

    LatchStimuli stimuli("STIMULI"); // Instancia o módulo de estímulos
    stimuli.E(E);
    stimuli.D(D);
    stimuli.clk(clk);

    // Criar arquivo VCD para GTKWave
    sc_trace_file *tf = sc_create_vcd_trace_file("waves");
    sc_trace(tf, clk, "clk");
    sc_trace(tf, E, "E");
    sc_trace(tf, D, "D");
    sc_trace(tf, Q, "Q");
    sc_trace(tf, QB, "QB");

    // Rodar simulação por 100 ns
    sc_start(100, SC_NS);

    // Fechar arquivo de ondas
    sc_close_vcd_trace_file(tf);

    return 0;
}
