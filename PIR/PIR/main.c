/*
 * PIR_LCD.c
 *
 * Reads PIR sensor on ATmega32 and displays status on LCD
 *
 * PIR OUT -> PD0
 */

#include <avr/io.h>
#include <util/delay.h>
#include "LCD.h"

#define PIR_PIN PD0   // PIR sensor connected to PD0

int main(void)
{
    // Configure PIR pin as input
    DDRD &= ~(1 << PIR_PIN);  // PD0 input
    PORTD |= (1 << PIR_PIN);  // Enable pull-up (optional)

    // Initialize LCD
    LCD_init();

    while (1)
    {
        if (PIND & (1 << PIR_PIN))  // PIR HIGH = motion detected
        {
            LCD_command(0x01);  // Clear LCD
			_delay_ms(10);
            LCD_display_string(" Motion Detected ");
        }
        else  // PIR LOW = no motion
        {
            LCD_command(0x01);
			_delay_ms(10);
            LCD_display_string(" Not Detected ");
        }

        _delay_ms(500);  // Small delay to stabilize display
    }
}
