#include <stdlib.h>
#include <stdio.h>

#include "item.h"
#include "btree.h"
#include "coda.h"
#include "stack.h"

struct node{
	Item value;
	struct node * left;
	struct node * right;
};

/*Funzioni interne ricorsive*/
Item ItemizeBTree(BTree t);

/* Crea nuovo albero Vuoto quindi con puntatore a NULL
 * la malloc sarà chiamata da 
*/
BTree newTree(){
	return NULL;
}

int isEmptyTree(BTree t){
	if(t == NULL) return 1;
	return 0;
}

BTree buildTree(BTree left, BTree right, Item el){
	//if(!Item) return NULL;
	BTree t = newTree();
	t = malloc(sizeof(struct node));
	t->left = left;
	t->right = right;
	t->value = el;
	
	return t;
}

Item getBTreeRoot(BTree t){
	if(isEmptyTree(t)) return NULL;
	return (t->value);
}

BTree getLeft(BTree t){
	if(isEmptyTree(t)) return NULL;
	return (t->left);
}

BTree getRight(BTree t){
	if(isEmptyTree(t)) return NULL;
	return (t->right);
}

void preOrder(BTree t){
	if(!isEmptyTree(t)){
		outputItem(t->value);
		preOrder(t->left);
		preOrder(t->right);
	}
}

void postOrder(BTree t){
	if(!isEmptyTree(t)){
		postOrder(t->left);
		postOrder(t->right);
		outputItem(t->value);
	}
}

void inOrder(BTree t){
	if(!isEmptyTree(t)){
		inOrder(t->left);
		outputItem(t->value);
		inOrder(t->right);
	}
}

/*LAB 9*/

/* Realizzare una o più funzioni per determinare l’altezza di un albero
 * e una o più funzioni per determinare il numero di nodi 
 * di un albero binario.
 */

/*Altezza di un Albero*/
int btreeHeight(BTree t){
	if(isEmptyTree(t)) return -1; //necessario altrimenti ritorna altezza + 1
	/* Così facendo un albero completamente vuoto ritorna -1, 
	 * un albero con almeno un item in radice ritorna 0 */
	int lh = btreeHeight(t->left);
	int rh = btreeHeight(t->right);
	if( lh >= rh) return lh + 1;
	else return rh + 1;
}

/*Numero di Nodi Totale*/
int btreeNodeNumber(BTree t){
	if(isEmptyTree(t)) return 0;
	return btreeNodeNumber(t->left) + btreeNodeNumber(t->right) + 1;
	
}

/*Stampa albero binario per livelli*/
void print_binary_tree_per_level(BTree t) {
	if(isEmptyTree(t)) return;	
	Coda q = nuovaCoda(); //Nuova Coda
	accoda(q, (Item) t);

	
	/* Nel while si fa il cast del puntatore BTree a Item perché la coda richiede Item.
	 * Va poi fatto il cast a BTree per fare l'output di t->value e per accodarne i figli. 
	 */
	while(!isEmptyCoda(q)){
		BTree tl = (BTree) rimuovi(q);
		outputItem(tl->value);
		if(!isEmptyTree(tl->left)) accoda(q, ItemizeBTree(tl->left));	//Accoda il nodo figlio di sx (cast a Item)
		if(!isEmptyTree(tl->right)) accoda(q, ItemizeBTree(tl->right)); //Accoda il nodo figlio di dx (cast a Item)
	}
	freeQueue(q); //free coda
}


/*Casting da BTree a Item*/
Item ItemizeBTree(BTree t){
	return t;
}

/*-- FUNZIONI ITERATIVE DI VISITA --*/

/*PreOrder Iterativo*/
void PreOrder_Iterative(BTree t){
	if(isEmptyTree(t)) return;
	Stack s = newStack();
	push(s,ItemizeBTree(t));
	/* In questo caso con l'uso di Stack LIFO va invertito l'ordine di inserimento, 
	 * prima il destro poi il sinistro perché verrà rimosso con pop prima quest'ultimo.
	 * Per il ruolo di Itemize e l'attenzione per i casting vedi note di print_binary_tree_per_level(BTree t).
	 */
	while(!isEmptyStack(s)){
		BTree tl = (BTree) pop(s);
		outputItem(tl->value);
		if(!isEmptyTree(tl->right)) push(s, ItemizeBTree(tl->right)); //Impila il nodo figlio di dx (cast a Item)
		if(!isEmptyTree(tl->left)) push(s, ItemizeBTree(tl->left));	//Impila il nodo figlio di sx (cast a Item)	
	}
	
	freeStack(s);
}

/*PostOrder Iterativo*/
void PostOrder_Iterative(BTree t){
	if(isEmptyTree(t)) return;
	Stack s = newStack();
	
	BTree current = t;
    BTree temp, prev = NULL;
	
	while (current || !isEmptyStack(s)) {
        if (current) {
            push(s, ItemizeBTree(current));
            current = current->left;
        }
        else {
            temp = (BTree) top(s);
            if (temp->right && temp->right != prev) {
                current = temp->right;
            }
            else {
                temp = (BTree) pop(s);
                outputItem(temp->value); 
                prev = temp;
				//free(temp); //DO NOT USE, UNLESS YOU WANT TO DESTROY THE TREE!
            }
        }
    }
	
	freeStack(s);
}

/*inOrder Iterativo*/
void InOrder_Iterative(BTree t) {
	if(isEmptyTree(t)) return;
	Stack s = newStack();
    BTree current = t;

    while (current || !isEmptyStack(s)) {
        if (current) {
            push(s, ItemizeBTree(current));
            current = current->left;
        }
        else {
            BTree temp = (BTree) pop(s);
            outputItem(temp->value);
            current = temp->right;
			//free(temp); //DO NOT USE, UNLESS YOU WANT TO DESTROY THE TREE!
        }
    }

    freeStack(s);
}


/*FREE BTREE*/
void freeBTree(BTree t){
	if(!isEmptyTree(t)){
		freeBTree(t->left);
		freeBTree(t->right);
		free(t);
	}
}


