// Standard Structure
// Timescale declaration (Optional, but recommended for simulations)
// Module definition (Defines inputs and outputs of the circuit)
// Signal declaration (wire and reg)
// Always and assign blocks (Defines the circuit logic)
// endmodule (Finalizes the module code)

// Defines the Time Unit
// 1ns (nanosecond) → Sets the basic unit of time for the simulation.
// 1ps (picosecond) → Sets the minimum accuracy of the time that can be measured.
`timescale 1ns / 1ps 

// wire - Direct connections (like wires) - For combinational assignments (assign)
// reg  - Stores values in flip-flops     - Inside clocked always blocks
module BlinkLED (
    input wire CLK,  
    output reg LED    
);
  
// Declares a 32-bit register to store the count
    reg [31:0] counter = 0;  

// (A) Combinational Logic (assign): assign result = A &state;
// (B) Sequential Logic (always): 

  always @(posedge CLK) begin // Executes this block on each rising edge of the clock (CLK)
        counter <= counter + 1;
        if (counter == 50000000) begin  
            LED <= ~LED; // Inverts (~) the state
            counter <= 0;
        end
    end
endmodule
