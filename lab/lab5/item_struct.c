struct canzone{
	char *titolo;
	char *cantante;
	int durata;
};

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "song.h"
#include "playlist.h"

Item inputItem(){
    struct canzone *p=malloc(sizeof(struct canzone));
	//p->titolo = malloc(51*sizeof(char));
	//p->cantante = malloc(51*sizeof(char)); 
    printf("\nNome Canzone: ");
    scanf(" %s", p->titolo);
    printf("\nNome Artista: ");
    scanf(" %s", p->cantante);
    printf("\nDurata in sec: ");
    scanf(" %d", p->durata);
    
    return p;
}

void outputItem(Item a){
    Song p = a;
    printf("-Titolo: %s \n-Cantante: %s \n-Durata: %d\n\n", p->titolo, p->cantante, p->durata);
}

int cmpItem(Item a,Item b){
    Song p1 = a;
    Song p2 = b;

    return strcmp(p1->titolo,p2->titolo);
    return 0;
}