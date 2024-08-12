#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "coda.h"
#include "list.h"

struct queue{
    List l;
	//int numelem;
};

Coda nuovaCoda(){
    Coda s = malloc(sizeof(struct queue));
    s->l = newList();
    return s;
}

int isEmptyCoda(Coda s){
    return isEmpty(s->l);
}

int accoda(Coda s, Item el){
    return addListTail(s->l, el);
	//(s->numelem)++;
    //return 1;
}

Item rimuovi(Coda s){
    /*if(removeHead(s->l) == NULL)
        return 0;
	//(s->numelem)--;
    return 1;
    //return removeHead(s->l) != NULL;*/
	return removeHead(s->l);
}

Item head(Coda s){
    return getHead(s->l);
}

void printCoda(Coda s){
    printList(s->l);
}