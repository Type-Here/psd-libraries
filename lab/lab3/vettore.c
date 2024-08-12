#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

static int conta_spazi(char *buffer); //Usato da input_array_dyn per contare quanti spazi ci sono in stringa di input

/***** Func1: somma degli elementi di un vettore *****/
int tot_array(int a[], int n) {
	int i, tot = 0;

	for(i = 0; i < n; i++)
		tot += *(a+i);

	return tot;
}
/***** Func2: somma di due vettori di pari dimensioni  *****/
void i_sum(int a[], int b[], int n1, int n2) {
	int i;

	if(n1 != n2)
		return;

	for(i = 0; i < n1; i++)
		a[i] = a[i] + b[i];
}


/***** Func3: Prodotto scalare di due vettori  *****/
int i_prod(int a[], int b[], int n1, int n2) {
	int i, prod = 0;

	if(n1 != n2)
		return 0;

	for(i = 0; i < n1; i++)
		prod += a[i] * b[i];

	return prod;
}

/**** Funzioni di input e output per vettori ****/

void input_array(int a[], int n){
	int i;
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
}

void output_array(int a[], int n) {
	int i;
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
    printf("\n");
}

/**** Funzione che carica dati da un buffer puntato da line nell'array di interi arr
 arr -> vettore di caricamento; line -> buffer; pos -> contiene il numero di caratteri letti in line ****/
int input_array_str(int *arr,char *line, int *pos){
	int i=0,n=0, counter=0;
    *pos=0;
	while(sscanf(line,"%d%n",&arr[i],&n)==1){ //%n Indica il numero di caratteri trasformati in numeri interi e gli spazi
		//printf("numero letto: %d\ncaratteri letti: %d\n", arr[i], n);
		line+=n;
		i++;
        counter+=n;//tiene il conto dei caratteri letti
	}
    *pos=counter +1; //pos è a disposizione del programma che ha invocato la funzione ed indica quanti caratteri totali sono stati letti nel buffer puntato da line
	return i;
}


/*Esercizio 3a - Allocazione dinamica Array da Input Buffer*/

int conta_spazi(char *buffer){
	int i, counter = 0;
	for(i = 0; buffer[i]!= '\0'; i++){
		if( buffer[i]==' ' && buffer[i+1] != ' '){
			counter++;
		}
	}
	return counter;
}

int *input_array_dyn(int *size, char *line){
	int i = 0;
	int n=0;
	*size = conta_spazi(line) + 1;
	printf("\nNumero elementi è: %d\n", *size);
	
	int *arr = (int *) malloc((*size)*sizeof(int));
	if (arr == NULL){
		fprintf(stderr, "Non si può allocare memoria di %d bytes\n", ((*size) *sizeof(int)));
		exit(1);
	}
	
	while(sscanf(line,"%d%n",&arr[i],&n)==1){
		line+=n;
		printf("Numero è: %d\n", arr[i]);
		i++;		
		//arr = (int *) realloc(arr, (i+1)*sizeof(int));
	}
	
	return arr;
}

/**-----Concatena Array ------**/
int *concatena_vet(int *array1, int *array2, int n1, int n2){
	int *array3 = (int *) realloc(array1,(n1+n2)*sizeof(int));
	if (array3 == NULL){
		fprintf(stderr, "Non si può allocare memoria di %d bytes\n", ((n1+n2) *sizeof(int)));
		exit(1);
	}
	int k;
	for (k = n1; k<(n1+n2); k++){
		array3[k]=array2[k-n1];
	}
	//printf("Stampa da Funzione: ");
	//output_array(array1, n1+n2);
	//n1+=n2;
	//free(array1);
	return array3;
}


/**** Funzioni di ordinamento e varie per vettori ****/
int min(int a[],int n) {
	int min=0;
	int i;
	for(i=1;i<n;i++)
		if(a[i]<a[min])
			min=i;
	return min;
}

void selection_sort(int a[], int n) {
	int i, m;
	for(i=0;i<n;i++) {
		m=min(a+i, n-i);
		swap(&a[i], &a[m+i]);
	}
}

void bubble_sort(int a[], int n){
	int i,j;

	for(i = 1; i < n; i++)
		for(j = 0; j < n - i; j++)
			if(a[j] > a[j+1])
				swap(&a[j],&a[j+1]);
}

void adaptive_bubble_sort(int a[], int n){
	int i,j,ordinato = 0;

	for(i = 1; i < n && !ordinato; i++) {
		ordinato = 1;
		for(j = 0; j < n - i; j++)
			if(a[j] > a[j+1]) {
				swap(&a[j],&a[j+1]);
				ordinato = 0;
		}
	}
}


void insert_array(int a[], int *n, int el, int pos){
	int i;
	if(pos<0||pos>*n)
		return;
	for(i=*n;i>pos;i--)
		a[i]=a[i-1];
	a[pos]=el;
	++*n;
}


void insert_sorted_array(int a[], int *n, int el){
	int i;

	for(i=*n;i>0 && a[i-1]>el;i--)
		a[i]=a[i-1];
	a[i]=el;
	++*n;
}


void insertion_sort(int a[],int n){
	int i=1;
	while(i<n)
		insert_sorted_array(a,&i,a[i]);
}

int compare_arrays(int a [], int b [],int  n1, int n2){
		int i;
		if(n1!=n2)
			return 0;
		for(i=0; i<n1 ;i++)
			if(a[i]!= b[i])
				return 0;
		return 1;
}
