#include <stdio.h>
#include <inttypes.h>
#include <string.h>

void movavg(float *array, uint8_t array_size, uint8_t window_size);

int main(void)
{
    float testArray[] = {11.67, 12.91, 15.81, 17.21, 13.39, 14.34, 12.72, 17.47, 16.66, 16.05, 14.42, 18.41, 19.02, 18.82, 18.43, 11.61, 17.5, 16.66, 14.02, 15.33, 16.88, 12.58, 12.8, 13.64, 18.99, 19.44};
    movavg(testArray, 26, 3);

    return 0;
}

void movavg(float *array, uint8_t array_size, uint8_t window_size)
{
    float sum = 0;
    char csvString[array_size * 7];
    char tempString[7];
    for (uint8_t i = 0; i <= array_size - window_size; i++)
    {
        for (uint8_t j = 0; j <= window_size; j++)
        {
            sum += array[i + j];
        }
        sprintf(tempString, "%.02f,", sum / window_size);
        
        if(i==0)strcpy(csvString,tempString);
        else strcat(csvString, tempString);
        
        sum = 0;
    }
    csvString[strlen(csvString) - 1] = '\0';
    
        printf("%s", csvString);

}