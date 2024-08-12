#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "playlist.h"
#include "song.h"


int main(){
	List list = newList();
	int i;
	Item el;
	Item removedItem;
	
	for (i = 0; i < 5; i++){
		el = inputItem();
		addHead(list, el);
	}
	
	removedItem = removeHead(list);
	printf("Elemento rimosso: ");
	outputItem(removedItem);

	printf("\nLista ora è: ");
	printList(list);
	printf("\n");
	
	int menu = 0;
	do {
	switch(menu){
		case 0:
			printf("\n1. Cerca elemento.\n");
			printf("2. Elimina per elemento.\n");
			printf("3. Elimina per posizione.\n");
			printf("4. Ordina con SelectionSort\n");
			printf("9. Per uscire\n");
			printf("0. Stampa questo menu\n\n");
		break;
		
		case 1:
			printf("Elemento da cercare: ");
			Item search = inputItem();
			int pos = 0;
			Item position_item=searchListItem(list, search, &pos);
			
			if(pos == -1){
				printf("Item non trovato\n");
			} else {
				printf("\nElemento trovato in posizione %d .\n", pos);
				outputItem(position_item);
			}
		break;
		
		case 2:
			printf("\nElemento da eliminare: ");
			Item it_elim = inputItem();
			Item elem_removed = removeListItem(list, it_elim);
			if(elem_removed == NULL){
				printf("\nElemento non trovato\n");
			} else {
				printf("\nElemento rimosso :");
				outputItem(elem_removed);
				printf("\n");
				printList(list);
			}
		break;
		
		case 3:
			printf("\nElemento da eliminare per posizione: ");
			int posizione;
			scanf("%d", &posizione);
			Item elem_removed_pos = removeListPos(list, posizione);
			if(elem_removed_pos == NULL){
				printf("\nElemento non trovato\n");
			} else {
				printf("\nElemento rimosso :");
				outputItem(elem_removed_pos);
				printf("\n");
				printList(list);
			}
		break;
		
		case 4:
			selectionSortList(list);
			printf("Lista ordinata :");
			printList(list);
			printf("\n");
		break;

		}
	printf("\nCosa vuoi fare? 9 per uscire. \n");
	scanf(" %d", &menu);
	getchar();	
	} while(menu != 9);
		
	return 0;
}