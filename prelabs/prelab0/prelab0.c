#include "prelab0.h"

//write a function that searches an array for the # of integers in the array that are greaterthan or equal to the integer being searched for

int querey(int *array, int size, int querey){
    int count = 0;
    for (int i = 0; i < size; i++){
        if (*(array + i) >= querey){
            count++;
        }
        else{
            continue;
        }
    }
    return count;
}