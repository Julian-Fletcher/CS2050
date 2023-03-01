#include "prelab5.h"


List * initList(int *error){
	List *list;
	list = malloc(sizeof(List));
	
	if(list){
		list->next=NULL;
		return list;
	}
	return list;
}

List * insertAtHead(int object, List* list, int* errorCode){
	List *p = malloc(sizeof(List));
	if(p){
		p->object = object;
		p->next = list;
		list = p;
		*errorCode = 0;
	}
	else{
		*errorCode = 1;
	}
	return list;
}


int getAtIndex(int pos, List* list){
	List *p = list->next;
	for(int i = 1;i!=pos;i++){
		p = list->next;
	}
	return p->object;
}

int getListLength(List *list){
	int count = 0;
	for(List *p = list->next;p->next!=NULL;p=p->next){
		count++;
	}
	return count;
}

List * freeList(List *list){
	int size = getListLength(list);
	List *p;
	for (int i = 1; i<size;i++){
		p = list;
		list = list->next;
		free(p);
	}
	return list;
}