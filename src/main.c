#include "my_malloc.h"

#include <stdio.h>

#define SIZE1 5
#define SIZE2 10


int main() {
    printf("hello world: %lu\n", sizeof(intptr_t));


    int* arr1 = my_malloc(sizeof(int) * SIZE1);
    int* arr2 = my_malloc(sizeof(int) * SIZE2);

    for (int i = 1; i <= SIZE1; i++) {
        arr1[i] = i * 10;
    }
    for (int i = 1; i <= SIZE2; i++) {
        arr2[i] = i * 100;
    }

    printf("address 1: %p\n", arr1);
    printf("address 2: %p\n", arr2);

    printf("arr1[4]: %d\n", arr1[4]);
    printf("arr2[7]: %d\n", arr2[7]);

    my_free(arr1);
    printf("arr2[7]: %d\n", arr2[7]);

    my_free(arr2);


    return 0;
}