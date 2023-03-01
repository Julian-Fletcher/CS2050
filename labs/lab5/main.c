#include "lab5.h"


int main(void){
	Node *list;
	makeList(&list);
	printf("%d\n", getSize(list));
	int x = -1;
	for(int i = 0; i< 10;i++){
		x = insertAtTail(&list, (void*)&i);
		if(x == 1){
			puts("FAIL");
			break;
		}
	}
	Node *p = list;
	for(int i = 0; i<10;i++){
		printf("%d\n", *(int*)p->data);
		p=p->next;
	}
	
	printf("Size is %d\n", getSize(list));
	removeFromHead(&list);
	puts("$");
	printf("%d\n", getSize(list));
	p = list;
	for(int i = 0; i<9;i++){
		printf("%d\n", *(int*)p->data);
		p=p->next;
	}
	freeList(&list);
	p = list;
	
}