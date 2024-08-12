/* ESERCIZIO LABORATORIO 6: PARENTESI BILANCIATE DI UNA ESPRESSIONE */
/* --- Uso dello stack --- */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"
#include "list.h"
#include "item.h"
#include "vettore.h"

#define BUFFER 50

int main (){
	List l = newList();
	Item el, search, found;
	int i;
	int ricorrenze, pos = 0;
	

	for(i=0; i<5; i++){
		printf("\nInserisci elemento: ");
		el = inputItem();
		addHead(l, el);
	}
	printf("\nPrintList Iterative: ");
	printList(l);
	printf("\n\n");
	
	printf("Stampiamo adesso con la funzione ricorsiva:\nPrintList Rec: ");
	printListRec(l);
	
	printf("\n\nCerca un elemento in Lista (search recursive): ");
	search = inputItem();
	
	found = searchListRec(l, search, &pos);
	
	if(found != NULL) {
		printf("Item found in pos %d\n Elemento: ", pos);
		outputItem(found);
	} else {
		printf("Item not found.\n");
	}	
	printf("\n\n");
	printf("Adesso stampiamo le ricorrenze di questo Item: %d", countItemListRec(l, search)); 
	
	destroyListRec(l);
	free(search);
	
	return 0;
	
}