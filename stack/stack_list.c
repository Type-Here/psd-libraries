#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../item/item.h"
#include "../list/list.h"
#include "stack.h"

/* Stack struttura di tipo LIFO
 * Last In First Out: Aggiunta in Testa, Rimozione in Testa.
 * Implementazione con Liste
 */

/* -- DEFINIZIONE STRUTTURE -- */
struct stack {
    List list;
};

/*- Crea Nuova Stack allocandone la memoria e alloca la sua lista*/
Stack newStack(){
    Stack s = malloc(sizeof(struct stack));
        if(!s) {fprintf(stderr, "\nMemoria non allocata da %s\n", __func__); return NULL;}
    s->list = newList();
    return s;
} 

/*Ritorna isEmptyList: 1 vuota, 0 no*/
int isEmptyStack(Stack s){
    return isEmptyList(s->list);
} 

/*Aggiunge a Testa*/
int push(Stack s, Item el){
    addHead(s->list, el);
    return 1;
}

/*Rimuove dalla testa, Ritorna l'item del nodo rimosso*/
Item pop(Stack s){
    return removeHead(s->list); //controllo se lista non vuota implementata in removeHead
}

/*Ottieni l'Item in Testa, non modifica la testa; NULL se vuota*/
Item top(Stack s){
    return getHead(s->list); //controllo se lista non vuota implementata getHead
}

void printStack(Stack s){
    printList(s->list);
}

int stackDim(Stack s){
    return sizeList(s->list);
}

void freeStack(Stack s){
    while(!isEmptyList(s->list)){
        free(removeHead(s->list));
    }
    free(s);
}