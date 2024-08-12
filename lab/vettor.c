// Modulo Vettore:
// IMPLEMENTAZIONE

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "my_utils.h" // contiene funzione scambia



int minimo_int(int a[], int i, int n); // dichiarazione locale

int inserisci(int a[], int val, int n); //inserisci: funzione di insertion_sort


/*---------- INPUT e OUTPUT ARRAY --------*/
/*Popola Array con Input Utente*/
void input_array(int a[], int n) {
	printf("Inserisci gli elementi nel tuo array, hai %d elementi \n", n);
	int i;
	for(i=0; i<n; i++){
		printf("Inserisci Cifra: ");
		scanf( "%d", &a[i]);	
	}
}

/*Stampa Array*/
void output_array(int a[], int n) {
	printf("Ecco il tuo Array: \n");
	int i;
	for(i=0; i<n; i++){
		printf("%d ", a[i]);
	}
}

/*--------- RICERCHE IN ARRAY ----------*/

/*Cerca Elemento in Array*/
int ricerca_array(int a[], int n, int elem){
	int i; 
	int k = 0;
	for(i=0; i<n; i++){
		if(elem == a[i]){
			k++;
			printf("%d trovato in array in posizione %d \n",elem,i);			
		}
	}
	if(!k){
		printf("%d non presente in tuo array \n", elem);
	} else {
		printf("%d ha %d ricorrenze \n", elem, k);
	}
	return k;
}

/*Cerca Massimo e Minimo*/

/*Massimo*/
int massimo_array(int a[], int n){
	int i;
	int max = 0;
	for(i=1;i<n;i++){
		if(a[max] < a[i]){
			max = i;
		}
	}
	return max;
}

/*Minimo*/  /*T(n) = O(n) Omega(n)*/
int minimo_array(int a[], int n){
	int i;
	int min = 0;
	for(i=1;i<n;i++){
		if(a[min] > a[i]){
			min = i;
		}
	}
	return min;
}
/*Trova il Minimo in un Intervallo di un array*/ //Utile per SelectionSort
int minimo_int(int a[], int i, int n) { 
	int min_int;
	min_int=minimo_array(a + i, n-i) + i;
	return min_int;
}

/* void selectionSort(int *array, int n){
	int i;
	int min;
	for(i=0; i<n-1;i++){
		min=minimo(array + i, n-i) + i;
		swap(&array[min], &array[i]);
		}
	}
*/


//seguite peppe289

/*------------ OPERAZIONI CON ARRAY -----------*/

/*Elimina elemento*/
int delete_el(int *a, int p, int n){
	int position = check_if_present(a,p,n); //check return -1 if not present otherwise return index
	if(position+1){
		int i;
		for(i = position; i < n-1; i++){a[i] = a[i + 1];}
		a[n-1] = 0;
		n--;
	} else {
		printf("Elemento non presente in array \n");
	}
	return n;
}


/*Inserisci elemento*/
//posizione p passata come range da 1 a n quindi in funzione aggiungere -1 dove necessario
int insert_el(int *a, int n, int insert, int p, int n_default){
	int counter = n;
	if(n == 0){ counter = n+1;}
	if(n == n_default){ counter = n-1;}
	if(p-1 > counter || p-1 < 0){
		printf("\nPosizione non valida");
	} else {
		if(n == n_default){
			printf("\nArray pieno, sostituire? (y/n): ");
			char response;
			//scanf("%c",&response);
			do {
				response=clear_getchar();
				if (response == 'y'){
					a[p-1]=insert;
					printf("Elemento sostituito \n");
				} else if(response == 'n'){
					printf("\nMain Menu: \n");
					break;
				} else {
					printf("Input non valido");
				}
			} while(response != 'n' && response != 'y');
		} else if (n > n_default) {
			printf("Somethings wrong, n > N... exiting"); // controllo se n è maggiore di N cost esce
			exit(EXIT_FAILURE);
		} else {
			n++;
			int k;
			for(k=n-1;k>p-1;k--){
				a[k]=a[k-1];
			}
			a[p-1]=insert;
		}
	}
	return n;
}


/*------------------------*/

/*----------------- ALGORITMI DI ORDINAMENTO --------------------*/


/*SELECTION_SORT*/

void selection_sort(int a[], int n){
		int i;
		for(i=0; i<n-1;i++){
			int min=minimo_int(a,i,n); //Theta(n)
			swap(&a[min], &a[i]);
		}	
}

/*Time Complexity = n * Theta(n) = Theta(n^2) */


/*INSERTION_SORT*/


/*- T(n) = O(n) ; Omega(1) -*/
int inserisci(int a[], int val, int n){
	int k;
	for(k=n-1;k>=0;k--){
		if(a[k] > val){
			a[k+1] = a[k];
			a[k]=val;
		} else {
			a[k+1] = val;
			return k+1;
		}
	
	}
	return k+1;
}

/** T(n) = O(n^2); Omega(n) **/
void insertion_sort(int a[], int n){
	int i;
	for(i=1;i<n;i++){
		int val = a[i];
		inserisci(a,val,i);
	}
	
}


/*BUBBLE_SORT*/

/** T(n) = O(n^2) ; Omega(n) **/
void bubble_sort(int a[], int n){
	int i,j;
	bool ordinato = false; //Adattativo = se non fa scambi è ordinato => Omega(1);
	for(i=1;i<n && !ordinato;i++){  // O(n^2);
		ordinato = true;
		//printf("\nSei Bello \n");
		for(j=0;j<n-i;j++){ //O(n)
			if(a[j]>a[j+1]){
				swap(&a[j],&a[j+1]);
				ordinato = false;
				//printf("..e ti tirano le printf \n");
			}
		}
	}
}