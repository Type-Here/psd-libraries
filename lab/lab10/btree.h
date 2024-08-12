#include "item.h"

typedef struct node *BTree;

BTree newTree();
int isEmptyTree(BTree);
BTree buildTree(BTree, BTree, Item);
Item getBTreeRoot(BTree);
BTree getLeft(BTree);
BTree getRight(BTree);
void preOrder(BTree);
void postOrder(BTree);
void inOrder(BTree); //visita simmetrica

int btreeHeight(BTree); //Altezza albero binario
int btreeNodeNumber(BTree); //Numero nodi di un albero binario

void print_binary_tree_per_level(BTree); //Printa l'albero per livelli

/*Visite Iterative*/
void PreOrder_Iterative(BTree);
void PostOrder_Iterative(BTree);
void InOrder_Iterative(BTree);


/*Lab 10*/
Item searchItemBTree(BTree, Item);
Item maxItemBTree(BTree);
int areEqualBtrees(BTree t, BTree cmp); //1 if equal, otherwise 0

/*Free BTree*/
void freeBTree(BTree);