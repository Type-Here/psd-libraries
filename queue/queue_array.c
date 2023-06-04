#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../item/item.h"
#include "../list/list.h"
#include "queue.h"

#define MAXQUEUE 50

/* Coda struttura di tipo FIFO
 * First In First Out: Aggiunta in Coda, Rimozione in Testa. // Come la coda alle Poste
 * Implementazione con Array, Coda Circolare.
 */

/* -- DEFINIZIONE STRUTTURE -- */
struct queue {
    Item *arr;
    int head;
    int tail;
};

    /* - Creazione Coda - */
Queue newQueue(){
    Queue q = malloc(sizeof(struct queue));
        if(!q) {fprintf(stderr, "Memoria non allocata da %s", __func__); return NULL;}
    q->arr = malloc(sizeof(Item) * MAXQUEUE);
        if(!q->arr) {fprintf(stderr, "Memoria non allocata da %s", __func__); return NULL;}
    q->head = 0;
    q->tail = 0;
    return q;
} 

    /*-- Gestione Coda -- */

/*Ritorna 1 vuota, 0 non vuota*/
int isEmptyQueue(Queue q){
    if(q->head == q->tail) return 1; //In array circolare unico caso in cui è vuoto è quanto head e tail sono uguali
    return 0;
}

/*Aggiungi in Coda ad Array, Ritorna 1 quando successo*/
int enqueue(Queue q, Item el){
    /* Modo per controllare se coda piena, tail+1 mod dimensione = testa; 
     * perché la coda potrebbe essere immediatamente dietro a testa*/
    if((q->tail + 1) % MAXQUEUE == q->head) {
            printf("\nCoda Piena.\n");
            return 0;
        }
    q->arr[q->tail] = el;
    q->tail = (q->tail + 1) % MAXQUEUE; // Per gestire la coda circolare la coda potrebbe trovarsi in posizione 0, 1 
                                        // o comunque a sinistra della testa nell'array!
    return 1; 
}

/*Rimuovi in Testa, Ritorna l'Item Rimosso o NULL se vuoto*/
Item dequeue(Queue q){
    if(isEmptyQueue(q)) return NULL;
    Item a = q->arr[q->head];
    q->head = (q->head + 1) % MAXQUEUE; //Vale discorso simile per enqueue
    return a;
}


/*Ritorna L'Item in testa o NULL, senza modificare la testa*/
Item head(Queue q){
    if(isEmptyQueue(q)) return NULL;
    return q->arr[q->head];
}


/* - OutPut Coda - */
void printQueue(Queue q){
    int i;
    for(i = q->head; i != q->tail; i = (i + 1) % MAXQUEUE){
        outputItem(q->arr[i]);
    } 
}



    /* -- FUNZIONI AGGIUNTIVE -- */

/*-- Funzioni Ricorsive --*/

/* Reverse Coda Ricorsivo, struttiamo le chiamate ricorsive 
 * come stack per invertire il contenuto della coda */
void reverseQueueRecursive(Queue q){
    if(isEmptyQueue(q)) return;
    Item el = dequeue(q);
    reverseQueueRecursive(q);
    enqueue(q, el);
}


/*------------------------------------------------*/
/*Altro Metodo più Lungo ma simile all'originale*/
/*Non Rilasciato al di fuori del modulo*/
void reverseCoda_rec(Queue s){ // T(n) = O(n);
	reverseCoda_internal(s, s->head, s->tail-1);
}

void reverseCoda_internal(Queue s, int t, int d){ // T(n) = O(n);
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
/*-- Fine Metodo Alternativo -------------------------*/




    /* -- Free -- */
void freeQueue(Queue q){
    while(!isEmptyQueue(q)){
        free(dequeue(q));
    }
    free(q->arr);
    free(q);
}