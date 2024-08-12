#include <stdio.h>
#include <stdlib.h>
#include "punto.h"

/* LABORATORIO 4

1. Chiediamo il numero n di punti da aggiungere in un array 
2. Creiamo un array a di punti di dimensione n 
3. Chiediamo in input n punti caricandoli nell’array a 
4. Chiediamo in input la distanza d 
5. Calcoliamo il numero m di coppie in a con distanza minore di d 
6. Stampiamo a video m

*/

void menu_f(){
	printf("\n1. Spostamento del punto dati due numeri reali deltaX e deltaY\n");
	printf("2. Calcola Centroide dell'insieme di punti.\n");
	printf("3. Calcola il numero di m coppie di punti che hanno distanza minore di un numero d\n\tNB Prende i punti inseriti in ordine a coppie 1-2; 3-4, 5-6 ecc..\n");
	printf("4. Calcola la distanza massima fra le coppie di punti della sequenza\n");
	printf("7. Stampa la sequenza inserita\n");
	printf("8. Stampa questo menu\n");
	printf("9. Esci\n");
}



int main(){
	int num;
	printf("Buongiorno, lavoriamo sui punti in un piano cartesiano \nQuanti punti vuoi inserire? ");
	scanf("%d", &num);
	Punto *seq;
	seq= (Punto *) calloc(num,sizeof(Punto));
    sequenza_punti(seq,num);
	
	int menu = 0;
	do{
		menu_f();
		printf("Cosa vuoi fare? (Print menu=8) ");
		scanf(" %d", &menu);
		switch(menu){
			case 1:
				int scelta;
				printf("Spostamento del punto dati due numeri reali deltaX e deltaY\n");
				stampa_sequenza(seq,num);
				printf("\nQuale punto vuoi spostare? 1-%d : ", num);
				scanf("%d", &scelta);
				if(scelta > num){
					printf("Scelta non valida \n");
				} else {
					printf("Di quanto lo vuoi spostare?(dx,dy): ");
					float dx, dy;
					scanf(" %f, %f",&dx, &dy);
					sposta(seq[scelta-1], dx, dy);
					printf("Risultato: ");
					stampa_sequenza(seq,num);
					printf("\n");
				}				
			break;
			
			case 2:
				printf("Calcoliamo il Centroide dell'insieme.\n");
				Punto centroid=centroide(seq, num);
				printf("Il punto centroide è: %.2f,%.2f; \n\n", ascissa(centroid), ordinata(centroid));
			break;
			
			case 3:
				printf("\nCalcoliamo il numero di m coppie di punti che hanno distanza minore di un numero d\n NB Prende i punti inseriti in ordine a coppie.\n");
				printf("Se la sequenza è dispari l'ultimo punto non verrà considerato\n");
				printf("\nQuale distanza vuoi considerare? ");
				float dist;
				int num_coppie = 0;
				scanf(" %f", &dist);
				num_coppie = punti_vicino_tot(seq, num, dist);
				printf("Le coppie di punti a min distanza di %.2f sono %d \n", dist, num_coppie);
			break;
			
			case 4:
				printf("4. Calcoliamo la distanza massima fra le coppie di punti della sequenza\n");
				printf("Se la sequenza è dispari l'ultimo punto non verrà considerato\n");
				printf("La distanza max è: %.2f", distanza_max(seq,num));
			break;
			
			case 7:
				printf("La sequenza inserita è: ");
				stampa_sequenza(seq,num);
			break;
			
			case 8:
			menu_f();
			break;
			
			case 9:
			break;
			
			default:
			printf("Input non valido. \n\n");
			menu = 8;
			break;
			
			
		}
	} while (menu != 9);
	
	

    return 0;
}