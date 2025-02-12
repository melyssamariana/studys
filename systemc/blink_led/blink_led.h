/*
SystemC Code Structure
- Library Inclusion (#include and sc_module)
- Module Definition (SC_MODULE)
- Port Declaration (sc_in and sc_out)
- Process Definition (SC_METHOD or SC_THREAD)
- Implementation of sc_main (Main Function)
*/

#ifndef BLINKLED_H
#define BLINKLED_H

#include <systemc.h>

SC_MODULE(BlinkLED) { // Defines a SystemC module named BlinkLED
    sc_in<bool> CLK;  
    sc_out<bool> LED;
    
    int counter = 0;  // Contador interno
    bool led_state = false;

    void blink_process() { // Defines the LED blinking logic
        while (true) {
            wait(); // Wait for clock edge
            counter++;
            if (counter == 50000000) { 
                led_state = !led_state;
                LED.write(led_state);
                counter = 0;
            }
        }
    }

    SC_CTOR(BlinkLED) { //  is a SystemC constructor macro used to define the constructor of a SystemC module. It is a shortcut for SC_MODULE constructor initialization.
        SC_THREAD(blink_process); // Registers the process to be executed in a loop
        sensitive << CLK.pos();  // Triggers execution on rising edge of CLK.
    }
};

#endif
