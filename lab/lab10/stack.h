#include "item.h"

typedef struct stack *Stack;

Stack newStack(); 

int isEmptyStack(Stack); 

int push(Stack, Item);

Item pop(Stack);

Item top(Stack);

void printStack(Stack);

int stackDim(Stack);

void freeStack(Stack s);