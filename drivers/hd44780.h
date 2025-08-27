#ifndef HD44780_H
#define HD44780_H

#include "pico/stdlib.h" // Pico Standard Library

// ### YOU CAN CHANGE AFTER THIS LINE ###

// Defining pins (values accepted: 0-29)
#define RS_PIN 1 // Register Select pin
#define E_PIN 2  // Enable pin
#define D4_PIN 4 // Data 4 pin
#define D5_PIN 5 // Data 5 pin
#define D6_PIN 6 // Data 6 pin
#define D7_PIN 7 // Data 7 pin

// ### DO NOT CHANGE AFTER THIS LINE ###

// Creates a bitmask of the pins will be used to the LCD screen
#define PINS_BITMASK ((1u << RS_PIN) | (1u << E_PIN) | (1u << D4_PIN) | (1u << D5_PIN) | (1u << D6_PIN) | (1u << D7_PIN))   

// Instructions to initialize the LCD
#define MODE_8BIT 0x03
#define MODE_4BIT 0x02

// Function set
// |0|0|1|DL|N|F|-|-|
// DL: 1 -> 8-bits    | 0 -> 4-bits (Data Length)
// N:  1 -> 2 lines   | 0 -> 1 line (Number display lines)
// F:  1 -> 5x10 dots | 0 -> 5x8 dots (Character Font)
//                                    D
//                                 001LNF--
#define MODE_4BIT_2LINES_5X8FONT 0b00101000 //0x28

// Display on/off control
// |0|0|0|0|1|D|C|B|
// D: 1 -> Display on | 0 -> Display off
// C: 1 -> Cursor on  | 0 -> Cursor off
// B: 1 -> Blink on   | 0 -> Blink off
//                                    00001DCB
#define DISPLAY_OFF                 0b00001000 //0x08
#define DISPLAY_ON_NOCURSOR_NOBLINK 0b00001100 //0x0C
#define DISPLAY_ON_CURSOR_BLINK     0b00001111 //0x0F
#define DISPLAY_ON_NOCURSOR_BLINK   0b00001101 //0x0D
#define DISPLAY_ON_CURSOR_NOBLINK   0b00001110 //0x0E

// Clear display
// Clears entire display and sets the DDRAM address to 0
#define CLEAR_DISPLAY 0x01

// Entry mode set
// |0|0|0|0|0|1|I/D|S|
// I/D: 1 -> Increment | 0 -> Decrement
#define ENTRY_MODE_INCREMENT_NOSHIFT 0b00000110 // 0x06
#define ENTRY_MODE_DECREMENT_NOSHIFT 0b00000100 // 0x04

//Characters codes
#define EXCLAMATION_CHAR 0x21
#define AT_CHAR 0x40   // @
#define A_UPPER_CHAR 0x41 // A

//Function declarations
void lcd_init(void);
void lcd_write_nibble(uint8_t nibble);
void lcd_write_byte(uint8_t byte, bool is_data);
void lcd_pulse_enable();
void lcd_send_command(uint8_t cmd);
void lcd_send_char(char c);

#endif