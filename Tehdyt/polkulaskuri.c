#include <stdio.h>
#include <inttypes.h>
#include <math.h>

struct piste {
    int koordinaatit[3];
    struct piste* seuraava;
};

struct polku {
    double matka;
    struct piste* pisteet;
};

void laske_kuljettu_matka(struct polku* polku);

int main() {
    struct piste piste1 = {{1,2,3}, NULL};
    struct piste piste2 = {{10,11,12},&piste1};
    struct piste piste3 = {{5,6,7},&piste2};
    struct polku polku1 = {0,&piste3};
    laske_kuljettu_matka(&polku1);
    printf("matka:%f\n",polku1.matka);
    return 0;
}

void laske_kuljettu_matka(struct polku* polku) {

    struct piste* ptr = polku->pisteet;
    do{
        int sum = 0;
        for (uint8_t i = 0;i < 3; i++) {
            int distance = ptr->koordinaatit[i] - ptr->seuraava->koordinaatit[i];
            sum += distance*distance;
        }
        polku->matka += sqrt(sum);
        ptr = ptr->seuraava;
    }
    while(ptr->seuraava != NULL);
}