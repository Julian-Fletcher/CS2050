#include "prelab2.h"

void *arr;

void * createArray(int length, int dataTypeSize){
	int *array;
	array = malloc(length * dataTypeSize + sizeof(int));
	array[0] = length;
	arr = &array;
	return (void *)(array + 1);
}

float * readFloatFileIntoArray(FILE *fptr, int *length){
	float * array;
	if(NULL!=fptr){ 
		fscanf(fptr,"%d", length);
		printf("The size of the array is %d\n", *length);
		array = createArray(*length, sizeof(float));
		if(NULL!=array){
			for(int i = 0; i < *length; i++){
				if(!feof(fptr)){
					fscanf(fptr, "%f", &array[i]);
				}
			}
			puts("FUNCTION SUCCESS");
			return array;
		}
		else{
			puts("createArray FAILED");
			return NULL;
		}
	}
	else{
		puts("FILE POINTER NOT ASSIGNED!!");
		return NULL;
	}
}



void FreeFloatArray(float **array){
	free(*array-1);
	*array = NULL;
}
