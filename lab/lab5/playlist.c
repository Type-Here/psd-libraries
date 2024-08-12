/***---- ADT PLAYLIST ----***/

/** Specificare e realizzare un ADT «Playlist» che dovrà fornire operatori per:
1.Creare una playlist(indicata da un nome e una lista di canzoni); 
Una canzone è caratterizzata dal titolo, dal nome del cantante (o gruppo musicale) e dalla durata della canzone in secondi.
2.Inserire una canzone in testa ad una playlist;
3.Rimuovere una canzone da una playlist dato il titolo;
4.Ordinare la playlist in base al titolo delle canzoni **/

struct canzone{
	char *titolo;
	char *cantante;
	int durata;
};


#include "playlist.h"
#include "song.h"
#include "lista.h"
#include <stdlib.h>


struct playlist{
	char *nome;
	List songs;
};


/*struct nodo-list{
	struct canzone *song;
	struct nodo-list *next;
};*/


Playlist createPlaylist(char *name){
	Playlist playlist= malloc(sizeof(struct playlist));
	playlist->nome = name;
	
	List songs = newList();
	playlist->songs = songs;
	
	return playlist;
}

Playlist addSong(Playlist pl, Song s){
	addHead(pl->songs, s);
	return pl;
}

Playlist removeSong(Playlist pl, char* title){
	
	Song temp = malloc(sizeof(Song));
	temp->titolo= malloc(31*sizeof(char));
	temp->titolo = title;
	removeListItem(pl->songs, temp);
	return pl;
}

Playlist sortSongs(Playlist pl){
	selectionSortList(pl->songs);
	return pl;
}

void printPlaylist(Playlist pl){
	printList(pl->songs);
}