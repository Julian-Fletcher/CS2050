#include "prelab5.h"

/*Returns an empty list with a dummy node
* ec = 0 when malloc is successful, 1 when it fails
*/
List * initList(int *ec){
	*ec = 1;
	List *list = malloc(sizeof(List));
	if(list){
		list->next=NULL;
		*ec = 0;
	}
	return list;	
}
List * insertAtHead(int data, List* list, int* ec){
	if(list->next!=NULL){
		List *p = list->next;
		List *new = malloc(sizeof(List));
		if(new){
			new->next=p->next;
			new->object=data;
			p->next=new;
			*ec=0;
		}
		else{
			*ec=1;
		}
	}
	else{
		List *new=malloc(sizeof(List));
		if(new){
			list->next=new;
			new->object=data;
			new->next=NULL;
			*ec = 0;
		}
		else{
			*ec=1;
		}
	}
	return list;
}
int getAtIndex(int val, List* list){
	List *p = list->next;
	if(p){
		for(int i = 0; i!=val;i++){
			p=p->next;
		}
	}
	return p->object;	
}
int getListLength(List* list){
	int count = 0;
	List *p = list->next;
	if(p){
		for(;p->next!=NULL;p=p->next){
			count++;
		}
	}
	return count;	
}


List * freeList(List * list){
	List *p = list;
	while(list->next!=NULL){
		p =list;
		list=list->next;
		free(p);
	}
	free(list);
	list=NULL;
	return list;
}