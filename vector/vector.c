#include <stdlib.h>
#include <stdio.h>

#include "../item/item.h"
#include "../utils/utils.h"
#include "vector.h"

/*Dichiarazioni Locali*/
void merge(Item *a1, Item *a2, int s1, int s2, Item * a);

/* -- I/O ARRAY -- */
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

/**-- ORDINAMENTI SEMPLICI --**/

/*Array Ordinato in Modo Crescente; 1 true; 0 false*/
int isOrderedArrayC(Item *a, int size){
    int i = 0;
    while(i<size-1){
        if(cmpItem(a[i], a[i+1]) > 0) return 0;
    }
    return 1;
}

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

/** -ORDINAMENTI SEMPLICI RICORSIVI- **/

/*Selection Sort Ricorsivo*/
void selectionSortRecursive(Item *a, int size){
    if(size <= 1) return;
    int min = minimo(a, size);
    swap(&a[0], &a[min]);
    selectionSortRecursive(a+1, size-1);
}

/*BubbleSort Ricorsivo Adattivo*/
void bubbleSortRecursiveAdaptive(Item *a, int size){
    if(size <= 1) return;
    int i, isOrdered = 1;
    for(i = 0; i < size - 1; i++){
        if(cmpItem(a[i], a[i+1]) > 0){
            swap(&a[i], &a[i+1]);
            isOrdered = 0;
        }
    }
    if(isOrdered) return;
    bubbleSortRecursiveAdaptive(a, size-1);
}

/*Insertion Sort Ricorsivo*/
void insertionSortRecursive(Item *a, int size){
    if(size <= 1) return;
    insertionSortRecursive(a, --size);
    int n = size;
    insertSortedArray(a, &n, *(a + n));
}


/*-- RICERCA BINARIA --*/
int binarySearch(Item *a, int size, Item el){ //ritorna indice dell'array, -1 non trovato
    int m;
    int sup = size - 1;
    int inf = 0;
    while(inf <= sup){
        m = (sup + inf) / 2;
        if(cmpItem(el, a[m]) == 0) return m;
        else if(cmpItem(el, a[m]) > 0){
            inf = m+1;
        } else {
            sup = m-1;
        }
    }
    return -1;
}

/*Ricerca Binaria Ricorsiva*/
int binarySearchRecursive(Item *a, int size, Item el){
    if(size < 1) return -1;
    int m = size-1 / 2;
    if(cmpItem(el,a[m]) == 0){ return m;}
    else if(cmpItem(el,a[m]) > 0){
        /* I fattori m +/-1 correttivi servono perché la funz ricorsiva ritorna l'indice
         * nel sottoarray di dimensioni minori sopra o sotto la media al livello superiore rispettivamente;
         * corrispondono alla quantità aggiunta o sotratta nella ricorsione. */
        return m + 1 + binarySearchRecursive(a + (m + 1), size - (m + 1), el);
        //vai nel sotto array superiore da pos m+1
    } else {
        return m - 1 - binarySearchRecursive(a, size -(m+1), el);
        //vai nel sotto-array inferiore da 0 (relativo) a m-1
    }
}



/*--RICERCA BINARIA RICORSIVA -- Vecchia Implementazione, lasciata per documentazione
int BinarySearchRec_internal(int *a, int inf, int sup, int k){
	int center;
	if(inf > sup) return -1;
	else{
		 center = (inf + sup) / 2;
		 if(a[center] == k) return center;
		 else if(a[center] < k){
			 inf = center + 1;
			 return BinarySearchRec_internal(a,inf,sup,k);
		 }
		 else{
			sup = center - 1;
			return BinarySearchRec_internal(a,inf,sup,k);
		 }
	 }
	
}

int BinarySearchRec(int *a, int size, int k){
	return BinarySearchRec_internal(a,0,size-1,k);
}*/


/** - ORDINAMENTI AVANZATI ARRAY - **/

/*Funzione Merge: Unisce due sottoarray, T(n) = O(n); S(n) = n*/
void merge(Item *a1, Item *a2, int s1, int s2, Item * a){
    int i, j, k;
    Item b[s1+s2];
    for(i = j = k = 0; i < s1 && j <s2; k++){
        if(cmpItem(a1[i],a2[j]) <= 0){
            b[k] = a1[i];
            i++;
        } else {
            b[k] = a2[j];
            j++;
        }
    }

    for(; i < s1; i++, k++){
        b[k] = a1[i];
    }

    for(; j < s2; j++, k++){
        b[k] = a2[j];
    }

    for(k = 0; k < s2+s1; k++){
        a[k] = b[k];
    }
}


/* MergeSort */
void mergeSort(Item *a, int size){
    if(size <= 1) return;
    mergeSort(a, size/2);
    mergeSort(a + size/2, size - size/2);
    merge(a, a + size/2, size/2, size - size/2, a);
}

/*QuickSort*/
Item medianOfThreeItem(Item b, Item m, Item e){
    if(cmpItem(m,b) > 0){
        if(cmpItem(m,e) < 0) return m;
        else return e;
    } else {
        if(cmpItem(b,e) < 0) return b;
        else return e;
    }
}

int qsPartition(Item *a, int begin, int end){
    Item pivot = a[begin];
    //Item pivot = medianOfThreeItem(a[begin], a[(begin + end)/2], a[end]); //Ottimizzazione con calcolo mediana tra 3 valori
    int i = begin-1;
    int j = end+1;
    while(1){
        do{
            i++;
        } while(cmpItem(a[i], pivot) < 0);

        do{
            j--;
        } while(cmpItem(a[j], pivot) > 0);

        if(i >= j) return j;
        swap(&a[i], &a[j]);
    }
}

void qsInternal(Item *a, int begin, int end){
    if(begin >= end) return;
    int pivot = qsPartition(a, begin, end);
    qsInternal(a, begin, pivot);
    qsInternal(a, pivot+1, end);
}

void quickSort(Item *a, int size){
    if(size <= 1) return;
    //if(size <= 1 || isOrderedArrayC(a, size)) return; //Ottimizzazione se già ordinato ritorna
    qsInternal(a, 0, size-1);
}

/*MergeSort Iterativo*/
void mergeSortIterative(Item *a, int size){
    int dim = 1;
    int right, left;
    while(dim < size){
        right = dim;
        left = 0;
        while(right < size){
            int rend = (right + dim - 1 < size) ? dim : (size - right);
            merge(a + left, a + right, dim, rend, a + left);
            left += (2*dim);
            right += (2*dim);
        }
        dim = 2*dim;
    }
}