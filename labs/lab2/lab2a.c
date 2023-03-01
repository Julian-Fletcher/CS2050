#include "lab2.h"

/*dynamically creates an array of the size specified by the paramater "int size"
Assigns a pointer to the new array to the pointer provided in the paramater 
*/
int makeArray(int **array, int size){
	
	*array = malloc(size * (sizeof(int))); //assigning the new array to a pointer 
	if(NULL==*array){
		return 1;
	}
	else{
		return 0;
	}
}

//Initializes an array provided to 0
//Takes a pointer to the array and the size of the array
void initArray(int *array, int size){
	for(int i = 0; i<size; i++){
		array[i] = 0;
	}
}

/*
Takes a pointer to an array, the size, and a number to multiply by
Returns the number of elements that were multiplied 
Only multiplies even numbers or 0
*/
int multiplyEven(int *array, int size, int multiplicand){
	int count = 0;
	//Checks whether a value is even or 0, and multiplies it by the paramater multiplicand
	for(int i = 0; i<size;i++){
		if((array[i] % 2 == 0) || array[i] == 0){
			array[i] *= multiplicand;
			count++;
		}
		else{
			continue;
		}
	}
	return count;
}

/*frees a dynamically allocated array 
and sets the pointer to that array to null
*/
void freeArray(int **array){
	free(*array); 
	*array = NULL;	//set the original pointer to null
}