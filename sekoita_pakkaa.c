#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

void shuffle(uint8_t *list, uint16_t list_size);

int main(){
    uint8_t list[8] = { 1,2,3,4,5,6,7,8};
    shuffle(list,8);

}

void shuffle(uint8_t *list, uint16_t list_size){
    uint8_t tempList[list_size];
    
    for(uint16_t i=0; i<list_size;i++){
        uint16_t randIndex = rand() % (list_size-i);
        tempList[i] = list[randIndex];
        
        for(uint16_t j=randIndex;j<list_size-i-1;j++){
            list[j] = list[j+1];
        }

    }
    for(uint16_t i=0;i<list_size;i++){
        list[i] = tempList[i];
    }
}

