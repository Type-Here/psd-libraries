#include "../item/item.h"

/*Dichiarazione Puntatore Stack*/
typedef struct stack *Stack;

Stack newStack(); 

int isEmptyStack(Stack); 
int stackDim(Stack);

/*Gestione Stack*/
int push(Stack, Item); //aggiungi in testa
Item pop(Stack); //rimuovi in testa, ritorna item o NULL
Item top(Stack); //ritorna l'item, non modifica la stack

/*Stampa*/
void printStack(Stack);

/*Free*/
void freeStack(Stack);