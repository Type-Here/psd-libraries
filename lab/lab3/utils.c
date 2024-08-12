// Modulo Utils: funzionalità generali (es swap)
// IMPLEMENTAZIONE

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//#define RAND_MAX 50

int init(){
	srand(time(NULL));   // Initialization, should only be called once.	
	return 0;
}


/*Swap 2 Elementi in Array*/
void swap(int *a, int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
	}

/*Controlla se int b presente in array a di dim n*/	
int check_if_present(int *a, int b, int n){
	int i;
	for(i=0;i<n;i++){
		if(b == a[i]){
			return i;
		}
	}
	return -1;
}

/*getchar che "pulisce" il buffer da \n e EOF*/
int clear_getchar(){
	int c;
	while ((c = getchar()) == '\n' || c == EOF) { continue; }
	return c; 
}

/*popola randomicamente array a di n elementi*/
void popola(int *a, int n){
	int i;
	for(i=0;i<n;i++){
		a[i] = rand() % 100 + 1;      // Returns a pseudo-random integer between 0 and RAND_MAX, then limitng to 100.
	}
}