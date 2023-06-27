/*FUNZIONI SU VETTORE*/

/* --Funzioni Generiche-- */
void input_array(Item *arr, int size); //Input from user with InputItem
void output_array(Item *arr, int size);
Item * concatena_array(Item *arr1, Item *arr2, int size1, int size2); //ritorna un terzo array

/* Ordinamenti Semplici Array */
int isOrderedArrayC(Item *a, int size); //Controlla se Array è Ordinato in Modo Crescente; 1 true, 0 false

void selectionSort(Item *, int size); 

void bubbleSort(Item *, int size);
void bubbleSortAdaptive(Item *, int size);

void insertionSort(Item *, int size);
void insertSortedArray(Item *a, int * n, Item el); // n < size! controllo da implementare in funzione chiamante!

/* Ordinamenti Semplici Array Ricorsivi */
void bubbleSortRecursiveAdaptive(Item *a, int size);
void selectionSortRecursive(Item *a, int size);
void insertionSortRecursive(Item *a, int size);

/* Ricerca Binaria */
int binarySearch(Item *a, int size, Item el); //ritorna indice di array, -1 non trovato
int binarySearchRecursive(Item *a, int size, Item el); //ritorna indice di array, -1 non trovato

/* Ordinamenti Più Avanzati Array */
void mergeSort(Item *a, int size); //Usa merge, ricorsivo
void quickSort(Item *a, int size); //Pivot = a[begin]

void mergeSortIterative(Item *a, int size); //Versione iterativa, usa merge

/*Altro*/
Item medianOfThreeItem(Item b, Item m, Item e); //calcola mediana tra 3 Item