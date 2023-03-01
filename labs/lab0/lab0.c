#include "lab0.h"

/* REQUIRED CODE GOES HERE */

//function to count and return the number of occurances of a specific integer in an array
int countOccurrences(int size, int array[], int query){
    int count = 0;
    for(int i = 0; i < size; i++){      //this loop tallies the amount of time the query occurs
        if (array[i] == query){
            count++;
        }
    }
    return count;
}