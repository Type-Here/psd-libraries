#include "item.h"

typedef struct queue * Coda;

Coda newQueue();

int isEmptyQueue(Coda);

int enqueue(Coda c, Item el);

Item dequeue(Coda c);

void printQueue(Coda c);