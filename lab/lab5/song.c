/**QUA CREIAMO SOGNI E CANZONI**/
#include "song.h"
#include "playlist.h"
#include <stdlib.h>
#include <string.h>

struct canzone{
	char *titolo;
	char *cantante;
	int durata;
};

Song initSong(char* title, char* artist, int durata){
	Song p = malloc(sizeof(struct canzone));
	p->titolo = malloc(31*sizeof(char));
	strcpy(p->titolo, title); 
	p->cantante = malloc(31*sizeof(char));
	strcpy(p->cantante, artist);
	p->durata = durata;
	return p;
}

char* title(Song s){
	return s->titolo;
}


char* artist(Song s){
	return s->cantante;
}

int durata(Song s){
	return s->durata;
}