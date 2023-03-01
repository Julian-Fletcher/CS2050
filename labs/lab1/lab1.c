#include "lab1.h"

//This function calculates the average value of an array 
int getAverage(int array[], int size, float *result){
	float sum;
	if(NULL!= array && NULL!=result && size >0){	//checks whether either pointer is NULL, and if size is a positive number
		for(int i = 0; i < size; i++){
			sum += (float)array[i];
		}
		*result = (sum/(float)size);
		if(*result >= 0 || *result <= 0){	//checks if the average is a real number
			return 0;
		}
		else{		//returns 0 if the average is not a real number
			return 1;
		}
	}
	else{			//returns 1 (failure) if the if statment is not passed
		return 1;
	}
}


//This function calculates the sum of all positive numbers in an array
int sumPositive(int array[], int size, int *result){
	if(NULL!=array && NULL!=result && size>0){		//checks whether either pointer is NULL, and if size is a positive number
	for(int i = 0; i < size; i++){
			if(array[i] > 0){
				*result+=array[i];
			}
			else{
				continue;
			}
		}
		return 0;
	}
	else{			//returns 1 (failure) if the if statment is not passed
		return 1;
	}
}
