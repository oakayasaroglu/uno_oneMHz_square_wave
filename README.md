# 1 MHz Square Wave Generator Code for 16 MHz Arduino UNO 

## a. Output
This code generates 1 MHz Square Wave for 16 MHz Arduino UNO's. 12th pin is the output pin. 

![Arduino UNO output](images\a.jpg)

This signal has some ringing effect because I didn't match to 50Ω empedance and there isn't any load at the end of the circuit. After fixing these issues, the ringing effect will be gone.

## b. How It Works
With a simple calculation, 1 MHz frequencies period is 1 µS. For each square wave signals has been created with half of a period is HIGH signal, then half of a period is LOW signal. 

![Frequency Calculation](images\b.jpg)

Arduino UNO's clock signal is 16 MHz so clock signal's period is $\frac{1}{16}$ µS. That means 16 times per 1 µS. Due to this calculation, I can set the Arduino for 8 cycles of HIGH signal, then 8 cycles of LOW signal.

Due to AVR Instruction Set Manual:
- `cbi` command uses 2 clock cycles,
- `sbi` command uses 2 clock cycles,
- `breq` command uses 2 clock cycles,
- `nop` command uses 1 clock cycle

### Remind!

This code is written for 16 MHz Arduino UNO's.

## c. References
- [AVR Instruction Set Manual](http://ww1.microchip.com/downloads/en/devicedoc/atmel-0856-avr-instruction-set-manual.pdf)
- [delayMicroseconds Function Explanation](https://electronics.stackexchange.com/a/84782)
