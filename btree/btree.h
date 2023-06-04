#include "../item/item.h"

/*Definizione Puntatore a Struttura*/
typedef struct node *BTree;

/*Crea Albero*/

BTree newTree();
BTree buildTree(BTree, BTree, Item);

/*Ottieni Info su Albero*/

int isEmptyTree(BTree);
Item getBTreeRoot(BTree);
BTree getLeft(BTree);
BTree getRight(BTree);

/*Visite all'Albero Binario*/

void preOrder(BTree);
void postOrder(BTree); 
void inOrder(BTree); //visita simmetrica

/* - IMPLEMENTAZIONI AGGIUNTIVE - */

/* - Altezza e Numero Nodi - */

int btreeHeight(BTree); //Altezza albero binario
int btreeNodesNumber(BTree); //Numero nodi di un albero binario

/*Visita per Livelli*/
void printBTreePerLevel(BTree); //Printa l'albero per livelli
void printBTreeSpecificLevel(BTree t, int level); //Stampa un livello specifico dell'albero binario

/*Visite all'Albero Binario Iterative*/

void PreOrder_Iterative(BTree); //Visita PreOrder dell'Albero, Usa uno Stack.
void PostOrder_Iterative(BTree); //Visita PostOrder dell'Albero, Usa uno Stack.
void InOrder_Iterative(BTree); //visita simmetrica iterativa, Usa uno Stack.


/*Altre Funzioni*/
/*Versioni Ricorsive*/
Item searchItemBTree(BTree, Item); //Cerca elemento in un albero binario, Ritorna Item o NULL
Item maxItemBTree(BTree); //Cerca l'elemento maggiore in un albero binario, Ritorna Item o NULL
int areEqualBtrees(BTree t, BTree cmp); //1 if equal, otherwise 0

/* -- Free BTree -- */
void freeBTree(BTree);


/* PrintTree in Forma di Albero
 * Presa da traccia. Non necessario saperla ma utile a visualizzare */

/*Stampa L'albero in maniera "visiva" al momento funziona solo con item_int*/
void printTree(BTree bt);