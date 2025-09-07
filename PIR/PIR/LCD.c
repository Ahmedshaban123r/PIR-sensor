
/*
 * LCD.c
 *
 * Created: 8/9/2025 12:16:24 PM
 *  Author: ASUS
 */ 
#include "LCD.h"

void LCD_command(unsigned char cmnd)
{
	LCD_DATA_PORT = cmnd; // Send the command to the data port
	LCD_CTRL_PORT &= ~(1 << RS_PIN); // RS = 0 for command
	LCD_CTRL_PORT &= ~(1 << RW_PIN); // RW = 0 for write
	LCD_CTRL_PORT |= (1 << E_PIN); // Enable high
	_delay_ms(1);
	LCD_CTRL_PORT &= ~(1 << E_PIN); // Enable low
	_delay_ms(1);
}

void LCD_data(unsigned char data)
{
	LCD_DATA_PORT = data; // Send the data to the data port
	LCD_CTRL_PORT |= (1 << RS_PIN); // RS = 1 for data
	LCD_CTRL_PORT &= ~(1 << RW_PIN); // RW = 0 for write
	LCD_CTRL_PORT |= (1 << E_PIN); // Enable high
	_delay_ms(1);
	LCD_CTRL_PORT &= ~(1 << E_PIN); // Enable low
	_delay_ms(1);
}

void LCD_init()
{
	// Set data and control ports as outputs
	DDRC = 0xFF; // Data port
	DDRA |= (1 << RS_PIN) | (1 << RW_PIN) | (1 << E_PIN); // Control port
	_delay_ms(20); // LCD Power ON delay
	LCD_command(0x38); // 2 lines, 5x7 matrix
	LCD_command(0x0E); // Display on, cursor on
	LCD_command(0x01); // Clear display
	_delay_ms(2);
}

void LCD_display_string(const char *str)
{
	for (int i = 0; str[i] != '\0'; i++)
	{
		LCD_data(str[i]);//A--> N--> A--> S--> \0 BREAK
		_delay_ms(100);
	}
}
void LCD_display_char( const char *chr )

{
	LCD_data(chr);
}

void LCD_create_char(unsigned char location, unsigned char charmap[]) {
	location &= 0x07; // Only 0–7 allowed
	LCD_command(0x40 | (location << 3)); // Set CGRAM address
	_delay_ms(100);
	for (int i = 0; i < 8; i++) {
		LCD_data(charmap[i]); // Send row pattern
		_delay_ms(100);
	}
}

void LCD_goto(uint8_t row, uint8_t col) {
	uint8_t address;

	if (row == 0) {
		address = 0x80 + col;  // First line
		} else {
		address = 0xC0 + col;  // Second line
	}

	LCD_command(address);
}

void wave_animation(const char *text) {
	uint8_t len = 0;
	while (text[len] != '\0') len++; // Get text length

	int pos_start = 0; // start column
	int phase = 0;     // wave phase

	while (1) {
		LCD_command(0x01); // Clear
		_delay_ms(10);

		for (uint8_t i = 0; i < len; i++) {
			uint8_t row = ((i + phase) % 2); // Alternate rows for wave effect
			LCD_goto(row, pos_start + i);
			_delay_ms(10);
			LCD_data(text[i]);
			_delay_ms(1000);
		}

		phase++;
		if (phase >= 2) phase = 0; // reset wave pattern
		_delay_ms(20000);
	}
}


void typewriter(const char *text, uint8_t row) {
	LCD_goto(row, 0);  // Start position
	for (uint8_t i = 0; text[i] != '\0'; i++) {
		LCD_data(text[i]);
		_delay_ms(150); // Typing speed
	}
}



