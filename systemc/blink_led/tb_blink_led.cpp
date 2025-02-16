#include <systemc.h>
#include "blink_led.h"
#include "blink_led_stimuli.h"

int sc_main(int argc, char *argv[]) {
    sc_trace_file *tf;

    // Create signals
    sc_signal<bool> clk;
    sc_signal<bool> led;

    // Instantiate modules
    BlinkLED blinker("BLINKER");
    StimuliBlink stimuli("STIMULI");

    // Connect signals
    blinker.CLK(clk);
    blinker.LED(led);
    stimuli.CLK(clk);

    // Create waveform file
    tf = sc_create_vcd_trace_file("waves");
    tf->set_time_unit(1, SC_NS);
    sc_trace(tf, clk, "clk");
    sc_trace(tf, led, "led");

    // Run simulation for 1 second (1e9 ns)
    sc_start(1e9, SC_NS);

    // Close VCD file
    sc_close_vcd_trace_file(tf);

    return 0;
}
