#include <stdio.h>
#include <stdlib.h>
#include "queue-stack.h"
#include "item.h"

int main(){

	Coda c = newQueue();
	int i;
	printf("\nInserisci 5 el: \n");
	for(i = 0; i < 5; i++){
		enqueue(c, inputItem());
	}
	printf("\nCoda: ");
	printQueue(c);
	for(i = 0; i < 6; i++){
		if(!isEmptyQueue(c)){
			printf("\n\nElemento rimosso: ");
			Item removed = dequeue(c);
			outputItem(removed);
			free(removed);
			printf("\nCoda Rimasta: ");
			printQueue(c);
		} else {
			printf("\nCoda Vuota.\n");
		}
	}
	
	printf("\nEnd.\n");


	return 0;
}