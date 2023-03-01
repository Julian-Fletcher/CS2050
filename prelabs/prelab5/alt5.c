#include "prelab5.h"

List * initList(int *error){
	List *list;
	list = NULL;
	return list;
}

List * insertAtHead(int object, List* list, int* ec){
	List *p = malloc(sizeof(list));
	if (p){
		p->object = object;
		p->next=list;
		list = p;
		return list;
		*ec = 0;
	}
	else{
		*ec = 1;
	}
	return list;
}


int getAtIndex(int pos, List* list){
	List *p = list;
	for(int i = 1; i!=pos;i++){
		if(p->next!=NULL){
			p=p->next;
		}
		else{
			return -10000;
			break;
		}
	}
	return p->object;
}

int getListLength(List *list){
	int count = 1;
	for(List *p = list;p->next!=NULL;p=p->next){
		count++;
	}
	return count;
}

List * freeList(List *list){
	List *p = list;
	while(list->next!=NULL){
		p = list;
		list=list->next;
		free(p);
	}
	free(list);
	return NULL;	
}