#include "lab4.h"

//creates an array with the given array size and the element size. Stores the size of the array in spot [0]
//will return a null pointer if the array cannot be created
void * makeArray(int arraySize, int elementSize){
	int *array;
	array = malloc(arraySize * elementSize + sizeof(int));	//allocate space for the array + room for the size
	if(NULL!=array){
		array[0] = arraySize;
		return (void *)(array+1);	//return a void pointer to the user and hide the size
	}
	else{
		return NULL;
	}
}

//returns the size of an array made with makeArray, needs an array made by "makeArray"
int getSize(void *array){
	return *(((int *)array) - 1);
}

//takes a specificied weight and counts how many inventory items in an array have that specified value
int countWithWeight(InventoryItem *items, float weight){
	int size = getSize((void *)items);
	int count = 0;
	//increments through the array and checks if the size of each element matches the specified value
	for(int i = 0;i<size;i++){
		if(items[i].weight == weight){
			count++;
		}
	}
	return count;
}

//free an array created by makeArray
void freeArray(void *array){
	free(((int *)array)-1);
}