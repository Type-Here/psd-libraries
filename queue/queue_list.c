#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../item/item.h"
#include "../list/list.h"
#include "queue.h"

/* Coda struttura di tipo FIFO
 * First In First Out: Aggiunta in Coda, Rimozione in Testa. // Come la coda alle Poste
 * Implementazione con Liste
 */

/* -- DEFINIZIONE STRUTTURE -- */
struct queue {
    List list;
};


/* --Creazione Coda-- */
Queue newQueue(){
    Queue q = malloc(sizeof(struct queue));
    q->list = newList();
    return q;
} 

/* -- Gestione Coda -- */

/*- Controlla se Coda Vuota: 1 vuota, 0 non vuota -*/
int isEmptyQueue(Queue q){
    return isEmptyList(q->list);
} 

/*- Accodamento e Rimozione da Coda -*/

/*- Accoda, Ritorna 1 se successo -*/
int enqueue(Queue q, Item el){
    return addListTail(q->list, el);
}

/*Rimuove in Testa, Ritorna l'Item rimosso o NULL in caso di coda vuota o errore*/
Item dequeue(Queue q){
    return removeHead(q->list); //removeHead già gestisce i casi per la lista
}

/* - Ritorna elemento in Testa, senza rimuoverlo, NULL se vuota - */
Item head(Queue q){
    return getHead(q->list);
}

/*OutPut Coda*/
void printQueue(Queue q){
    printList(q->list);
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
/*Un altro metodo sarebbe sfruttare il Reverse List*/


/*Free*/
void freeQueue(Queue q){
    freeList(q->list);
    free(q);
}