#include <stdio.h>
#include <stdlib.h>

#include "coda.h"
#include "item.h"

/*-- ESERCIZIO LAB 8 REVERSE RICORSIVO DI CODA --
 * Funzionante su Code di Array e Code di Liste
 * Testato su Item Int come da traccia */

int main(){

	Coda s = nuovaCoda();
	Item el;
	int i;

	for(i=0; i<5; i++){
		printf("\nAccoda elemento: ");
		el = inputItem();
		accoda(s, el);
	}
	printf("\nCoda: ");
	printCoda(s);
	printf("\n");
	
	/*Funzione ricorsiva che percorre tutta la lista una volta e la capovolge: T(n) = O(n).
	Effettua n/2 scambi e n/2 iterazioni ~ O(n)*/
	
	/* Con migliore precisione:
	 * - Lavoro di combinazione costante.
	 * - Senza partizione dei dati.
	 * - Singola chiamata ricorsiva.
	 * T(n) = Lineare con n. ( O(n) ).
	 * Valido sia per reverse array che reverse list (numero di operazioni comparabili).
	 */
	reverseCoda_rec(s);
	printf("\nCoda invertita:\n");
	printCoda(s);
	
	printf("\nArrivederci.\n");
	
	freeQueue(s);
	//free(el);
	
}