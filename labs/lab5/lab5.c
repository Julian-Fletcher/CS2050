#include "lab5.h"

//Initializes the provided pointer to an empty list (NULL). ALways returns 0
int makeList(Node **list){
	*list = NULL;
	return 0;
}

//Returns the number of elements in a provided list. Will return 0 if the list is empty
int getSize(Node *list){
	if(list){
		int size = 1;
		for(Node *p = list;p->next!=NULL;p=p->next){			//this loops through the list to determine its size
			size++;
		}
		return size;
	}
	else{
		return 0;
	}
}

//Takes a pointer to Node *, and inserts the given data at the end of the list. Returns 0 on success, one on failure
int insertAtTail(Node **list, void *data){
	int ec;
	//if the list is empty, a new node will simply be created and added
	if(*list==NULL){					
		Node *new =malloc(sizeof(Node));
		//the following puts the node into the list and puts the provided data into the node
		if(new){						
			new->next = NULL;
			new->data = data;
			*list = new;
			ec = 0;
		}
		else{
			ec = 1;
		}
	}
	//if the list is not empty, a node will be created and added to the end
	else{
		//creates a second pointer to the list in order to find the end of the list
		Node *p = *list;
		while(p->next!=NULL){
			p=p->next;
		}
		//the following puts the node into the list and puts the provided data into the node
		Node *new = malloc(sizeof(Node));
		if(new){
			p->next = new;
			new->next = NULL;
			new->data = data;
			ec = 0;
		}
		else{
			ec = 1;
		}
	}
	return ec;	
}

//This function removes the node at the head of the list. It will return any data which was removed from the list, or NULL if the list was empty.
void * removeFromHead(Node **list){
	if(*list){			//checks that the list is not empty
	//the following moves the head of the list forward by one node and returns the data in the node that waas removed, it also frees the node
		Node *head = *list;
		*list=(*list)->next;
		//the following stores the data from the removed node, then  frees the node and returns the data
		void * rmData = head->data;	
		free(head);						
		return rmData;
	}
	else{
		return NULL;
	}
}

//Frees the provided list and sets the pointer to NULL
void freeList(Node **list){
	//first checks if the list is already empty
	if(*list){
		Node *p = *list;
		//the following increments through the list, moving the list pointer forward by one node, and freeingt the previous node with the second pointer. The last node will be freed after the loops' conlusion
		while((*list)->next!=NULL){
			p = *list;
			*list=(*list)->next;
			free(p);
		}
		free(*list);
		*list = NULL;
	}
}