#include "prelab5.h"


int main(void){
	
	List *head;
	int ec;
	head = initList(&ec);
	if(ec!=1){
		for(int i = 1; i<101; i++){
			head=insertAtHead(i,head,&ec);
		}
	}
	else{
		puts("FAIL!");
	}
	List *p = head;
	for(int i = 1; i<101; i++){
		printf("Node #%d: %d\n", i, p->object);
		p=p->next;
	}
	printf("Value at index 50 is: %d\n", getAtIndex(50,head));
	printf("List length is: %d\n",getListLength(head));
	
	head = freeList(head);
}