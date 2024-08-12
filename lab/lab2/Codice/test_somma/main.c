#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vettore.h"
#define N 50

int compare_result(int tot, int *oracle, int n){
	if(n < 0 || tot != oracle[n-1]){
		return 0;
	}
	return 1;
}


int main(int argc, char* argv[]) {
	//int A[N];
	//int n=5;
	
	char buffer[N];
	int array_input[N];
	int array_oracle[N];
	
	int dim_input, dim_oracle;
	int test_result;
	
	//input_array(A,n);
	//bubble_sort(A,n);
	//output_array(A,n);

	/*if(argc != 4){
		printf("Numero di argomenti non valido.. Exiting!");
		exit(1);
	}*/
	FILE *f_input, *f_oracle, *f_output;
	
	if ((f_input = fopen(argv[1], "r")) == NULL){
		printf("Error! opening file %s\n", argv[1]);
		//printf(stderr, "Error! opening file %s\n", argv[1]);
		// Program exits if fopen returns NULL.
		exit(1);
	}
	
	if ((f_oracle = fopen(argv[2], "r")) == NULL){
		printf("Error! opening file %s\n", argv[2]);
		// Program exits if fopen returns NULL.
		exit(1);
	}
	
	if ((f_output = fopen(argv[3], "w")) == NULL){
		printf("Error! opening file %s\n", argv[3]);
		// Program exits if fopen returns NULL.
		exit(1);
	}
		
	int i;
	for (i=1; fgets(buffer, N, f_input) != NULL; i++){
	
		printf("Elaboriamo riga %d. \n", i);
		int pos = strlen(buffer);
		dim_input = input_array_str(array_input, buffer, &pos);
		/*Somma elementi di un Vettore*/
		int totale = tot_array(array_input,dim_input);
		
		/*Otteniamo Oracle*/
		fgets(buffer, N, f_oracle); 
		dim_oracle = input_array_str(array_oracle, buffer, &pos);
		
		/*Compariamo il risultato*/
		test_result = compare_result(totale, array_oracle, dim_oracle);
	
		/*Stampiamo Risultato Test in Output*/
		fprintf(f_output, "Risultato test num %d: %d .\n",i,test_result);
		
		//output_array(array_input, dim_input);
		printf("Totale Calcolo: %d \n",totale);
		printf("Risultato test num %d: %d .\n",i,test_result);
	}
	
	fclose(f_input);
	fclose(f_oracle);
	fclose(f_output);
	return 0;
}