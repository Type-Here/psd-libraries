#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "stack.h"

#define START_DIM 10
#define ADD_DIM 5

struct stack{
    int top;
	int dim;
    Item *arr;
};

Stack newStack(){
    Stack s = malloc(sizeof(struct stack));
		if(s==NULL){return NULL;}
	
	s->arr = malloc(sizeof(Item)*START_DIM);
		if(s->arr == NULL) return NULL;
    s->top=0;
	s->dim = START_DIM;
    return s;
} 

int isEmptyStack(Stack s){
    if(s->top == 0)
        return 1;
    else    
        return 0;
}

int push(Stack s, Item el){
	Item *temp;
    if(s->top == s->dim){
		temp = realloc(s->arr, sizeof(Item)*(s->dim + ADD_DIM));
		if(temp == NULL){return 0;}
		else{
			s->arr = temp;
			s->dim += ADD_DIM;
			printf("\nDimensione Estesa a %d\n", s->dim);
		}
	}
	s->arr[s->top] = el;
	(s->top)++;
	return 1;
    }

Item pop(Stack s){ 
    if(isEmptyStack(s))
        return NULL;
    else{
		Item temp = s->arr[s->top-1];
        (s->top)--;
        return temp;
    }
}

Item top(Stack s){
    if(isEmptyStack(s))
        return NULL;
    else
        return s->arr[(s->top)-1];
}

void printStack(Stack s){
    int i;
    for(i=s->top-1; i>=0; i--)
        outputItem(s->arr[i]);
}

int stackDim(Stack s){
	return s->top;
}

void freeStack(Stack s){
	s->top = 0;
	free(s->arr);
	free(s);
}