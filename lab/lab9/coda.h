#include "item.h"

typedef struct queue *Coda;

Coda nuovaCoda(); 

int isEmptyCoda(Coda); 

int accoda(Coda, Item);

Item rimuovi(Coda);

//Item top(Coda);

void printCoda(Coda);

void reverseCoda_rec(Coda);

void freeQueue(Coda);