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

//Ricorsive
int btreeHeight(BTree); //Altezza albero binario, solo rad = 0
int btreeNodesNumber(BTree); //Numero nodi di un albero binario

//Iterative
int btreeHeight_Iterative(BTree); //Altezza albero binario, solo rad = 0
int btreeNodesNumber_Iterative(BTree);

/*Visita per Livelli*/
void printBTreePerLevel(BTree); //Printa l'albero per livelli, Ricorsiva
void printBTreeSpecificLevel(BTree t, int level); //Stampa un livello specifico dell'albero binario
void printBTreePerLevel_Iterative(BTree t); //Printa l'albero per livelli, Iterativa

void printBTreePerLevel_Iterative_Pretty(BTree t); //Sempre iterativa, stampa con separatore tra livelli

/*Visite all'Albero Binario Iterative*/

void PreOrder_Iterative(BTree); //Visita PreOrder dell'Albero, Usa uno Stack.
void PostOrder_Iterative(BTree); //Visita PostOrder dell'Albero, Usa uno Stack.
void InOrder_Iterative(BTree); //visita simmetrica iterativa, Usa uno Stack.


/*Altre Funzioni*/
/*Versioni Ricorsive*/
Item searchItemBTree(BTree, Item); //Cerca elemento in un albero binario, Ritorna Item o NULL
Item maxItemBTree(BTree); //Cerca l'elemento maggiore in un albero binario, Ritorna Item o NULL
int areEqualBtrees(BTree t, BTree cmp); //1 if equal, otherwise 0
int * heightAndNumNodes(BTree); //Trova Numero Nodi e Altez Albero Insieme. Ritorna array di 2 el: [0] = alt, [1]= n nodi

/* Calcola un'espressione inserita in un Albero Binario Pieno. (deve esserlo non controllato in funzione)
 * Ogni radice è un'operatore, ogni foglia un valore.
 * I nodi contengono tutti Item di tipo String 
 * Sembra una visita inOrder ma serve una postOrder per calcolare!*/
float resolveExpressionTree_Recursive(BTree t);
void printExpressionTree(BTree t); //Stampa Equazione in un Albero di Espressioni, Visita inOrder Ricorsiva


/* -- Free BTree -- */
void freeBTree(BTree); //Usa solo in caso di Item Allocati dinamicamente! altrimenti uso free su albero