#include "lab3.h"
#include<string.h>

int main(void){
	char *str1;
	char *str2;
	str1 = strAlloc(5);
	str2 = strAlloc(5);
	
	int a = strLen(str1);
	int b = strLen(str2);
	
	strcpy(str1, "Hello");
	strcpy(str2, "Hello");
	
	printf("A: %d B: %d\n", a, b);
	strCpy(str1, str2);
	printf("%s, %s\n", str1, str2);
	int c = strCmpRev(str1, str2);
	printf("%d\n", c);
	
	strFree(str1);
	strFree(str2);
	
}