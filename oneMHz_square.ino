// for 16 MHz Arduino UNO 1 MHz Square Wave Generator code

// 1 MHz means 1 cycle per microsecond
// 1 MHz square wave means half of a microsecond HIGH, then half of a microsecond LOW signal
// Arduino UNO turns 16 cycles per microsecond so 8 cycles HIGH 8 cycles LOW

//    HIGH            HIGH            HIGH            HIGH
// _--------________--------________--------________---------_
//            LOW             LOW             LOW

void setup() {
  pinMode(12, OUTPUT);
}

void loop() {
                                   
  __asm__ __volatile__ (          
  "cli" "\n\t"                // disable interrupts --> prevents oscilloscope signal glitches
  "cp 0x01,0x01" "\n\t"       // false boolean
  "loop: cbi 0x05,4" "\n\t"   // 2 cycles, pin12 LOW(beginning of endless loop)
  "nop" "\n\t"                    
  "nop" "\n\t"                    
  "nop" "\n\t" 
  "nop" "\n\t"                    
  "nop" "\n\t"                     
  "nop" "\n\t"                // 6 cycles wait                                          --------> total 8 cycles for now
  "sbi 0x05,4" "\n\t"         // 2 cycles, pin12 HIGH
  "nop" "\n\t"                    
  "nop" "\n\t"
  "nop" "\n\t"
  "nop" "\n\t"                // 4 cycles wait 
  "breq loop");               // 2 cycles false boolean used at endless loop creation   --------> total 16 cycles for now
}

// sources: - http://ww1.microchip.com/downloads/en/devicedoc/atmel-0856-avr-instruction-set-manual.pdf
//          - https://electronics.stackexchange.com/a/84782
