#include "lab1.h"
#include <stdlib.h>

int main(void){
	int array[10] = {-1,2,3,4,-5,6,7,8,-9,10};
	int size = 10;
	float avg;
	int sum;
	
	getAverage(array, size, &avg);
	printf("%2f\n", avg);
	sumPositive(array, size, &sum);
	printf("%d\n", sum);
}