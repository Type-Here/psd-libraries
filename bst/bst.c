#include <stdlib.h>
#include <stdio.h>

#include "bst.h"
#include "../item/item.h"
#include "../queue/queue.h"

/* -- IMPLEMENTAZIONE BST ---*/
/* Definizione: Albero Binario con le seguenti caratteristiche, se l'albero non è vuoto:
 *   - ogni elemento del sottoalbero di sinistra precede (<) la radice
 *   - ogni elemento del sottoalbero di destra segue (>) la radice
 *   - i sottoalberi sinistro e destro sono alberi binari di ricerca
 *
 * Complessità O(h), dove h è l’altezza dell’albero.
 * Senza ulteriori implementazioni (es alberi AVL o Delta-Bilanciati) possono uscire 
 * casi degeneri come alberi "lineari" che diventano come delle liste (es aggiungiamo numeri in ordine crescente)
*/


/*-- DEFINIZIONE STRUTTURA --*/
struct node {
    Item value;
    struct node *left;
    struct node *right;
};

/*Funzioni Interne*/

BST createNodeBST(); //Crea un nodo allocando la memoria necessaria e ne inizializza i valori interni a NULL

/*-- CREAZIONE ALBERO --*/
/*--Segue Stesse Regole di BTree per la creazione--*/

/*Creazione nuovo BST vuoto, ritorna NULL*/
BST newBST(){
    return NULL;
}

/* Usa insertBST invece */
/* Operatore di Creazione Albero Bottom-Up. Identico nel lavoro a buildTree di btree.c
 * Ritortato qui come buildBST per favorire l'indipendenza del modulo da btree.c e testarlo autonomamente.
 * La correttezza dei dati in left e right (left < right) lasciata al client.

BST buildBST(BST left, BST right, Item value){
    if(!value) return NULL;
    BST b = malloc(sizeof(struct node));
        if(!b) {fprintf(stderr, "\nMemoria non allocata in  %s\n", __func__); return NULL;}
    b->left = left;
    b->right = right;
    b->value = value;
    return b;
}*/

/*Richiamato in insertBST, funzione interna*/
/*Crea un nodo allocando la memoria necessaria e ne inizializza i valori interni a NULL*/
BST createNodeBST(){
	BST b = malloc(sizeof(struct node));
	b->left = NULL;
	b->right = NULL;
	b->value = NULL;
	return b;
}

/* -- INFORMAZIONI SU UN NODO BST -- */

/*Ritorna 1 se vuoto, 0 altrimenti*/
int isEmptyBST(BST b){
    if(b == NULL) return 1;
    return 0;
}

/*Ritorna nodo Sinistro, NULL se non esiste*/
BST getLeft(BST b){
    if(isEmptyBST(b)) return NULL;
    return b->left;
}

/*Ritorna nodo Destro, NULL se non esiste*/
BST getRight(BST b){
    if(isEmptyBST(b)) return NULL;
    return b->right;
}

/* Ritorna Item del Nodo, NULL se nodo non esiste
 * Simile a getBTreeRoot di btree.c */
Item getItem(BST b){
    if(b == NULL) return NULL;
    return b->value;
}


/*-- OPERATORI DI RICERCA --*/

/* Cerca un elemento in BST, Ritorna Item o NULL. - Versione Ricorsiva.
 * Siccome il BST è "ordinato" sfruttiamo le caratteristiche del bst per migliorare l'efficienza di ricerca*/
Item search(BST b, Item el){
    if(isEmptyBST(b)) return NULL; //P.B.
    if(cmpItem(b->value, el) == 0) return b->value;
    else if(cmpItem(b->value, el) < 0){
        return search(getRight(b), el); //Per le caratt. del bst se val nodo < el da cercare vai a figlio dx (che è > del nodo)
    } else {
        return search(getLeft(b), el); //VIceversa cerca nel nodo sinistro
    }
    //return NULL; //Non dovrebbe mai arrivare qui
}

/* Ricerca il minimo, Ritorna Item o NULL se bst vuoto - Ricorsivo
 * Siccome bst "ordinato" min value è la foglia all'estrema sinistra */
Item min(BST b){
    if(isEmptyBST(b)) return NULL; //P.B.
    if(!(getLeft(b))) return b->value; //P.B. 
    else min(getLeft(b)); //Chiamata ricosiva su figlio sn
}

