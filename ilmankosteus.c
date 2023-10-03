#include <stdio.h>
#include <inttypes.h>
#include <math.h>

float kosteus(uint16_t rekisteri);

int main() {
	
	return 0;
}

float kosteus(uint16_t rekisteri) {
	uint16_t bitmask = 0xFFFC;
	uint16_t bits = rekisteri & bitmask;
	//bits = bits >> 2;

	return (float)bits / pow(2,16) * 100;
}