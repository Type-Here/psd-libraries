#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "coda.h"

#define MAXQUEUE 50

struct queue{
	int head;
    int tail;
    Item arr[MAXQUEUE];
};

Coda nuovaCoda(){
    Coda s = malloc(sizeof(struct queue));
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
