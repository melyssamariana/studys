#ifndef STIMULI_BLINK_H
#define STIMULI_BLINK_H

#include <systemc.h>

SC_MODULE(StimuliBlink) {
    sc_out<bool> CLK;

    void generate_clock() {
        while (true) {
            CLK.write(0);
            wait(10, SC_NS); // Clock period: 20 ns (50 MHz)
            CLK.write(1);
            wait(10, SC_NS);
        }
    }

    SC_CTOR(StimuliBlink) {
        SC_THREAD(generate_clock);
    }
};

#endif
