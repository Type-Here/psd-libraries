/*FUNZIONI SU VETTORE*/

/* --Funzioni Generiche-- */
void input_array(Item *arr, int size);
void output_array(Item *arr, int size);
Item * concatena_array(Item *arr1, Item *arr2, int size1, int size2);

/* Ordinamenti Semplici Array */
void selectionSort(Item *, int size); 

void bubbleSort(Item *, int size);
void bubbleSortAdaptive(Item *, int size);

void insertionSort(Item *, int size);
void insertSortedArray(Item *a, int * n, Item el); // n < size! controllo da implementare in funzione chiamante!