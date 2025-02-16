#ifndef ADD1B_STIMULI_H
#define ADD1B_STIMULI_H

#include <systemc.h>

SC_MODULE(Adder1bStimuli) {
    sc_out<bool> A, B, Cin;
    sc_in<bool> S, Cout;
    sc_in_clk clk;

    void generate_stimuli() {
        wait();
        A.write(0); B.write(0); Cin.write(0);
        wait();
        A.write(0); B.write(0); Cin.write(1);
        wait();
        A.write(0); B.write(1); Cin.write(0);
        wait();
        A.write(0); B.write(1); Cin.write(1);
        wait();
        A.write(1); B.write(0); Cin.write(0);
        wait();
        A.write(1); B.write(0); Cin.write(1);
        wait();
        A.write(1); B.write(1); Cin.write(0);
        wait();
        A.write(1); B.write(1); Cin.write(1);
        wait();
    }

    SC_CTOR(Adder1bStimuli) {
        SC_THREAD(generate_stimuli);
        sensitive << clk.pos();
    }
};

#endif
