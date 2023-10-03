#include <stdio.h>
#include <inttypes.h>
#include <math.h>


uint32_t ilmanpaine(uint8_t xlsb, uint8_t lsb, uint8_t msb);

int main() {

	float tulos = ilmanpaine(0b11011110, 0b10111100, 0b00011000);
	printf("%f\n", tulos);

	return 0;
}


uint32_t ilmanpaine(uint8_t xlsb, uint8_t lsb, uint8_t msb) {
	
    uint32_t paine = 0;
    
    paine += msb;
    paine <<= 8;
    
    paine += lsb;
    paine <<= 4;
    
    xlsb = (xlsb & 0xf0) >> 4;
    paine += xlsb;
    
    
    
	return paine;
}