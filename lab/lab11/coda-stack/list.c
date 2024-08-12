#include "list.h"
#include "item.h"
#include <stdlib.h>
#include <stdio.h>

/*-- ADT --*/

struct list{
    int size;
    struct node *head;
	struct node *tail;
	//int numelem;
};

struct node{
    Item value;
    struct node *next;
};

/* Funzioni Locali per ricorsività */
int countItemListRec_Node(struct node *, Item); 
Item searchListRec_Node(struct node *, Item item, int *);
void revList_internal(List l, struct node *, struct node *); //Funzione interna di reverselist_rec


/*--- IMPLEMENTAZIONE FUNZIONI ---*/

List newList(){
	List list = malloc(sizeof(struct list));
	list -> size = 0;
	list -> head = NULL;
	list -> tail = NULL;
	return list;	
}

int isEmpty(List list){
	if (list -> size == 0) 
		return 1;

	return 0;	
}

void addHead(List list, Item el){

	struct node *newHead = malloc(sizeof(struct node));

	newHead -> value = el;
	newHead -> next = list -> head;

	list -> head = newHead;
	

	(list -> size)++;
}

Item removeHead(List list){

	if (isEmpty(list)) return NULL;

	struct node *temp = list -> head;
	list -> head = temp -> next;

	Item el = temp -> value;
	free(temp);

	(list -> size)--;
	
	if (isEmpty(list)){
		list->tail = NULL;
	}

	return el;
}

Item getHead(List list){

	if (isEmpty(list)) return NULL;

	return list -> head -> value;
}

int sizeList(List list){
	return list -> size;	
}

void printList(List list){

	struct node *p;
	for (p = list -> head; p != NULL; p = p -> next){
		outputItem(p -> value);
	}	
}

Item searchListItem(List l, Item q, int *pos)
{
	struct node *p;
	*pos = 0;
	for (p = l -> head; p != NULL; p = p -> next, (*pos)++){
		if (cmpItem(q, p->value) == 0)
		{
			return p->value;
		}
	}
	*pos = -1;
	return NULL;
}

Item removeListItem(List l, Item q)
{
	struct node *prev, *p;
	Item val;
	if (isEmpty(l))
		return NULL;
	for (p = l -> head; p != NULL; prev = p, p = p -> next){
		if (cmpItem(q, p->value) == 0)
		{
			if (p == l->head)
				return removeHead(l);
			else	//si può anche evitare
			{
				prev->next = p->next;
				val = p->value;	//assegno il valore precedente dell'item
				(l->size)--;	//decremento taglia lista
				free(p);		//libero memoria p
				return val;		//ritorno l'item
			}
		}
	}
	return NULL;	//caso in cui non è stato trovato
}

Item removeListPos(List l, int pos)
{
	struct node *prev, *p;
	Item val;
	int i;
	if (isEmpty(l) || pos < 0 || pos >= l->size)	//controllo precondizione
		return NULL;
	for (i = 0, p = l -> head; p != NULL; prev = p, p = p -> next, i++){
		if (i == pos)
		{
			if (p == l->head)
				return removeHead(l);
			else	//si può anche evitare
			{
				prev->next = p->next;
				val = p->value;	//assegno il valore precedente dell'item
				(l->size)--;	//decremento taglia lista
				free(p);		//libero memoria p
				return val;		//ritorno l'item
			}
		}
	}
	return NULL;
}

int addListPos(List list, Item el, int pos){
    struct node *p, *newNode;
    int i;

    if(pos<0 || pos>list->size){
        return 0;
    }
    if(pos==0){
        addHead(list, el);
        return 1;
    }
    for(i=0, p=list->head; i<pos-1; p=p->next, i++);
        
    newNode=malloc(sizeof(struct node));
    newNode->next=p->next;
    newNode->value=el;
    p->next=newNode;

    (list->size)++;
    return 1;
}

int addListTail(List list, Item el){
	struct node *p, *newNode;
	
	newNode=malloc(sizeof(struct node));
	newNode->value=el;
	
	if (isEmpty(list)){
		list->head = newNode;	
	} else {
		p = list->tail;
		newNode->next=NULL;
		p->next=newNode;	
	}
	
	list->tail = newNode;
	(list->size)++;
	//printf("\n\tHead %s", list->head->value);
	//printf("\n\tTail %s\n", list->tail->value);
	//printf("\n\t headnext value = %s\n", list->head->next->value);
	return 1;

}

void reverseList(List list){
    struct node *prev=NULL, *p, *temp;

    for(p=list->head; p!=NULL; prev=p, p=temp){
        temp=p->next;
        p->next=prev;
    }
    list->head=prev;
}

List cloneList(List list){
    List l2=newList();
    struct node *p;

    for(p=list->head; p!=NULL; p=p->next){
        addListTail(l2, p->value);
    }
    return l2;
}



/*--- FUNZIONI RICORSIVE ---*/

void printListRec(List list){
	//if(isEmpty(list)) return;
	outputItem(list->head->value);
	struct list l_temp;
	l_temp.head = list->head->next;
	if(l_temp.head == NULL) return;
	else{
		printListRec(&l_temp);
	}	
}


Item searchListRec_Node(struct node * p, Item item, int *pos){
	++(*pos);
	if(p == NULL){(*pos)= -1; return NULL;}
	else if(cmpItem(p->value, item) == 0){
		return p->value;
	}else{
		return searchListRec_Node(p->next, item, pos);
	}

}

Item searchListRec(List list, Item item, int* pos){ //pos da 0 a size-1
	if(isEmpty(list)){ *pos= -1; return NULL;}
	*pos = 0;
	return searchListRec_Node(list->head, item, pos);
}


int countItemListRec_Node(struct node *p, Item item){
	int count = 0;
	if(p == NULL) return 0;
	if(cmpItem(p->value, item) == 0) {count++;}
	return countItemListRec_Node(p->next, item) + count;
	
}

int countItemListRec(List list, Item item){
	if(isEmpty(list)) return -1;
	return countItemListRec_Node(list->head,item);
}


void destroyListRec(List l){
	if(isEmpty(l)){ 
		free(l);
		return;
	}
	free(removeHead(l));
	destroyListRec(l);
}


/*-- LAB 8 ---*/

void reverselist_rec(List l){ // La funzione in sé fa solo due operazioni, la sua complessità dipende dalla funzione interna chiamata ( O(n) ).
	struct node *temp = l->head;
	struct node *prev = NULL;
	l->tail = temp;
	revList_internal(l, prev, temp);
	
}

void revList_internal(List l, struct node *prev, struct node *temp){  //Funzione interna di reverselist_rec
	if(temp == NULL){
		l->head = prev;
	} else {
		struct node *follow = temp->next;
		temp->next = prev;
		revList_internal(l, temp, follow);
	}
}
/*Funzione ricorsiva che percorre tutta la lista una volta e la capovolge: T(n) = O(n).*/