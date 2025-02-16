#ifndef LATCH_STIMULI_H
#define LATCH_STIMULI_H

#include <systemc.h>

SC_MODULE(LatchStimuli) {
    sc_out<bool> E, D;
    sc_in<bool> clk;

    void generate_signals() {
        wait(); // Espera o primeiro ciclo

        E.write(0); D.write(0);
        wait(10, SC_NS); // Mantém o estado

        E.write(0); D.write(1);
        wait(10, SC_NS); // Mantém o estado

        E.write(1); D.write(0);
        wait(10, SC_NS); // Atualiza para 0

        E.write(1); D.write(1);
        wait(10, SC_NS); // Atualiza para 1

        E.write(0); D.write(1);
        wait(10, SC_NS); // Mantém estado anterior

        sc_stop(); // Finaliza a simulação
    }

    SC_CTOR(LatchStimuli) {
        SC_THREAD(generate_signals);
        sensitive << clk.pos(); // Sensível ao clock positivo
    }
};

#endif
