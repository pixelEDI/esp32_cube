#include <Arduino.h>

//20x11
const unsigned char bitmap_batteryfull [] PROGMEM = {
	0x7f, 0xff, 0xc0, 0x80, 0x00, 0x60, 0xbf, 0xff, 0xa0, 0xbf, 0xff, 0xb0, 0xbf, 0xff, 0xb0, 0xbf, 
	0xff, 0xb0, 0xbf, 0xff, 0xb0, 0xbf, 0xff, 0xb0, 0xbf, 0xff, 0xa0, 0x80, 0x00, 0x60, 0x7f, 0xff, 
	0xc0
};

const unsigned char bitmap_batteryhaveFull [] PROGMEM = {
	0x7f, 0xff, 0xc0, 0x80, 0x00, 0x60, 0xbf, 0x80, 0x20, 0xbf, 0x80, 0x30, 0xbf, 0x80, 0x30, 0xbf, 
	0x80, 0x30, 0xbf, 0x80, 0x30, 0xbf, 0x80, 0x30, 0xbf, 0x80, 0x20, 0x80, 0x00, 0x60, 0x7f, 0xff, 
	0xc0
};

const unsigned char bitmap_Battery_Status_10perc [] PROGMEM = {
	0x7f, 0xff, 0xc0, 0x80, 0x00, 0x60, 0xb0, 0x00, 0x20, 0xb0, 0x00, 0x30, 0xb0, 0x00, 0x30, 0xb0, 
	0x00, 0x30, 0xb0, 0x00, 0x30, 0xb0, 0x00, 0x30, 0xb0, 0x00, 0x20, 0x80, 0x00, 0x60, 0x7f, 0xff, 
	0xc0
};