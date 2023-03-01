#include "lab3.h"

//take an integer and allocates a string array of that size, stores size in [0], returns 0 on success null on failure
char * strAlloc(int size){
	int *str;
	str = malloc((size * sizeof(char)) + sizeof(int));	//dynamically allocate the array and leave room for the size
	if (NULL!=str){
		str[0] = size;
		str++;
		return (char *)(str);			//return a char pointier to the user and hide the size
	}
	else{
		return NULL;
	}
}

//returns the size of an array made with strAlloc, needs an array made with strAlloc
int strLen(char *str){
	if(NULL!= str){
		return ((int *)str)[-1];
	}
	else{
		return 0;
	}
}

//takes source array and cpys it into the destination, assumes destination can fit the source
void strCpy(char *source, char *dest){
	int size = *(((int *)source)-1);	//casts to an integer then accesses the -1 element which is the size
	for(int i = 0;i<size;i++){
		dest[i] = source[i];
	}
}

//checks if the source is the same as the reverse of the destination array 1 if same, 0 if not the same. Assumes they are the same size
int strCmpRev(char *source, char *dest){
	if(NULL==source || NULL ==dest){
		return 0;
	}
	int size = ((int *)source)[-1];
	int c = 0;
	//increments through each array (one forward, one backward) and checks/tallies how many characters are the same
	for(int i = 0; i<size;i++){
		if((source[i] == dest[size-i-1])){
			c++;
		}
		else{
			break;
		}
	}
	if(size != c){
		c = 0;
	}
	else{
		c = 1;
	}
	return c;
}

//frees an array made by strAlloc
void strFree(char *str){
	free(((int *)str)-1);
}