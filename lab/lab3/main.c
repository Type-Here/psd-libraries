#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vettore.h"
#include "utils.h"

int main(int argc, char* argv[]) {
	int n;
	char line[100];
	int *array;
	
	int *array2;
	int *array3;
	int n2 = 0;
	
	char menu;
	
	printf("Buongiorno, inserisci un vettore: \n");
	scanf("%[^\n]", line);

	array = input_array_dyn(&n, line);
	printf ("Spazi sono: %d\n", n);
	
	printf("Il tuo array è: ");
	output_array(array,n);
	
	do {
		printf("Vuoi effettuare concatenazione array? (y/n) :");
		menu = clear_getchar();
		switch(menu) {
			case 'y':
				char line2[100];
				char char_var; //char di scarico e pulizia buffer;
		
				printf("\nInserisci il secondo vettore da concatenare: \n");
				scanf(" %[^\n]", line2);
				array2 = input_array_dyn(&n2, line2);
				printf("\nBene ora concateniamo questo vettore con il vettore precedente. \n");
				array3 = concatena_vet(array,array2,n,n2);	//concatena array2 su array1
				int new_n = n + n2;
				printf("Nuovo Array ha lunghezza %d .\n", new_n);
				//printf("Prima era %d\n",n);
				printf("Nuovo Array Concatenato: \n");
				output_array(array3,new_n);
				menu = 'n';
				break;
			
			case 'n':
				printf("Grazie per aver usato i nostri servizi, arrivederci.\n");
				break;
				
			default:
				printf("\nHai sbagliato.\n");
		}
	} while (menu != 'n');
	//free(array);
	free(array2);
	free(array3);
	return 0;
}