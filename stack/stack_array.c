#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../item/item.h"
#include "../list/list.h"
#include "stack.h"

#define START_DIM 10
#define ADD_DIM 5

/* Stack struttura di tipo LIFO
 * Last In First Out: Aggiunta in Testa, Rimozione in Testa.
 * Implementazione con Array
 */

/* -- DEFINIZIONE STRUTTURE -- */
struct stack {
   Item *arr;
   int top; // è l'indice del primo spazio vuoto!
   int dim; //dimensione massima momentanea, non dimensione occupata!
};


/*- Crea Nuova Stack allocandone la memoria e alloca il suo array a dim START_DIM*/
Stack newStack(){
    Stack s = malloc(sizeof(struct stack));
        if(!s) {fprintf(stderr, "\nMemoria non allocata da %s\n", __func__); return NULL;}
    s->arr = malloc(sizeof(Item)*START_DIM);
        if(!(s->arr)) {fprintf(stderr, "\nMemoria non allocata da %s\n", __func__); return NULL;}
    s->top = 0;
    s->dim = START_DIM;

    return s;
}

/*Ritorna 1 se vuoto, 0 altrimenti*/
int isEmptyStack(Stack s){
    if(s->top == 0) return 1;
    return 0;
}

int stackDim(Stack s){
    return s->top;
}

/*Gestione Stack*/

//aggiungi in testa
int push(Stack s, Item el){
    if(s->top == s->dim){
        Item * redim = realloc(s->arr, sizeof(Item) * (s->dim + ADD_DIM));
            if(!redim){fprintf(stderr, "\nRealloc non effettuata da %s\n", __func__); return -1;}
        s->arr = redim;
        s->dim += ADD_DIM;
    }
    s->arr[s->top] = el;
    ++(s->top);
    return 1;
}

//rimuovi in testa, ritorna item o NULL
Item pop(Stack s){
    if(isEmptyStack(s)) return NULL;
    Item el = s->arr[(s->top)-1];
    (s->top)--;
    return el;
}

//ritorna l'item, non modifica la stack
Item top(Stack s){
    if(isEmptyStack(s)) return NULL;
    return s->arr[(s->top)-1];
}

/*Stampa*/
void printStack(Stack s){
    int i;
    for(i = (s->top)-1; i >= 0; i--){
        outputItem(s->arr[i]);
    }
}

/* -- Free -- */
void freeStack(Stack s){
    s->top = 0;
    free(s->arr);
    free(s);
}
