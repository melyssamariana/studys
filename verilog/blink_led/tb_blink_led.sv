// Standard Testbench Structure
// Timescale declaration (Optional, but essential for accurate simulation)
// Module definition (Defines the test signals, but has no external inputs or outputs)
// Module instantiation (uut) (Calls the BlinkLED module to be tested)
// Clock generation (initial and forever) (Creates a clock signal to simulate the FPGA)
// Simulation control (initial and $finish) (Defines when the simulation stops)

`timescale 1ns / 1ps  

module BlinkLED_tb;
    reg CLK_tb;
    wire LED_tb;

 	// Connect test to real
    BlinkLED uut (
        .CLK(CLK_tb),
        .LED(LED_tb)
    );

    initial begin // Block that runs only once at the beginning of the simulation.
        CLK_tb = 0;
        forever #10 CLK_tb = ~CLK_tb; // Toggles the clock (~CLK_tb) every 10 ns
    end

    initial begin
        #100000000; // Wait 100 ms
        $finish;
    end
endmodule
