#include <stdlib.h>
#include "stack.h"
#include "queue-stack.h"

struct queue {
    Stack t;
    Stack h;
};

Coda newQueue(){
    Coda c = malloc(sizeof(struct queue));
    c->t = newStack();
    c->h = newStack();
    return c;
}

int isEmptyQueue(Coda s){
    return isEmptyStack(s->h) && isEmptyStack(s->t);
}

int enqueue(Coda c, Item el){
     while(!isEmptyStack(c->t)){
        push(c->h, pop(c->t));
     }
     push(c->h, el);

}

Item dequeue(Coda c){
    while(!isEmptyStack(c->h)){
        push(c->t, pop(c->h));
     }
     return pop(c->t);
}

void printQueue(Coda c){
    if(isEmptyStack(c->t)){
        while(!isEmptyStack(c->h)){
            push(c->t, pop(c->h));
        }
    }
    printStack(c->t);
}

