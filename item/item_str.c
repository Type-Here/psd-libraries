#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "item.h"

#define MAX 50

Item inputItem(){
    char * str = malloc(MAX*sizeof(char)); 
    scanf("%s", str);
    return str;
}

void outputItem(Item it){
    printf("%s\t", (char *) it);
}

int cmpItem(Item e1, Item e2){
    char * s1 = e1;
    char * s2 = e2;
    return (strcmp(s1, s2));
}

/*Vuota serve solo per compilare! Non Usare printTree con Item String!*/
void outputItemLen(Item it, int len){return;}


/* Funzione Per generare BTree casuali, non necessaria saperla!
 * serve solo per compilare! Non Usare newRandomTree con Item String! */
Item randomItem() {
    char * r = "isnotrand";
    return r;
}