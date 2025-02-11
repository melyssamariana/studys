-- Testbench Structure:
-- Libraries: Allows the use of logic signals and mathematical operations.
-- Entity: Defines that this code has no external inputs or outputs (it is a test circuit).
-- Architecture: Implements the test environment:
--     Test signals (CLK and LED).
--     Instance of the BlinkLED module (calls the real circuit for testing).
--     Clock generator (simulates the FPGA clock pulse).


library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

-- There are no inputs or outputs here, as it is just a test environment
entity BlinkLED_tb is
end BlinkLED_tb;

 -- Defines the test signals and simulation environment
architecture TB of BlinkLED_tb is

    signal CLK_tb  : STD_LOGIC := '0'; 
    signal LED_tb  : STD_LOGIC;         

	-- 1 / 50 MHz equals 20 ns
    constant CLK_PERIOD : time := 20 ns; 

begin
	-- uut: "Unit Under Test"
    -- instance BlinkLED
    uut: entity work.BlinkLED  
        port map (
        	-- Connect test to real
            CLK => CLK_tb,
            LED => LED_tb
        );


    process
    begin 
    	-- Simulates FPGA clock behavior
    	-- Alternates 0 and 1 every 10 ns (20 ns per full cycle)
        while now < 100 ms loop 
            CLK_tb <= '0';
            wait for CLK_PERIOD / 2; 
            CLK_tb <= '1';
            wait for CLK_PERIOD / 2;
        end loop;
        wait;
    end process;
end TB;
