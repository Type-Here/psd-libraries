#include "list.h"
#include "item.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "concessionaria.h"

/* -- DEFINIZIOE STRUTTURE -- */
struct concessionaria{
    char *name;
    List catalogo;
};

struct autom{
    char *targa;
    char * modello;
    int immatricolazione;
    int produzione;

};

/*-- CREAZIONE ADTs --*/

Concessionaria newConcessionaria(char *nameconc){
    Concessionaria c = malloc(sizeof(struct concessionaria));
    c->catalogo = newList();
    c->name = malloc(sizeof(char) * 31);
    c->name = nameconc;
    return c;
};

Auto newAuto(char * targa, char *modello, int immatricolazione, int produzione){
    Auto a = malloc(sizeof(struct autom));
    a->targa = malloc(sizeof(char) * 31);
    a->modello = malloc(sizeof(char) * 31);
    strcpy(a->targa, targa);
    strcpy(a->modello, modello);
    a->immatricolazione = immatricolazione;
    a->produzione = produzione;
    return a;
}


int aggiungiAuto(Concessionaria c, Auto a){
    addHead(c->catalogo, a);
    return 1;
}

/*-- OTTIENI INFO SU CONCESSIONARIA --*/

List getCatalogo(Concessionaria c){
    return c->catalogo;
}

char * getNameConc(Concessionaria c){
    return c->name;
}

/*-- FUNZIONI DI STAMPA --*/

void outputAuto(Auto a){
    printf("\n%s", a->targa);
    printf("\n%s", a->modello);
    printf("\nImm: %d", a->immatricolazione);
    printf("\nProd: %d", a->produzione);
    printf("\n");
}

void printCatalogo(List cat){
    if(isEmpty(cat)) return;
    Auto a = removeHead(cat);
    outputAuto(a);
    printCatalogo(cat);
    addHead(cat, a);
}

void printCatConcess(Concessionaria c){
    printCatalogo(c->catalogo);
}

/* -- FUNZIONI DA IMPLEMENTARE -- */

/*Cerca Auto per Targa, Funzione Ricorsiva */
Auto searchAutoTargaCatalogo(List cat, char * targa){
    if(isEmpty(cat)) return NULL;
    Auto a = removeHead(cat);
    Auto found = NULL;
    if(strcmp(a->targa, targa) == 0){
        addHead(cat, a);
        found = a;
        return found;
    }
    Auto b = searchAutoTargaCatalogo(cat, targa);
    addHead(cat, a);
    return (b) ? b : found; 
}


Auto searchAutoTarga(Concessionaria c, char * targa){
    return searchAutoTargaCatalogo(c->catalogo, targa);
}

/* Rimuovi auto per Targa, Funzione Ricorsiva */
Auto removeAutoTargaCatalogo(List cat, char * targa){
    if(isEmpty(cat)) return NULL;
    Auto a = removeHead(cat);
    Auto found = NULL;
    if(strcmp(a->targa, targa) == 0){
        found = a;
        return found;
    }
    Auto b = removeAutoTargaCatalogo(cat, targa);
    addHead(cat, a);
    return (b) ? b : found; 
}

Auto removeAutoTarga(Concessionaria c, char * targa){
    return removeAutoTargaCatalogo(c->catalogo, targa);
}

/* - Ordinamento per Anno di Produzione - */

int minYear(Auto *arr, int size){
    int i = 1;
    int min = 0;
    for(i; i < size; i++){
        if(arr[i]->produzione - arr[min]->produzione > 0){
            min = i;
        }
    }
    return min;
}

void sortByProdYear(Auto *arr, int size){
    int i = 0;
    for(; i < size; i++){
        int min = minYear(arr + i, size - i);
        Auto temp = arr[i];
        arr[i] = arr[min + i];
        arr[min + i] = temp;
    }
}

void orderByProdYearCat(List cat){
    Auto arr[50];
    int i = 0, k = 0;
    while(!isEmpty(cat)){
        arr[i] = removeHead(cat);
        i++;
    }
    sortByProdYear(arr, i);
    for(; k < i; k++){
        addHead(cat, arr[k]);
    }
}


/*Si sviluppi una funzione che ordini il catalogo delle auto per anno di produzione*/
void orderByProdYear(Concessionaria c){
	orderByProdYearCat(c->catalogo);
}