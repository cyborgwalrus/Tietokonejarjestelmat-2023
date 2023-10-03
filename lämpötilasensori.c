#include <stdio.h>
#include <inttypes.h>

float lampotila(uint16_t rekisteri, float kerroin);

float lampotila(uint16_t rekisteri, float kerroin) {
	uint16_t bitmask = 0xFFFC;
	uint16_t bits = rekisteri & bitmask;
	bits = bits >> 2;

	return (float)bits * kerroin;
}