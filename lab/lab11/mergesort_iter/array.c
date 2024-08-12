#include <stdio.h>

#define N 10


// T(n) = 3 = O(1)
void swap(int *a, int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}

// T(n) = O(n) = Omega(n) = Theta(n)
int minimo(int *array, int n){
	int i;
	int minimo = 0;

	for(i = 1; i < n; i++){
		if (array[minimo] > array[i]){
			minimo = i;
		}
	}

	return minimo;
}

void inputArray(int *array, int n){
	int i;

	for(i = 0; i < n; i++){
		scanf("%d",&array[i]);
	}
}

void printArray(int *array, int n){
	int i;

	for(i = 0; i < n; i++){
		printf("%d ", array[i]);
	}
}

// T(n) = n * Theta(n) = Theta(n^2)
void selectionSort(int *array, int n){
	int i;
	int min;

	for(i = 0; i < n-1; i++){
		min = minimo(array + i, n-i) + i; //Theta(n)
		swap(&array[min], &array[i]);
	}	
}

// T(n) = O(n) = Omega(1)
void insertSortedArray(int *array, int val, int *n)
{
	int i;
	for(i=(*n); i>0 && array[i-1]>val; i--)
	{
		array[i] = array[i-1];
	}
	array[i] = val;
	(*n)++;
}

// T(n) = O(n^2) = Omega(n)
void insertionSort(int *array, int n)
{
	int i=1;
	while(i<n)
		insertSortedArray(array, array[i], &i); // 
}

// T(n) = O(n^2) = Omega(n)
void bubbleSort(int *array, int n)
{
	int i,j, ordinato = 0;
	for(i=1; i<n && !ordinato; i++){ 
		ordinato = 1;
		for(j=0; j<n-i; j++) //Theta(n)
			if(array[j]>array[j+1]) {
				swap(&array[j], &array[j+1]);
				ordinato = 0;
			}
	}
	if(ordinato == 1)
		printf("L'array è già ordinato\n");
	}
//T(n)=T(n/2)+c 
int ricercaBR(int *arr, int inf, int sup, int k){
	int centro;
	if(inf>sup)
		return -1;
	else{
		centro=(inf+sup)/2;
		if(arr[centro]==k)
			return centro;
		else if(arr[centro]<k){
			return ricercaBR(arr, centro+1, sup, k);
		}
		else 
			return ricercaBR(arr, inf, centro-1, k);

	}
}

int ricercaBinariaR(int *arr, int size, int k){
	return ricercaBR(arr, 0, size-1, k);
}

/*MergeSort*/
void merge(int *a1, int *a2, int d1, int d2, int *a){
	int i, j, k, b[d1+d2];
	
	for(i = j = k = 0; i < d1 && j < d2; k++){
		if(a1[i] <= a2[j]){
			b[k] = a1[i];
			i++;
		}else{
			b[k] = a2[j];
			j++;
		}
	}
	
	for(; i<d1; i++, k++)
		b[k] = a1[i];
	
	for(; j<d2; j++, k++)
		b[k] = a2[j];
	
	for(k = 0; k< d1+d2; k++)
		a[k] = b[k];
}

void mergeSort(int *a, int n){
	if(n>1){
		mergeSort(a, n/2);
		mergeSort(a+n/2, n-n/2);
		merge(a, a+n/2, n/2, n-n/2, a);
	}
}

/** MergeSort Iterativo **/

void mergeSort_Iterativo(int *a, int size){
	int dim = 1;
	int ind = 0;
	int pos;
	while(dim < size){
		printf("\n dim %d", dim);
		pos = dim;
		ind = 0;
		while(pos < size){
			int end = (pos + dim -1 < size) ? (pos + dim - 1) : size - 1;
			printf("\nMerge di %d-%d e %d-%d", a[ind], a[ind + dim - 1], a[pos], a[end]);
			merge(a + ind, a + pos, dim, end + 1 - pos, a+ind);
			ind += (2 * dim);
			pos += (2 * dim);					
		}
		dim = 2*dim;
	}
}









/*QuickSort*/
int partition(int *arr, int begin, int end){
	int pivot = arr[begin];
	int i = begin - 1, j = end + 1;
	while(1){
		do {
			j--;
		} while(arr[j] > pivot);
		
		do {
			i++;
		} while(arr[i] < pivot);
		
		if( i >= j) return j;
		swap(arr + j, arr + i); 
	
	}
}

void qSort(int *arr, int begin, int end){
	if(begin < end){
		int p = partition(arr, begin, end);
		qSort(arr, begin, p);
		qSort(arr, p+1, end);
	}
}

void quickSort(int *arr, int size){
	qSort(arr, 0, size-1);
}

int main(){
	int a[N];
	int n=N;
	inputArray(a, n);
	mergeSort_Iterativo(a, n);
	printf("\n");
	printArray(a, n);
	printf("\n");

	return 0;
}


