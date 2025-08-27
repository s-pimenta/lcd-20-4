#include <stdio.h>
#include "pico/stdlib.h"
#include "drivers/hd44780.h"

int main()
{
    lcd_init(); //Initializes the screen

    //Sending text to the display, 1 character at a time.
    lcd_send_char('H');
    lcd_send_char('I');
    lcd_send_char('!');

    while (true) {

    }
}

