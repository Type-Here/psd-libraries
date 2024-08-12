#ifndef PLAYLIST_H
#define PLAYLIST_H

typedef struct playlist *Playlist;
typedef struct canzone *Song;


Playlist createPlaylist(char*);

Playlist addSong(Playlist, Song);
Playlist removeSong(Playlist, char*);

Playlist sortSongs(Playlist);

void printPlaylist(Playlist);

#endif