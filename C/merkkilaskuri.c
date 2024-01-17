#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

void merkkilaskuri(char* str, uint8_t* tulos);

int main() {
    uint8_t a[2] = { 0,0 };

    char str[] = "Carcinogen Jaded Oink Debacles    ";
    merkkilaskuri(str, a);
    printf("vowels:%i, not vowels:%i\n",a[0],a[1]);
    return 0;
}

//Tee funktio joka laskee merkkijonon vokaalit ja konsonantit 
//ja sijoittaa tulokset osoittimena annettuun taulukkoon.
//Määritellään vokaaleiksi a, e, i, o, u 
//ja oletetaan loppujen kirjaimien olevan konsonantteja.
//Funktion tulee siis ottaa huomioon isot ja pienet kirjaimet, 
//ja ei laske esimerkiksi pisteitä ja muita välimerkkejä.
//tulos on osoitin kaksi kokonaislukua pitkään taulukkoon [vokaalit, konsonantit].
void merkkilaskuri(char* str, uint8_t* tulos) {
    char* ptr;
    char vokaalit[] = "aeiou";
    for (ptr = str; *ptr != 0; ptr++) {
        
        if(*ptr == ' ')continue;
        bool vowel_found = false;
        *ptr = tolower(*ptr);
        for (char* c = vokaalit; *c != 0; c++) {
            
            if (*ptr == *c) {
                tulos[0]++;
                vowel_found = true;
                break;
            }
        }
        if (vowel_found == false)tulos[1]++;
    }
}
