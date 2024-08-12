#include "item.h"
#include <stdlib.h>
#include "lista.h"

struct list{
	int size;
	struct node *head;
};

struct node{
	Item value;        /*datastoredinthenode */
	struct node *next; /*pointertothenextnode*/
};



List newList(){
	List list= malloc(sizeof(struct list));
	list->size = 0;
	list->head = NULL;
	return list;
}


int isEmpty(List list){
	if (list->size == 0) 
		return 1;

	return 0;	
}


void addHead(List list, Item el){
	struct node *new_head;
	new_head = malloc(sizeof(struct node));
	new_head->value = el;
	new_head->next = list -> head;
	
	list->head = new_head;
	(list->size)++;
}

Item removeHead(List list){
	if (isEmpty(list)) return NULL;
	
	struct node *temp = list->head;
	
	list->head = temp->next;
	
	Item el = temp->value;
	free(temp);
	
	(list->size)--;

	return el;
}

Item getHead(List list){
	if (isEmpty(list)) return NULL;
	return (list->head)->value;
}

int sizeList(List list){
	return list->size;	
}


void printList(List l){
	struct node *p;
	for(p = l->head; p != NULL; p = p->next){
		outputItem(p->value);
	}	
}


Item searchListItem(List list, Item item, int *pos){
	if (isEmpty(list)) return NULL;
	struct node *temp = list->head;
	*pos = 0;
	while(temp->next != NULL){
		if(cmpItem(temp->value, item) == 0){
			return temp->value; 
		}
		(*pos)++;
		temp=temp->next;
	}
	*pos=-1;
	return NULL;
}

Item removeListItem(List list, Item item){ //Rimuove Item cercando un Item
	if (isEmpty(list)) return NULL;
	struct node *temp = list->head;
	struct node *prev = list->head;
	Item el;
	
	while(temp->next != NULL){
		prev = temp;
		temp=temp->next;
		if(cmpItem(temp->value, item) == 0){
			if(temp == list->head){
				return removeHead(list);
			} else {
				prev->next = temp->next;
				el = temp->value;
				free(temp);
				(list->size)--;
				return el;
			}
		}
	}
	return NULL;
}


Item removeListPos(List list, int pos){  //Rimuove un Item per posizione
	if (isEmpty(list)) return NULL;
	struct node *temp = list->head;
	struct node *prev = list->head;
	Item el;
	int counter = 0;
	while(counter < list->size){
		if(pos < 0 || pos >= list->size){
			return NULL;
		} else if(pos == 0){
			return removeHead(list);
		} else if(pos == counter){
			prev->next = temp->next;
			el = temp->value;
			free(temp);
			(list->size)--;
			return el;
		}
	prev = temp;
	temp=temp->next;	
	counter++;
	}

	return NULL;
}


/*Sort List*/
void selectionSortList(List list){
	int *arr[list->size];
	int i = 0;
	struct node *temp = list->head;
	struct node *mintemp = list->head;
	struct node *ordina = list->head;
	
	struct node salv_temp;
	
	for(i=0; i<list->size;i++){
		temp = ordina;
		mintemp = ordina;
		int k = i;
		while(temp->next != NULL){
			temp=temp->next;
			if(cmpItem(mintemp->value, temp->value) > 0){
				mintemp = temp;
			}	
		}
		salv_temp = *ordina;
		ordina->value = mintemp->value;
		mintemp->value = salv_temp.value;
		
		ordina = ordina->next;	
	}
}

/**
Item minimoItem(){
	
}*/