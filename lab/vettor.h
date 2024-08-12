// Modulo Vettore:
// Contiene le funzionalità per la manipolazione dell’array

//INTERFACCIA

void input_array(int a[], int n);
void output_array(int a[], int n);
int ricerca_array(int a[], int n, int elem); //ritorna numero di ricorrenze di elem
int minimo_array(int a[], int n); //return valore minimo in array
int massimo_array(int a[], int n); //return valore max array
int delete_el(int *a, int p, int n); // return n-1 if successfull otherwise n
int insert_el(int *a, int n, int i, int p, int n_default); // n_default = N costante in main; n= num elem al momento //return n+1 if successful otherwise n


//Algoritmi di Ordinamento
void selection_sort(int a[], int n);

void insertion_sort(int a[], int n);

void bubble_sort(int a[], int n);