#ifndef ITEM_H
#define ITEM_H


/*struct studente {
    char* nome[20];
    char* cognome[20];
    char* matricola[20];
    //int esami;
    //int media;
};

typedef struct studente Studente; */

#endif /* ITEM_H */

typedef void* Item;

Item inputItem();
void outputItem(Item);
int cmpItem(Item,Item);

