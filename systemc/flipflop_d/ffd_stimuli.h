#ifndef FFD_STIMULI_H
#define FFD_STIMULI_H

#include <systemc.h>

SC_MODULE(DFF_Stimuli) {
    sc_out<bool> CK, D;
    
    void stim() {
        D.write(0);
        CK.write(0);
        wait(10, SC_NS);

        D.write(1);
        wait(10, SC_NS);

        CK.write(1);  // Subida do clock → Q deve seguir D
        wait(10, SC_NS);

        D.write(0);
        CK.write(0);
        wait(10, SC_NS);

        CK.write(1);  // Subida do clock → Q deve seguir D
        wait(10, SC_NS);
    }

    SC_CTOR(DFF_Stimuli) {
        SC_THREAD(stim);
    }
};

#endif
