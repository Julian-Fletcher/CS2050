#include "lab2.h"

int main(void){
	int size = 10;
	int *array;
	int count = 0;
    makeArray(&array, size);
	initArray(array, size);
	count = multiplyEven(array, size, 2);
	printf("%d\n",count);
	freeArray(&array);
	
	return 0;
}