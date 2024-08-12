#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "playlist.h"
#include "song.h"
#include <string.h>

#define MAX 51

char* getstrcl(char *s, int n){
	s[strcspn(fgets(s, MAX, stdin), "\n")] = 0;
	return s;
}


int main(){
	char* pl_name = "Rock";
	char *titol = malloc(MAX*sizeof(char));
	char *cantant = malloc(MAX*sizeof(char));
	char *temp_time = malloc(MAX*sizeof(char));
	int durata;
	printf("Buongiorno, crea la tua playlist 'Rock'\n");
	Playlist pl = createPlaylist(pl_name);
	int i;
	Song s;
	
	printf("Popola la tua playlist (5 canzoni): \n");
	for (i = 0; i < 5; i++){
		printf("\nNome Canzone: ");
		//scanf("%[^\n]s", titol);
		getstrcl(titol, MAX);
		printf("Nome Artista: ");
		//scanf("%[^\n]s", cantant);
		getstrcl(cantant, MAX);
		printf("Durata in sec: ");
		//scanf(" %d", &durata);
		getstrcl(temp_time, MAX);
		durata=atoi(temp_time);
		s = initSong(titol, cantant, durata);
		addSong(pl, s);
		
		
	}
	printf("\nBene, la tua playlist è: \n");
	printPlaylist(pl);
	
	printf("\n\nOrdiniamo ora per Titolo.\n");
	sortSongs(pl);

	printf("\nLa Playlist Rock ora è: \n");
	printPlaylist(pl);
	printf("\n");
	
	free(titol);
	free(cantant);
	free(temp_time);
		
	return 0;
}