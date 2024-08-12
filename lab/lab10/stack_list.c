#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "stack.h"
#include "list.h"

struct stack{
    List l;
};

Stack newStack(){
    Stack s = malloc(sizeof(struct stack));
    s->l = newList();
    return s;
}

int isEmptyStack(Stack s){
    return isEmpty(s->l);
}

int push(Stack s, Item el){
    addHead(s->l, el);
    return 1;
}

Item pop(Stack s){
    /*if(removeHead(s->l) == NULL)
        return NULL;
    //return 1;*/
    return removeHead(s->l);
}

Item top(Stack s){
    return getHead(s->l);
}

void printStack(Stack s){
    printList(s->l);
}

int stackDim(Stack s){
	sizeList(s->l);
}

void freeStack(Stack s){
	destroyListRec(s->l);
	free(s);
}