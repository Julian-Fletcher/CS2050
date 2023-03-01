#include "prelab2.h"
#define FILENAME "data.txt"


int main(void){
	FILE * fp = fopen(FILENAME, "r");
	int arrayLen = 0;
	float *array = readFloatFileIntoArray(fp, &arrayLen);
	for(int i = 0; i < arrayLen; i++){
		printf("%f\n", array[i]);
	}
	FreeFloatArray(&array);
	puts("After");
	for(int i = 0; i < arrayLen; i++){
		printf("%f\n", array[i]);
	}
}