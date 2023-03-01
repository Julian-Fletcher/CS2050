#include "prelab3.h"

void * createArray(int size, int dataTypeSize){
	int *array;
	array = malloc(size * dataTypeSize + sizeof(int));
	array[0] = size;
	return (void *)(array+1);
}
int getArraySize(void *array){
	return *(((int *)array) - 1);
}
void freeArray(void *array){
	free(((int *)array)-1);
	array = NULL;
}