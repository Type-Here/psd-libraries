#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../item/item.h"
#include "misc.h"

/* Qui Tutto quello Che non rientra in categorie specifiche
 * Troviamo:
 * - Funzioni Ricorsive
 * - ADT Punto Cartesiano
 * - Altr.. (da completare) 
 * - Massimo Comune Divisore */


/** -- MIX FUNZIONI RICORSIVE E SUE ITERATIVE -- **/

/* - Calcola il Massimo Comune Divisore tra due numeri interi con Formula di Euclide - */

/*MCD Ricorsivo*/
int MCD_rec(int a, int b){
    if(b == 0) return a;
    return MCD_rec(b, a % b);
}

/*MCD Iterativo*/
int MCD_iterative(int a, int b){
    int c = 0;
    while(b != 0){
        c = a % b;
        a = b;
        b = c;
    }
    return c;
}

/* - Fibonacci Definizione Classica f(0) = 0 - */

/*Calcola numero di Fibonacci fino ad n nella sequenza - Ricorsivo*/
int fibonacci_rec(int n){
    if(n < 1) return 0;
    if(n == 1) return 1;
    return (fibonacci_rec(n-1) + fibonacci_rec(n-2));
}

/*Versione Ricorsiva di Seq di Fibonacci leggermente ottimizzata(?)*/
int fibonacci_rec_alternative(int n){
    if(n < 1) return 0;
    if(n == 1) return 1;
    if(n == 2) return 1;
    return (2*fibonacci_rec(n-2) + f(n-3));
}

/*Calcola numero di Fibonacci fino ad n nella sequenza - Iterativo!*/
int fibonacci_iterative(int n){
    if(n == 0) return 0;
    int i = 0;
    int fib = 0, a = 1, b = 0;
    for(i; i <= n; i++){
        fib = a + b;
        b = a;
        a = fib;
    }
    return fib;
}

/* - Controlla se Stringa è Palindroma - */

int isPalindrome_Internal(char *string, int size){
    if(size <= 1) return 1;
    if(string[0] != string[size-1]) return 0;
    isPalindrome_Internal(string + 1, size - 1);
}

/* Funzione che controlla se una stringa è palindroma i.e. "anna", "sos"; Ricorsiva
 * Ritorna 1 se true, 0 se false */
int isPalindrome_Recursive(char * string){
    if(!string) return -1;
    return isPalindrome_Internal(string, strlen(string));
}

/*Riporto solo per conoscenza la funzione ricorsiva con variabile "static" */
/*int palindromo_rec_opt(char* s){
	static int i = 1;
	if(strlen(s) <= 1){
		i = 1;
		return 1;
	}		
	else if(s[0] != s[strlen(s)-i]){
		i = 1;
		return 0;
	}
	else {
		i++; 
		return palindromo_rec_opt(s+1);
		}
	return 1;
}*/

int isPalindrome_Iterative(char *s){
    if(!s) return -1;
    int j = strlen(s);
    if(j <= 1) return 1;
    int i = 0;
    j--; //strlen(s) = size; j = size - 1
    while(i < j){
        if(s[i] != s[j]) return 0;
        i++;
        j--;
    }
    return 1;
}