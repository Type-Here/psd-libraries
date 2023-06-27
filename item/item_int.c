#include "item.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

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

/*Funzione Per generare BTree casuali, non necessaria saperla*/
Item randomItem() {
	int *pt = malloc(sizeof(int));
    srand(time(0));
	*pt = rand() % 10;
	return pt;
}