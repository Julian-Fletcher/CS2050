#include "prelab1.h"

void getArray(int *array, int n, int *distp, int *minp, int *maxp){
	int min, max, occur, count;
	min = array[0];
	max = array[0];
	occur = 0;
	int dist[n];
	for(int i = 0; i < n; i++){
		if(array[i] < min) min = array[i];
		if(array[i] > max) max = array[i];
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if (dist[j] == array[i]){
				break;
			}
			else{
				count++;
			}
		}
		if(count == n){
			dist[i] = array[i];
		}
		count = 0;
	}
	for(int i = 0; i < n; i++){
		if (dist[i] != 0){
			occur++;
		}
	}
	
	
	
	*distp = occur;
	*minp = min;
	*maxp = max;
}