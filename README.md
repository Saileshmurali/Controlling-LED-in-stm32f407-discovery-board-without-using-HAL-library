# Controlling-LED-in-stm32f407-discovery-board-without-using-HAL-library
Adding the NOP() inside the delay routine depends on compiler. In some IDEs like eclipse, the code will work without adding the NOP, but in keil IDE, if nop is not used, then the compiler optimises the code, so the blinking of LEDs won't take place. 
