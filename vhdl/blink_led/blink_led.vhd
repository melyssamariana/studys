--Standard structure:
--Libraries: Defines the basic functionalities used
--Entity: Defines the inputs and outputs of the circuit.The entity defines the hardware
--Architecture: Implements the logic of the circuit

library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL; 

entity BlinkLED is
    Port (
        CLK : in  STD_LOGIC;
        LED : out STD_LOGIC
    );
end BlinkLED;

--Two internal variables (signals):
--counter: A counter that controls the time to toggle the LED.
--led_state: Stores the current state of the LED (0 = off, 1 = on)

architecture Behavioral of BlinkLED is
    signal counter : integer := 0;
    signal led_state : STD_LOGIC := '0';
begin
    process(CLK)
    begin
        if rising_edge(CLK) then
            counter <= counter + 1;
            --1 / 50MHz x 50M equals 1s
            if counter = 50000000 then
                led_state <= NOT led_state;
                counter <= 0;
            end if;
        end if;
    end process;
    LED <= led_state;
end Behavioral;
