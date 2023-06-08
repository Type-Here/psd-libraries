#include "../item/item.h"

/*Definizione Puntatore a Struttura queue*/
typedef struct queue *Queue;

/*Creazione Coda*/

Queue newQueue(); 

/*Gestione Coda*/

int isEmptyQueue(Queue); 
int enqueue(Queue, Item);
Item dequeue(Queue);

//Item top(Queue);
/*OutPut Coda*/
void printQueue(Queue);

/*Funzioni Ricorsive*/
void reverseQueueRecursive(Queue);

/*Free*/
void freeQueue(Queue);