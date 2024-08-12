#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#include "utils.h"
#include "item.h"
#include "vettore.h"

#define MAX 6

/* -- ESERCIZIO LAB N°8 --
 * Selection Sort Ricorsivo su Array di Item.
 * vettore.c non alla versione più recente 
 * ma le funzioni swap e minimo per Item sono state riscritte in fondo al file 
 * così come la funzione ricorsiva.
*/

void print_it(Item *a, int n){
		int i;
		printf("\nArray: ");
		for(i=0; i<n; i++){
		outputItem(a[i]);
	}
}

int main(){
	Item arr[MAX];
	Item el;
	int i;
	for(i=0; i < MAX; i++){
		printf("\nInserisci elemento: ");
		el = inputItem();
		arr[i] = el;
	}
	
	print_it(arr, MAX);
	
	selection_sort_rec(arr,MAX); /*T(n) = O(n^2) = Omega(n^2)*/
	
	/* Con migliore precisione:
	* - Lavoro di combinazione lineare: chiamata ogni ricorsione della funzione min_item (complessità O(n) per la singola chiamata)
	* - Ricorsione senza partizione dei dati.
	* - Singola chiamata ricorsiva.
	* T(n) = Quadratico con n ( O(n^2) ).
	*/
	
	printf("\nArray Ordinato: ");
	print_it(arr, MAX);
	printf("\nOperazione Conclusa. \n");
	
	for(i=0; i < MAX; i++){
		free(arr[i]);
	}
}