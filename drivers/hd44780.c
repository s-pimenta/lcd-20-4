#include "hd44780.h" // Incluing the corresponding header

#include "pico/stdlib.h" // Pico standard library

// Initializes the LCD screen
void lcd_init(void) {

    gpio_init_mask(PINS_BITMASK); // Initializes the LCD GPIOs to SIO
    gpio_set_dir_out_masked(PINS_BITMASK); // Sets the LCD GPIOs to Output

    sleep_ms(40); // Datasheet says to wait at least 40 miliseconds to LCD to wake up

    lcd_write_nibble(MODE_8BIT);
    sleep_ms(5);
    lcd_write_nibble(MODE_8BIT);
    sleep_us(100);
    lcd_write_nibble(MODE_8BIT);

    //Switch to 4-bit mode
    lcd_write_nibble(MODE_4BIT);

    //Sets the number of lines and character font (cannot be changed after this point)
    lcd_send_command(MODE_4BIT_2LINES_5X8FONT);

    //lcd_send_command(DISPLAY_OFF);
    lcd_send_command(CLEAR_DISPLAY);

    //Sets the entry mode
    lcd_send_command(ENTRY_MODE_INCREMENT_NOSHIFT);

    //Sets the display on the cursor and blinking
    lcd_send_command(DISPLAY_ON_CURSOR_BLINK);
}

void lcd_write_byte(uint8_t byte, bool is_data) {
    
    // checks if the data in the data pins is for the Data register, or Instruction register
    if (is_data) {
        gpio_put(RS_PIN, 1);
    }
    else {
        gpio_put(RS_PIN, 0);
    }
    //write the high nibble first
    lcd_write_nibble(byte >> 4);

    // Then the low nibble
    lcd_write_nibble(byte & 0x0F);
}

// Sends a 4-bit (nibble) data to LCD
void lcd_write_nibble(uint8_t nibble) {

    // Sets the nibble data for each pin
    gpio_put(D4_PIN, (nibble >> 0) & 0x01); // The (nibble >> 0) & 0x01 can be replaced to just nibble & 0x01
    gpio_put(D5_PIN, (nibble >> 1) & 0x01);
    gpio_put(D6_PIN, (nibble >> 2) & 0x01);
    gpio_put(D7_PIN, (nibble >> 3) & 0x01);

    lcd_pulse_enable(); // Pulses the (E)nable pin
}

// Sends a pulse to the (E)nable Pin
void lcd_pulse_enable() {
    gpio_put(E_PIN, 1); // Sets the pin HIGH (1)
    sleep_us(1); // Waits 1 microsecond
    gpio_put(E_PIN, 0); // Sets the pin LOW (0)
    sleep_us(40); // Needs at least 37 microseconds (datasheet page 24)
}

// Sends a command to the display
void lcd_send_command(uint8_t cmd){
    lcd_write_byte(cmd, false);
    sleep_ms(2);
}

// Sends a character to the display
void lcd_send_char(char c) {
    lcd_write_byte(c, true);
    sleep_us(43); // Data writes need at least 43 microseconds
}

// Prints a string of text to the screen
void lcd_print(const char *text){
    int i = 0; //track the current postion of the string

    while (text[i] != '\0') { // checks if the current character is null
        lcd_send_char(text[i]); // sends the character to the lcd screen
        i = i + 1; // increments the index position
    }
}


