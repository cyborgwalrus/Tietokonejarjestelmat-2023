#include <stdio.h>
#include <inttypes.h>


struct mpudata_t {
    float data[6];
};
void tarkistus(struct mpudata_t mpu, uint8_t index, float threshold);

int main() {
    struct mpudata_t values = { { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0 } };
    tarkistus(values, 5, 3.21);

    printf("1.00,2.00,3.00,4.00,5.00,6.00 expected\n");
    return 0;
}

//Laadi funktio joka tarkistaa ylittääkö tietorakenteen taulukossa annetun 
//indeksin osoittama arvo kynnysarvon (engl. threshold).
//Jos kynnysarvo ylittyy, tulostetaan kaikki tietorakenteen jäsenen arvot 
//CSV-formaatissa kahden desimaalin tarkkuudella. Muuten älä tulosta mitään.
void tarkistus(struct mpudata_t mpu, uint8_t index, float threshold) {
    float* data;
    data = mpu.data;
    if (mpu.data[index] > threshold) {
        printf("%.2f,%.2f,%.2f,%.2f,%.2f,%.2f\n",
            data[0], data[1], data[2], data[3], data[4], data[5]);
    }
}