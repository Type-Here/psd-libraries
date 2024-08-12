/**INTERFACCIA DI SONG**/

#ifndef SONG_H
#define SONG_H

typedef struct canzone *Song;

Song initSong(char* title, char* artist, int durata);
char* title(Song);
char* artist(Song);
int durata(Song);

#endif