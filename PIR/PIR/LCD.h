/*
 * LCD.h
 *
 * Created: 8/9/2025 12:13:18 PM
 *  Author: ASUS
 */ 


#ifndef LCD_H_
#define LCD_H_

#include <avr/io.h>
#include <avr/delay.h>
#define LCD_DATA_PORT PORTC
#define LCD_CTRL_PORT PORTA
#define RS_PIN PA0
#define RW_PIN PA1
#define E_PIN PA2


void LCD_command(unsigned char cmnd);
void LCD_data(unsigned char data);
void LCD_init();
void LCD_display_string(const char *str);
void LCD_display_char( const char *chr );

void LCD_create_char(unsigned char location, unsigned char charmap[]);
void wave_animation(const char *text);

void typewriter(const char *text, uint8_t row);
void LCD_goto(uint8_t row, uint8_t col);

#endif /* LCD_H_ */