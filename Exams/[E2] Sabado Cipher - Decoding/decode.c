#include<stdio.h>
#include<stdlib.h>
#include"decode.h"

int* bitmaskToArray(short int word[]) {
    int totalShorts = 4;
    int totalBits = totalShorts * 16; 
    int *bitArray = malloc(totalBits * sizeof(int));

    if (bitArray == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    int index = 0;
    for (int i = 0; i < totalShorts; i++) {
        for (int bit = 15; bit >= 0; bit--) {
            bitArray[index++] = (word[i] >> bit) & 1;
        }
    }

    return bitArray;
}

char* decodeString(int arr[]) {
    char *decoded = malloc(9 * sizeof(char)); 
    if (decoded == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    for (int i = 0; i < 8; i++) {
        unsigned char value = 0;
        for (int bit = 0; bit < 8; bit++) {
            value = (value << 1) | arr[i * 8 + bit];
        }
        decoded[i] = value; 
    }

    decoded[8] = '\0'; 
    return decoded;
}
void displayBitPattern(int arr[]) {
    int totalBits = 64; 
    for (int i = 0; i < totalBits; i++) {
        printf("%d", arr[i]);
        if ((i + 1) % 16 == 0) printf(" ");
    }
}