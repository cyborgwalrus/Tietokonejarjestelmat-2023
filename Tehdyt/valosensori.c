#include <stdio.h>
#include <inttypes.h>
#include <math.h>


float valoisuus(uint16_t rekisteri);

int main() {

	float tulos = valoisuus(0b0110110000110101);
	printf("%f\n", tulos);

	return 0;
}


float valoisuus(uint16_t rekisteri) {
	
	uint16_t bitmask = 0xf000;
	uint16_t exp_bits = rekisteri & bitmask;
	
	exp_bits = exp_bits >> 12;

	uint16_t fractional_bits = rekisteri & ~bitmask;

	return 0.01 * pow(2, exp_bits) * fractional_bits;
}