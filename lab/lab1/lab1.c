//Main Programm
#include <stdio.h>
#include "vettor.h"
#include "utils.h"

#define N 5

void print_menu(){
	printf("Salve, hai a disposizione un array di 5 elementi \n");
	printf("1. Premi 'a' per popolare array \n");
	printf("2. Premi 'p' per stampare array \n");
	printf("3. Premi 's' per cercare un elemento dell'array \n");
	printf("4. Premi 'm' per ricercare il minimo in un dato array \n");
	printf("5. Premi 'o' per ordinare un dato array \n");
	printf("6. Premi 'd' per Eliminare un elemento in un dato array \n");
	printf("7. Premi 'i' per Inserimento di un elemento in un dato array \n");
	printf("8. premi 'h' per stampare questo menu \n");
	printf("9. Premi 'e' o 'q' per uscire \n");
}

int main(int argc, char *argv[]) {
	
	int mio_array[N];	
	int elementi = 5; // Inizialmente popoliamo l'intero array. NB deve essere <= a N
	
	popola(mio_array,elementi); //lo popoliamo randomicamente per testing
	
	char menu;
	print_menu();		
	do {
		printf("\nCosa vuoi fare? 'h' per aiuto: ");
		//scanf( "%c", &menu); 
		/*scanf salva in variabile sia il char che /n(/r) 
		  quindi alla prima iterazione switch prenderà char alla seconda /n e dà errore! 
		  meglio usare getchar() da stdio */
		menu=clear_getchar();
		printf("\n");
		switch (menu) {
			case 'a':
			input_array(mio_array, elementi);
			break;
			
			case 'p': 
			output_array(mio_array, elementi);
			break;
			
			case 's':
			int cerca;
			printf("Inserisci la cifra da cercare: ");
			scanf("%d", &cerca);
			printf("\n");
			ricerca_array(mio_array, elementi, cerca);
			break;
			
			case 'm':
			int mini;
			mini = minimo_array(mio_array, elementi);
			printf("Il numero più piccolo è: %d \n", mio_array[mini]);
			break;
			
			case 'o':
			printf("Ordiniamo l'array. \n");
			selection_sort(mio_array, elementi);
			output_array(mio_array, elementi);
			printf("\n");
			break;
			
			case 'd':
			int mariorui;	
			output_array(mio_array, elementi);
			printf("\nQuale elemento eliminare? ");
			scanf("%d", &mariorui);
			
			elementi = delete_el(mio_array, mariorui, elementi); 
			//delete_el ritorna n-1 ed "elimina" un elemento in modo da "nasconderlo" stampando n-1 in elementi 
			
			printf("\nRisultato: ");
			output_array(mio_array, elementi);
			
			break;
			
			case 'i':
			int ohsimen, lobotka;
			printf("\nQuale numero inserire? ");
			scanf("%d", &ohsimen);
			if(elementi == N){printf("\n In che posizione? (1 - %d): ", elementi);}
			else {printf("\n In che posizione? (1 - %d): ", elementi+1);}
			
			scanf("%d", &lobotka);
			
			elementi = insert_el(mio_array, elementi, ohsimen, lobotka, N);
			break;
			
			case 'h':
			print_menu();
			break;
			
			case 'e':
			case 'q':
			break;
			
			default:
            printf("This input is not valid \n"); 
            break;
		}
	} while(menu != 'e' && menu != 'q');
	
	return 0;
}