#include "item.h"
#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "concessionaria.h"

#define SIZES 31


/* INFO SULL'ESERCIZIO:
 * Come suggerito dal Professore in Aula, pur se non richiesto dalla traccia,
 * ho preso i parametri delle auto da un file txt chiamato "auto.txt".
 * Per lo svolgimento in concessionaria.c, 
 * ho simulato una prova d'esame in cui list.c e list.h e item*.c NON potessero essere modificati,
 * il che ha portato a soluzioni non ottimali ma funzionanti */
/* Le auguro buona giornata */


int menu(Concessionaria c);

int main(){

	FILE * fp = fopen("auto.txt", "r");
	char line[100];
	int counter = 1;

	Concessionaria piccirillo = newConcessionaria("piccirillo");

	while(fgets(line, 100, fp)){
		Auto new;
		char *targa, *modello;
		int imma, prod;
		int pos = 0, exist = 1, read = 0, counter = 1;
		while(exist == 1){
			char * word = malloc(sizeof(char) * SIZES);
			exist = sscanf(line + pos, "%s%n", word, &read);
			pos += read;
			if(!word || strcmp(word, "\0") == 0) break;
			switch(counter){
				case 1:
					targa = word;
					break;
				case 2:
					modello = word;
					break;
				case 3:
					imma = atoi(word);
					free(word);
					break;
				case 4:
					prod = atoi(word);
					free(word);
					break;
			}
			counter++;
		}
		//printf("\nAggiungo");
		new = newAuto(targa, modello, imma, prod);
		aggiungiAuto(piccirillo, new);
		free(targa);
		free(modello);
	}

	fclose(fp);

	printf("\n-- Welcome to Piccirillo Experience --\n");
	menu(piccirillo);

	return 0;
}


int menu(Concessionaria c){
	int choice = 9;
	do{
		switch (choice)
		{
		case 1:
			char targa[30];
			printf("\nInserisci Targa da Cercare: ");
			//targa[strcspn(fgets(targa, 30, stdin), "\n")] == '\0';
			scanf("%[^\n]", targa);
			getchar();
			printf("\nCerchiamo auto con targa %s", targa);
			Auto search = searchAutoTarga(c, targa);
			if(search){ 
				printf("\nAuto trovata: \n");
				outputAuto(search);
			} else {
				printf("\nAuto non presente in catalogo\n");
			}
			break;

		case 2:
			printf("\n\nOrdiniamo ora il catalogo per anno di produzione: ");
			orderByProdYear(c);
			printCatConcess(c);
			break;
		
		case 3:
			printf("\nCatalogo Concessionaria: %s ", getNameConc(c));
			printCatConcess(c);
			break;

		case 4:
			printf("\n\nRimuoviamo ora un 'auto dal catalogo\n");
			printf("\nCatalogo Intero: ");
			printCatConcess(c);
			printf("\n------\n");
			printf("\nInserisci Targa di Auto da Eliminare: ");
			char elimina[30];
			//elimina[strcspn(fgets(elimina, 30, stdin), "\n")] == '\0';
			scanf("%[^\n]", elimina);
			getchar();
			printf("\nRimuoviamo Auto con Targa %s", elimina);
			Auto rimossa = removeAutoTarga(c, elimina);
			if(rimossa){ 
				printf("\nAuto Rimossa: \n");
				outputAuto(rimossa);
			} else {
				printf("\nAuto non presente in catalogo\n");
			}	
			break;

		
		case 9:
			printf("\nMain Menu: ");
			printf("\nPremi 1 per Cercare per Targa");
			printf("\nPremi 2 per Ordinare per Anno di Produzione");
			printf("\nPremi 3 per Stampare Catalogo Auto");
			printf("\nPremi 4 per Eliminare un'auto per Targa");
			printf("\nPremi 9 pre Stampare il Menu");
			printf("\n\nPremi 0 per Uscire.");
			//printf("\n -----\nCosa vuoi fare?: ");
			//scanf("%d", &choice);
			break;
		
		default:
			printf("\nOperazione non valida.\n");
			choice = 9;
			break;
		}

		printf("\n -----\nCosa vuoi fare? (9 menu): ");
		scanf("%d", &choice);
		getchar();

	}while(choice != 0);
	return 0;
}