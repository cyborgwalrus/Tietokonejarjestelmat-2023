#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>

float keskiarvo(char* lista);

int main() {
    char str[] = "201,53,12,31,5";
    printf("%.1f\n60.4\n", keskiarvo(str));
    return 0;
}

float keskiarvo(char* lista) {
    float sum = 0.0;
    int8_t count = 0;
    const char seperator[] = ",";
    char* c_ptr;

    c_ptr = strtok(lista, seperator);

    while (c_ptr != NULL) {
        sum += atol(c_ptr);
        count++;
        c_ptr = strtok(NULL, seperator);
    }
    return sum / count;
}