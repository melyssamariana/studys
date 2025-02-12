/*
Structure of a SystemC Testbench

- Include Libraries (#include) → Import SystemC and module headers.
- Declare Signals (sc_signal) → Create wires to connect modules.
- Instantiate the Module (BlinkLED) → Create and connect an instance of the design.
- Generate the Clock (for loop or SC_METHOD) → Simulate a hardware clock.
- Run the Simulation (sc_start) → Execute for a given time.
*/

#include <systemc.h>
#include "blink_led.h"

int sc_main(int argc, char* argv[]) {
    sc_signal<bool> clk;
    sc_signal<bool> led; 

    BlinkLED blinker("BLINK"); // Instantiate the BlinkLED module
    blinker.CLK(clk);
    blinker.LED(led);


    sc_start(0, SC_NS); // Start the simulation
  
  	// Generate clock: Toggle every 10 ns (50 MHz)
    for (int i = 0; i < 100000000; i++) { // Simulate for 100 ms
        clk.write(i % 2);  // Toggle the clock signal (0 → 1 → 0)
        sc_start(10, SC_NS);   // Advance simulation by 10 ns
    }

    return 0;
}
