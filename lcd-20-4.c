#include <stdio.h>
#include "pico/stdlib.h"
#include "drivers/hd44780.h"

int main()
{
    lcd_init(); //Initializes the screen

    lcd_print(PI_CHAR " 3.14"); //Sending text to the LCD Screen

    while (true) {

    }
}

