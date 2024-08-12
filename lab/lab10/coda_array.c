#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "coda.h"

#define MAXQUEUE 50

/*-- STRUCT CODA --*/
struct queue{
	int head;
    int tail;
    Item *arr;
};

/*Funzioni Interne Ricorsive*/
void reverseCoda_internal(Coda s, int t, int d);

/*-- Operazioni ADT--*/

Coda nuovaCoda(){
    Coda s = malloc(sizeof(struct queue));
		if(s == NULL) return NULL;
	s->arr = malloc(MAXQUEUE * sizeof(Item));
		if(s->arr == NULL) return NULL;
    s->head=0;
	s->tail=0;
    return s;
} 

int isEmptyCoda(Coda s){
    if(s->head == s->tail)
        return 1;
    else    
        return 0;
}

int accoda(Coda s, Item el){
    if((s->tail + 1) % MAXQUEUE == s->head)
        return 0;
    else{
        s->arr[s->tail] = el;
        s->tail=(s->tail + 1) % MAXQUEUE;
        return 1;
    }
}

Item rimuovi(Coda s){
    if(isEmptyCoda(s))
        return NULL;
    else{
		Item a = s->arr[s->head];
        s->head = (s->head + 1) % MAXQUEUE;
        return a;
    }
}

Item head(Coda s){
    if(isEmptyCoda(s))
        return NULL;
    else
        return s->arr[(s->head)];
}

void printCoda(Coda s){
    int i = s->head;
    while(i != s->tail){
		outputItem(s->arr[i]);
		i = (i + 1) % MAXQUEUE;
	}
        
}

void reverseCoda_rec(Coda s){ // T(n) = O(n);
	reverseCoda_internal(s, s->head, s->tail-1);
}

void reverseCoda_internal(Coda s, int t, int d){ // T(n) = O(n);
	if(t == d) return;
	else if ((t+1) % MAXQUEUE == d){
		Item temp = s->arr[t];
		s->arr[t] = s->arr[d];
		s->arr[d] = temp;
		return;
	}
	else {
		Item temp = s->arr[t];
		s->arr[t] = s->arr[d];
		s->arr[d] = temp;
		reverseCoda_internal(s, (t+1) % MAXQUEUE, (d-1) % MAXQUEUE);	
	}
}

void freeQueue(Coda s){
	//s->head = 0;
	//s->tail = 0;
	do{
		Item a = rimuovi(s);
		free(a);
	}while(!isEmptyCoda(s));
	free(s->arr);
	free(s);
}