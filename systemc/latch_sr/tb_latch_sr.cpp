#include <systemc.h>
#include "latch_sr.h"

int sc_main(int argc, char* argv[]) {
    sc_signal<bool> S, R, Q, QB; // Sinais internos

    LatchSR latch("LATCH_SR"); // Instancia o módulo
    latch.S(S);
    latch.R(R);
    latch.Q(Q);
    latch.QB(QB);

    // Criar arquivo VCD para visualização no GTKWave
    sc_trace_file *tf = sc_create_vcd_trace_file("waves");
    sc_trace(tf, S, "S");
    sc_trace(tf, R, "R");
    sc_trace(tf, Q, "Q");
    sc_trace(tf, QB, "QB");

    // Simulação
    cout << "Iniciando simulação...\n";

    // Estado inicial (S=0, R=0) → Mantém o estado
    S.write(0);
    R.write(0);
    sc_start(10, SC_NS);

    // Estado (S=1, R=0) → Set (Q=1, QB=0)
    S.write(1);
    R.write(0);
    sc_start(10, SC_NS);

    // Volta para (S=0, R=0) → Mantém estado
    S.write(0);
    R.write(0);
    sc_start(10, SC_NS);

    // Estado (S=0, R=1) → Reset (Q=0, QB=1)
    S.write(0);
    R.write(1);
    sc_start(10, SC_NS);

    // Volta para (S=0, R=0) → Mantém estado
    S.write(0);
    R.write(0);
    sc_start(10, SC_NS);

    // Estado proibido (S=1, R=1)
    S.write(1);
    R.write(1);
    sc_start(10, SC_NS);

    cout << "Simulação finalizada.\n";

    // Fecha o arquivo de ondas
    sc_close_vcd_trace_file(tf);

    return 0;
}
