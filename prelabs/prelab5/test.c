#include <stdio.h>


int main(void){
int *p, n=100;
float *q, x;
p = &n;
x = n;
q = &x;
p = (int *)q;
printf("%d\n",*p);
}