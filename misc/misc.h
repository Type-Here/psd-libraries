/* Qui Tutto quello Che non rientra in categorie specifiche */
#include "../item/item.h"

/*Funzioni Ricorsive e Iterative*/

/*MCD, Formula di Euclide*/
int MCD_rec(int a, int b); //MCD, Ricorsiva
int MCD_iterative(int a, int b); //MCD, Iterativa

/* - Fibonacci Definizione Classica f(0) = 0 - */
/* In alternativa esiste la Definizione Combinatoriale per cui f(0) = 1!*/

int fibonacci_rec(int n); //Fibonacci, Ricorsiva, f(0) = 0;
int fibonacci_iterative(int n); //Fibonacci, Iterativa, f(0) = 0;

int fibonacci_rec_alternative(int n); //Fibonacci, Ricorsiva, f(0) = 0; Alternativa da Testare

/* - Controlla se Stringa è palindroma - Ritorna 1:palindroma, 0:no, -1:stringa nulla */
int isPalindrome_Iterative(char *s); //versione iterativa
int isPalindrome_Recursive(char *s); //versione ricorsiva

