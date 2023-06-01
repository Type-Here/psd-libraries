#include <stdlib.h>
#include <stdio.h>

#include "../item/item.h"
#include "../utils/utils.h"
#include "vector.h"

void input_array(Item *arr, int size){
    int i;
    for(i = 0; i < size; i++){
        arr[i] = inputItem();
    }
}

void output_array(Item *arr, int size){
    int i;
    for(i = 0; i < size; i++){
        outputItem(arr[i]);
        printf(" ");
    }  
}

Item * concatena_array(Item *arr1, Item *arr2, int size1, int size2){
    Item *arr3 = malloc((size1+size2)*(sizeof(Item)));
    if(!arr3) {
        fprintf(stderr, "\nImpossibile allocare arr3 di size %d.\n", size1+size2);
        return NULL;
    }
    int k, j;
    for (k = 0; k< size1; k++){
		arr3[k] = arr1[k];
	}
    for (j = 0; j < size2; j++, k++){
		arr3[k] = arr2[j];
	}
}

/**-- FUNZIONI PER ORDINAMENTI --**/

/*- Ritorna l'indice dell'elemento Minimo -*/
int minimo(Item *arr, int size){
    int i, min = 0;
    for(i = 1; i < size; i++){
        if(cmpItem(arr[min], arr[i]) > 0){
            min = i;
        }
    }
    return min;
}

/*- Ritorna l'indice dell'elemento Massimo -*/
int massimo(Item *arr, int size){
    int i, max = 0;
    for(i = 1; i < size; i++){
        if(cmpItem(arr[max], arr[i]) < 0){
            max = i;
        }
    }
    return max;
}


/*- Selection Sort -*/
void selectionSort(Item *a, int size){
    int i = 0;
    int min;
    for(i; i < size; i++){
        min = minimo(a + i, size - i);
        swap(&a[i], &a[min + i]);
    }
}

/*- Bubble Sort -*/
void bubbleSort(Item *a, int size){
    int i, j;
    for(i = 1; i < size; i++){
        for(j = 0; j < size - i; j++){
            if(cmpItem(a[j], a[j+1]) > 0) swap(&a[j], &a[j+1]);
        }
    }
}

/*- Bubble Sort Adattativo -*/
void bubbleSortAdaptive(Item *a, int size){
    int i, j, isOrdered = 1;
    for(i = 1; i < size; i++){
        for(j=0; j < size - i; j++){
            if(cmpItem(a[j], a[j+1]) > 0){
                swap(&a[j], &a[j+1]);
                isOrdered = 0;
            }

        }
    if(isOrdered) return;
    }
}

/*- Insertion Sort -*/
void insertionSort(Item *a, int size){
    int i = 1;
    while(i < size){
        insertSortedArray(a, &i, a[i]);
    }
}

/*Insertion in a Sorted Array*/
void insertSortedArray(Item *a, int * n, Item el){ // n < size! controllo da implementare in funzione chiamante
    int i;
    for(i = *n; i > 0 && cmpItem(a[i-1], el) > 0; i--){
        a[i] = a[i-1];
    }
    a[i] = el;
    ++(*n);
}

