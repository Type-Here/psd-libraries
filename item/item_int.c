#include "item.h"
#include <stdlib.h>
#include <stdio.h>

Item inputItem(){
    int * a = malloc(sizeof(int));
    scanf("%d", a);
    return a;
}

void outputItem(Item e){
    int * a = e;
    printf("%d ", *a);
}

int cmpItem(Item e1, Item e2){
    int * a1 = e1;
    int * a2 = e2;
    return (*a1 - *a2);
}


/*Funzione Per Stampare BTree visivamente, non necessaria saperla*/
void outputItemLen(Item it, int len){
	int *pt = it;
	int length = snprintf(NULL, 0, "%d", *pt);
	char str[length + 1];
	snprintf(str, length + 1, "%d", *pt);

	printf("%.*s", len, str);
}