#include <systemc.h>
#include "ffd.h"
#include "ffd_stimuli.h"

int sc_main(int argc, char* argv[]) {
    sc_signal<bool> CK, D, Q, QB;
    
    DFF flipflop("FlipFlop");
    DFF_Stimuli stimuli("Stimuli");

    flipflop.CK(CK);
    flipflop.D(D);
    flipflop.Q(Q);
    flipflop.QB(QB);

    stimuli.CK(CK);
    stimuli.D(D);

    // Criando o arquivo de onda para GTKWave
    sc_trace_file *tf = sc_create_vcd_trace_file("waves");
    sc_trace(tf, CK, "CK");
    sc_trace(tf, D, "D");
    sc_trace(tf, Q, "Q");
    sc_trace(tf, QB, "QB");

    // Executando a simulação
    sc_start(50, SC_NS);

    // Fechando o arquivo de onda
    sc_close_vcd_trace_file(tf);
    return 0;
}
