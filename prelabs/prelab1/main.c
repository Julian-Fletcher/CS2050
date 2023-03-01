#include "prelab1.h"

int main(void){
	int array[] = {3, 3, 3, 3, 3, 3, 3, 3, 3, 3};
	int size, dist, min, max;
	size = 10;
	getArray(array, size, &dist, &min, &max);
	printf("There are %d distinct elements in the array. The max is %d and the min is %d.\n", dist, min, max);	
}