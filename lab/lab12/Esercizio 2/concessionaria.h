#include "item.h"

/*Definizioni Puntatori a Struct*/
typedef struct concessionaria *Concessionaria;
typedef struct autom *Auto; 

/*Creazione ADTs*/
Concessionaria newConcessionaria(char *nameconc);
Auto newAuto(char * targa, char *modello, int immatricolazione, int produzione);

/*Aggiungi Auto a Concessionaria*/
int aggiungiAuto(Concessionaria c, Auto a);

/*Funzioni di Print*/
void outputAuto(Auto a); //stampa tutte le info su singola auto
void printCatConcess(Concessionaria c); //stampa il catalogo di una concessionaria

/*Ottieni Info Sulla Concessionaria*/
List getCatalogo(Concessionaria c);
char * getNameConc(Concessionaria c);

/*Funzioni da Implementare sul Catalogo*/
Auto searchAutoTarga(Concessionaria c, char * targa);
Auto removeAutoTarga(Concessionaria c, char * targa);

void orderByProdYear(Concessionaria c); //Ordinamento per Anno di Produzione (selection sort)