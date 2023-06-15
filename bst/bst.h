#include "../item/item.h"

/*Definizione puntatore a nodo*/
typedef struct node *BST;

BST newBST(); //Nuovo BST (return NULL)

/*Info su Nodo*/

int isEmptyBST(BST); //1 vuoto, 0 no
BST getLeft(BST); //Torna figlio sinistro o NULL se vuoto
BST getRight(BST); //Torna figlio destro o NULL se vuoto
Item getItem(BST); //Ritorna Item nodo, o NULL se nodo è vuoto

/*Operatori di ricerca*/

Item search(BST, Item); //Ritorna Item se trovato, NULL altrimenti - Ricorsiva
Item min(BST); //Se albero non vuoto, ritorna minimo (foglia estrema sinistra) - Ricorsiva
Item max(BST); //Se albero non vuoto, ritorna massimo (foglia estrema destra) - Ricorsiva

Item min_Iterative(BST b); //Versione Iterativa
Item max_Iterative(BST b); //Versione Iterativa

/*Inserimento ed Eliminazione*/
/*NB Ricorda di passare indirizzi di BST per effettuare modifiche ai nodi!*/

void insertBST(BST *, Item); // - Ricorsiva
Item deleteBST(BST *, Item); //Ritorna Item del nodo Rimosso o NULL - Ricorsiva

/*Funzioni di Stampa*/
void printPerLevel(BST); //Iterativa con Coda!