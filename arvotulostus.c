#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <math.h>

void kirjoita_sensorit(char* str, float ax, float ay, float az, float press, float temp);

int main() {

    char str[40];
    kirjoita_sensorit(str, 0.2536, -5.3272, -1.3277776, 101325.273261, 27.721667);
    printf("+0.25,-5.33,-1.33,101325,27.72\n");
    printf("%s\n", str);
    return 0;
}

//Kiihtyvyysanturin kolmen akselin arvot annetaan etumerkillisinä (+/-)
//ilmanpaineesta tulostetaan vain kokonaisluku (tulostetaan ilman desimaaleja)
//kaikki muut annetaan kahden desimaalin tarkkuudella.

void kirjoita_sensorit(char* str, float ax, float ay, float az, float press, float temp) {
    sprintf(str, "%+.2f,%+.2f,%+.2f,%i,%.2f", ax, ay, az, (int)round(press), temp);
}