/* Ricerca il massimo, Ritorna Item o NULL se bst vuoto - Ricorsivo
 * Siccome bst "ordinato" max value è la foglia all'estrema destra */
Item max(BST b){
    if(isEmptyBST(b)) return NULL; //P.B.
    if(!(getRight(b))) return b->value; //P.B. 
    else max(getRight(b)); //Chiamata ricosiva su figlio dx
}


/*Min e Max - Versioni Iterative*/

/*Ricerca il minimo in BST - Iterativo*/
Item min_Iterative(BST b){
    if(isEmptyBST(b)) return NULL;
    BST temp = b;
    while(temp->left){
        temp = temp->left;
    }
    return temp->value;
}

/*Ricerca il massimo in BST - Iterativo*/
Item max_Iterative(BST b){
    if(isEmptyBST(b)) return NULL;
    BST temp = b;
    while(temp->right){
        temp = temp->right;
    }
    return temp->value;
}


/* -- INSERIMENTO ED ELIMINAZIONE -- */

/* Inserimento Valore (e quindi nodo in BST) - Ricorsiva.
 * Seguiamo l'albero seguendo le regole del BST e creiamo una nuova foglia quando incontriamo un figlio vuoto */
void insertBST(BST *b, Item el){
    if(isEmptyBST(*b)){ //P.B.
        *b = createNodeBST();
        (*b)->value = el;
    } else if(cmpItem(el, (*b)->value) == 0){ //Il valore già esiste, ritorniamo senza creare (no duplicati)
        return;
    } else if(cmpItem(el, (*b)->value) > 0){ //se el > val nodo allora deve essere inserito nel figlio destro
        insertBST(&((*b)->right), el);
    } else {
        insertBST(&((*b)->left), el); //se el < val nodo allora deve essere inserito nel figlio sinistro
    }
}


/* Note Sull'Eliminazione di un Nodo con entrambi i figli:
 *  1. Si sostituisce l’elemento da eliminare con il max nel sottoalbero sinistro (da notare che tale elemento non ha sottoalbero destro, la cui radice altrimenti sarebbe maggiore) 
 *     (Alternativamente si cerca e sostituisce con l’elemento minimo nel sottoalbero destro)
 *  2. Si chiama ricorsivamente la delete sul sottoalbero sinistro del nodo contenente l’elemento max
 *  3. L’albero risultante è un ABR.
 */

/*Eliminazione Nodo per Item - Ricorsiva */
Item deleteBST(BST *b, Item el){
    if(!el) return NULL;
    if(isEmptyBST(*b)) return NULL; //P.B.
    int dif = cmpItem(el, (*b)->value);
    if(dif > 0){ //Chiamate ricorsive per trovare l'elemento (logica uguale a insert)
        return deleteBST(&((*b)->right), el);
    } else if(dif < 0){
        return deleteBST(&((*b)->left), el);
    
    /*Elemento trovato*/
    } else { //se elemento è uguale elimina nodo (dif == 0)
        BST removed;
        Item temp = (*b)->value; //Assegniamo a temp il valore del nodo da eliminare
        if(!getLeft(*b)){ //se non ha figlio sinistro assegna figlio destro al nodo e libero la memoria del nodo rimosso
            //anche se non ha nessun figlio alla fine il nodo assumerà NULL
            removed = *b;
            *b = (*b)->right;
            free(removed);
            return temp;

        } else if(!getRight(*b)){ //se non ha figlio destro assegna figlio sinistro al nodo e libero la memoria del nodo rimosso
            removed = *b;
            *b = (*b)->left;
            free(removed);
            return temp;

        } else { //se ha entrambi i figli
            Item mx = max((*b)->left); //mx = massimo del sottoalbero di sinistra
			(*b)->value = mx; //assegna mx al value del nodo attuale
			deleteBST(&(*b)->left, mx); //Elimina il massimo del sottoalbero sinistro di b
            return temp;
        }
    }

}

/*Implementazione simile a BTree*/
void printPerLevel(BST b){
    if(isEmptyBST(b)) return;
    Queue q = newQueue();
    BST temp;
    enqueue(q, b);
    while(!isEmptyQueue(q)){
        temp = dequeue(q);
        outputItem(temp->value);
        if(getLeft(temp)) enqueue(q, getLeft(temp));
        if(getRight(temp)) enqueue(q, getRight(temp));
    }
    free(q);
}