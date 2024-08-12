#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vettore.h"
#define N 50


/*TEST PRODOTTO VETTORI*/

int compare_result(int prod, int *oracle, int n){
	if(n < 0 || prod != oracle[n-1]){
		return 0;
	}
	return 1;
}

int main(int argc, char* argv[]) {
		
	char buffer[N];
	char buffer2[N];
	int array_input1[N];
	int array_input2[N];
	int array_oracle[N];
	
	int dim_input1, dim_input2, dim_oracle;
	int test_result;
	
	FILE *f_input1, *f_input2, *f_oracle, *f_output, *f_output2;
	
	if ((f_input1 = fopen(argv[1], "r")) == NULL){
		printf("Error! opening file %s\n", argv[1]);
		//printf(stderr, "Error! opening file %s\n", argv[1]);
		// Program exits if fopen returns NULL.
		exit(1);
	}
	
	if ((f_input2 = fopen(argv[2], "r")) == NULL){
		printf("Error! opening file %s\n", argv[2]);
		//printf(stderr, "Error! opening file %s\n", argv[1]);
		// Program exits if fopen returns NULL.
		exit(1);
	}
	
	if ((f_oracle = fopen(argv[3], "r")) == NULL){
		printf("Error! opening file %s\n", argv[3]);
		// Program exits if fopen returns NULL.
		exit(1);
	}
	
	if ((f_output = fopen(argv[4], "w")) == NULL){
		printf("Error! opening file %s\n", argv[4]);
		// Program exits if fopen returns NULL.
		exit(1);
	}
	
	if ((f_output2 = fopen(argv[5], "w")) == NULL){
		printf("Error! opening file %s\n", argv[5]);
		// Program exits if fopen returns NULL.
		exit(1);
	}
	
	int i;
	for (i=1; fgets(buffer, N, f_input1) != NULL || fgets(buffer2, N, f_input2) != NULL; i++){
		
		/*Otteniamo Input1*/
		printf("Elaboriamo riga %d. \n", i);
		int pos = strlen(buffer);
		dim_input1 = input_array_str(array_input1, buffer, &pos);
		
		/*Otteniamo Input2*/
		int pos2 = strlen(buffer2);
		fgets(buffer2, N, f_input2); 
		dim_input2 = input_array_str(array_input2, buffer2, &pos2);
		
		/*Prodotto Scalare di Due Array*/
		int prodotto;
		prodotto = i_prod(array_input1, array_input2, dim_input1, dim_input2);
						
		/*Otteniamo Oracle*/
		fgets(buffer, N, f_oracle); 
		dim_oracle = input_array_str(array_oracle, buffer, &pos);
		
		/*Compariamo il risultato*/
		test_result = compare_result(prodotto, array_oracle, dim_oracle);
	
		/*Stampiamo Risultato Test in Output*/
		fprintf(f_output, "Risultato test num %d: %d .\n",i,test_result);
		
		fprintf(f_output2, "%d \n", prodotto);
		
		printf("Prodotto = %d \n", prodotto);
		//output_array(array_input1, dim_input1);
		
		printf("Risultato test num %d: %d .\n\n",i,test_result);
	}
	
	fclose(f_input1);
	fclose(f_input2);
	fclose(f_oracle);
	fclose(f_output);
	fclose(f_output2);
	return 0;
}