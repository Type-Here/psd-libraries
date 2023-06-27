#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "btree.h"

#include "../item/item.h"
#include "../list/list.h"
#include "../stack/stack.h"
#include "../queue/queue.h"


/* --- ALBERO BINARIO ---
 * L’ALBERO (generico) è un grafo diretto aciclico, una struttura informativa per rappresentare: 
 *  - Organizzazioni gerarchiche di dati 
 *  - Partizioni successive di un insieme in sottoinsiemi disgiunti
 *  - Procedimenti decisionali enumerativi
 * 
 * L'Alberio BINARIO:
 * Speciale ADT Albero con nodi aventi al massimo due figli (sinistro e destro).
 * 
 * Esempio di Albero Binario (da riferimento per gli esempi in funzioni successivamente)
 *                                       h
 *                                     /   \
 *                                    a     c
 *                                  /  \   /  \                                  
 *                                 d    l  p   s
 *                                     / \
 *                                    o   q
 * 
 */

/* NB spessso isEmptyTree(t) non è semanticamente necessario per la funzione, 
 * ma soprattutto nelle funzioni iterative ci evita di allocare spazio 
 * 	per le code e stack di appoggio necessarie al funzionamento delle funzioni stesse
 * risparmiando spazio e tempo */

/* -- DEFINIZIONE STRUTTURA -- */
struct node{
	Item value;
	struct node * left;
	struct node * right;
};

/*-- INIZIALIZZAZIONE ALBERO BINARIO --*/

/* newTree: nuovo nodo Inizializzato a NULL
 * Diverso da buildTree che invece crea un vero e proprio nodo */
BTree newTree(){
    return NULL;
}

/* BuildTree: Crea una nuova radice / nodo genitore
 * Argomenti: Figlio SN, Figlio DX, Value del nodo genitore
 * Costruttore di Tipo Bottom-Up: dalle foglie alla radice.
 * Sostanzialmente diverso da newTree, le funzioni non gestiscono bene valori NULLI del nodo.
 * Pertanto si consiglia di usare newTree se si intende lasciare il nodo vuoto. */
BTree buildTree(BTree left, BTree right, Item value){
    BTree t = newTree();
    t = malloc(sizeof(struct node));
    t->left = left;
    t->right = right;
    t->value = value;
    return t;
}

/*-- OTTIENI INFORMAZIONI SULL'ALBERO --*/

/*Come precisato in BuidTree e newTree il check per vedere se vuoto controlla se BTree t = NULL 
* non il suo valore! (t->value) 
* Ritorna 1 se vuoto, 0 altrimenti */
int isEmptyTree(BTree t){
    if(t == NULL) return 1;
    return 0;
}

/* Ottieni il Valore Item del Nodo Visitato (non della radice dell'albero!)
 * Ritorna l'Item se presente, altrimenti NULL */
Item getBTreeRoot(BTree t){
    if(isEmptyTree(t)) return NULL;
    return t->value;
}

/* Ottieni il Puntatore al Figlio SINISTRO del Nodo Visitato (non della radice dell'albero!)
 * Ritorna il NODO se presente, altrimenti NULL */
BTree getLeft(BTree t){
    if(isEmptyTree(t)) return NULL;
    return t->left;
}


/* Ottieni il Puntatore al Figlio DESTRO del Nodo Visitato (non della radice dell'albero!)
 * Ritorna il NODO se presente, altrimenti NULL */
BTree getRight(BTree t){
    if(isEmptyTree(t)) return NULL;
    return t->right;
}


/* ---- VISITE ALL'ALBERO BINARIO ---- */

/* - VISITE RICORSIVE: Es di DFS - */

/* La Visita PreOrder:
 *  - Prima visita il nodo in cui si trova (Stampa il Suo Valore)
 *  - Poi Visita il Figlio sinistro e ne stampa il valore
 *  - Poi Visita il Figlio destro e ne stampa il valore
 * Es. su Albero di Esempio: h a d l o q c p s  
 * */
void preOrder(BTree t){
    if(isEmptyTree(t)) return; //Passo Base
    outputItem(getBTreeRoot(t));
    preOrder(getLeft(t));
    preOrder(getRight(t));
    /*NB si potrebbe scrivere anche in questo modo 
      ma per favorire l'implementazione al difuori del modulo uso getLeft e getRight*/
    //outputIte(t->value);
    //preOrder(t->left);
    //preOrder(t->right);
}

/* La Visita PostOrder:
 *  - Prima Visita i Figli sinistri fino in fondo e risalendo ne stampa il valore
 *  - Poi Visita i Figli destri e ne stampa il valore
 *  - Infine visita le readici e ne stampa il valore
 * Es. su Albero di Esempio: d o q l a p s c h  
 * */
void postOrder(BTree t){
    if(isEmptyTree(t)) return; //Passo Base
    postOrder(getLeft(t));
    postOrder(getRight(t));
    outputItem(t->value);
}

/* La Visita InOrder o Simmetrica:
 *  - Prima Visita i Figli sinistri fino in fondo e risalendo ne stampa il valore
 *  - Poi visita le radici e ne stampa il valore
 *  - Infine visita i Figli destri e ne stampa il valore 
 * Es. su Albero di Esempio: d a o l q h p c s  
 * */
void inOrder(BTree t){
    if(isEmptyTree(t)) return; //Passo Base
    inOrder(getLeft(t));
    outputItem(t->value);
    inOrder(getRight(t));
} 

/* - IMPLEMENTAZIONI AGGIUNTIVE - */

/* - ALTEZZA ALBERO - */

/*Return Max of Value beetween 2 int*/
int maxOfValue(int a, int b){
    if(a >= b) return a;
    return b;
}

/* - Altezza dell'Albero: Ricorsiva - Nodo Radice = 0 - */
int btreeHeight(BTree t){ //Altezza albero binario
    if(isEmptyTree(t)) return 0; //P.B.
    if(!getLeft(t) && !getRight(t)) return 0; //P.B. (utile per non aggiungere h=1 quando solo radice!)
    return 1 + maxOfValue(btreeHeight(getLeft(t)), btreeHeight(getRight(t)));
}

/*- Altezza dell'Albero: Iterativa - Nodo Radice = 0 - */
int btreeHeight_Iterative(BTree t){
	if(isEmptyTree(t)) return 0;
	BTree temp;
	int h = 0;
	int counter, nodeslev = 1; //corrisponderà a numero di nodi per livello, parte da 1 per la radice
	Queue c = newQueue();
	enqueue(c, t);
	while(!isEmptyQueue(c)){
		h++;
		counter = nodeslev; //il ciclo interno visita i nodi presenti al livello attuale, x nodi = x cicli;
		nodeslev = 0; //riazzera il conteggio all'inizio di un ciclo interno
		while(counter--){
			temp = dequeue(c);
			if(getLeft(temp)) {enqueue(c, getLeft(temp)); nodeslev++;}
			if(getRight(temp)) {enqueue(c, getRight(temp)); nodeslev++;}
		}
	}
	free(c);
	return h-1;
}

/* - NUMERO DI NODI - */

/* - Ottieni Numero di Nodi: Ricorsivo - */
int btreeNodesNumber(BTree t){
    if(isEmptyTree(t)) return 0; //P.B.
    return 1 + btreeNodesNumber(getLeft(t)) + btreeNodesNumber(getRight(t));
}

/* - Ottieni Numero di Nodi: Iterativo - */
int btreeNodesNumber_Iterative(BTree t){
	if(isEmptyTree(t)) return 0;
	BTree temp;
	Queue c = newQueue();
	enqueue(c,t);
	int num = 1;
	while(!isEmptyQueue(c)){
		temp = dequeue(c);
		if(getLeft(temp)) {enqueue(c, getLeft(temp)); num++;}
		if(getLeft(temp)) {enqueue(c, getLeft(temp)); num++;}
	}
	free(c);
	return num;
}


/* - VISITA PER LIVELLI: Es di BFS - */

/*Es. h - a c - d l p s - o q*/

/* Internal Visita per livelli
 * Stampa un livello specifico dell'albero */
void printBTreeSpecificLevel(BTree t, int level){
    if(isEmptyTree(t)) return; //P.B.
    if(level == 0) outputItem(getBTreeRoot(t));
    if(level > 0){
        printBTreeSpecificLevel(getLeft(t), level - 1);
        printBTreeSpecificLevel(getRight(t), level - 1);
    }
}

/* - Visita per Livelli: Ricorsiva - */
void printBTreePerLevel(BTree t){ //Printa l'albero per livelli
     int height = btreeHeight(t);
     int level;
     for(level = 0; level <= height; level++){
        if(level != 0) printf("- ");
        printBTreeSpecificLevel(t, level);
     }
} 


/* - Visita Per Livelli: Iterativa - */
void printBTreePerLevel_Iterative(BTree t){
	if(isEmptyTree(t)) return;
	Queue c = newQueue();
	BTree temp;
	enqueue(c, t);
	while(!isEmptyQueue(c)){
		temp = dequeue(c);
		outputItem(getBTreeRoot(temp));
		if(getLeft(temp)) enqueue(c, getLeft(temp));
		if(getRight(temp)) {enqueue(c, getRight(temp));}
	}
	free(c);
}

/* - Visita Per Livelli: Iterativa; Più Carina la stampa con trattino tra i livelli - */
void printBTreePerLevel_Iterative_Pretty(BTree t){
	if(isEmptyTree(t)) return;
	Queue c = newQueue();
	BTree temp;
	int counter, numnodes = 1;
	enqueue(c, t);
	while(!isEmptyQueue(c)){
		counter = numnodes;
		numnodes = 0;
		while(counter--){
			temp = dequeue(c);
			outputItem(getBTreeRoot(temp));
			if(getLeft(temp)) {enqueue(c, getLeft(temp)); numnodes++;}
			if(getRight(temp)) {enqueue(c, getRight(temp)); numnodes++;}
		}
		if(!isEmptyQueue(c)) printf("- ");
	}
	free(c);
}


/* --- VISITE ALL'ALBERO BINARIO ITERATIVE --- */

/* Visita PreOrder Iterativa. Usa uno Stack */
void PreOrder_Iterative(BTree t){
    if(isEmptyTree(t)) return;
    Stack s = newStack();
    push(s, t);
    while(!isEmptyStack(s)){
        BTree node = pop(s);
        outputItem(getBTreeRoot(node));
        if(!isEmptyTree(getRight(node))) push(s, getRight(node));
        if(!isEmptyTree(getLeft(node))) push(s, getLeft(node));
    }
	free(s);
}

/* Visita PostOrder Iterativa. Usa uno Stack */
void PostOrder_Iterative(BTree t){
    if(isEmptyTree(t)) return;
    Stack s = newStack();
    BTree current = t;
    BTree temp, prev = NULL;
    while(!isEmptyStack(s) || current){
        if(current){
            push(s, current);
            current = getLeft(current);
        }
        else{
            temp = top(s);
            if (getRight(temp) != NULL && getRight(temp) != prev) {
                current = getRight(temp);
            } else {
                temp = pop(s);
                outputItem(getBTreeRoot(temp));
                prev = temp;
            }
        }
    }
	free(s);
}

/* Visita InOrder (Simmetrica) Iterativa. Usa uno Stack */
void InOrder_Iterative(BTree t){
    if(isEmptyTree(t)) return;
    Stack s = newStack();
    BTree current = t;
    BTree temp = NULL;
    while(!isEmptyStack(s) || current){
        if(current){
            push(s, current);
            current = getLeft(current);
        } else{
            temp = pop(s);
            outputItem(getBTreeRoot(temp));
            current = getRight(temp);
        }
    }
	free(s);
}

/* --- ALTRE FUNZIONI --- */

/* -- Funzioni di Ricerca -- */
/* Cerca Elemento in un albero binario, Ricorsiva
 * Ritorna l'Item trovato, non il suo nodo. Altrimenti NULL*/
Item searchItemBTree(BTree t, Item el){
    if(isEmptyTree(t)) return NULL;
    if(cmpItem(el, getBTreeRoot(t)) == 0){
        return getBTreeRoot(t);
    }
    Item le = searchItemBTree(getLeft(t), el);
    Item re = searchItemBTree(getRight(t), el);
    return (le) ? le : re;
}

/*Ritorna l'Elemento Maggiore in un Albero Binario. NULL se vuoto*/
Item maxItemBTree(BTree t){
    if(isEmptyTree(t)) return NULL;
    Item left = maxItemBTree(getLeft(t));
    Item right = maxItemBTree(getRight(t));
    Item root = getBTreeRoot(t);
    Item max = root;
    if(left){
        if(cmpItem(left, max) > 0){max = left;}
    }
    if(right){
        if(cmpItem(right, max) > 0){max = right;}
    }
    return max;
}

/* - Controlla se 2 alberi sono uguali; //1 if equal, otherwise 0 - */
int areEqualBtrees(BTree t, BTree cmp){
    if(isEmptyTree(t) && isEmptyTree(cmp)) return 1;
    if(isEmptyTree(t) || isEmptyTree(cmp)) return 0; // anche ^ (xor) ok ma il caso entrambi true già gestito
    if(cmpItem(getBTreeRoot(t), getBTreeRoot(cmp)) != 0) return 0;
    return (areEqualBtrees(getLeft(t), getLeft(cmp)) && areEqualBtrees(getRight(t), getRight(cmp)));
}



/* - Trova Numero di Nodi e Altezza Albero Insieme. Ritorna array di 2 elementi: [0] = alt, [1]= n nodi - */
int * heightAndNumNodes(BTree t){
	int * hn = calloc(sizeof(int), 2);
	if(isEmptyTree(t)) return hn;
	if(!getLeft(t) && !getRight(t)) return hn;
	int * hl = heightAndNumNodes(getLeft(t));
	int * hr = heightAndNumNodes(getRight(t));  
	hn[0] = (hl[0] > hr[0]) ? (hl[0] + 1): (hr[0] + 1);
	hn[1] = 1 + hl[1] + hr[1];
    free(hl);
    free(hr);
	return hn;
}

/* -- FREE BTREE -- */
/*Usa solo se Item allocati dinamicamente!*/
void freeBTree(BTree t){
	if(!isEmptyTree(t)){
		freeBTree(t->left);
		freeBTree(t->right);
		free(t);
	}
}


/* -- CALCOLO DI UN ALBERO DI ESPRESSIONI (EXPRESSION TREEs) -- */
float calcolaNodoItemOperatore(float l, float r, Item op){
	char * oper = op;
	if(strcmp(oper, "+") == 0){
		return l + r;
	} else if(strcmp(oper, "-") == 0){
		return l - r;
	} else if(strcmp(oper, "*") == 0){
		return l * r;
	} else if(strcmp(oper, "/") == 0){
		return l / r;
	} else {
		fprintf(stderr, "\nOperatore non Inizializzato\n");
		return -1;
	}
}


/* Calcola un'espressione inserita in un Albero Binario Pieno. (deve esserlo non controllato in funzione)
 * Ogni radice è un'operatore, ogni foglia un valore.
 * I nodi contengono tutti Item di tipo String 
 * Sembra una visita inOrder ma serve una postOrder per calcolare!
 * La inOrder ok per stampare correttamente l'equazione */
float resolveExpressionTree_Recursive(BTree t){
	if(isEmptyTree(t)) return 0;
	if(!getLeft(t) && !getRight(t)){ return ((float)atof(getBTreeRoot(t)));} 
	//se non ha figli dx e sx è una foglia quindi un numero da ritornare alla radice.
	float left = resolveExpressionTree_Recursive(getLeft(t));
	float right = resolveExpressionTree_Recursive(getRight(t));
	return calcolaNodoItemOperatore(left, right, getBTreeRoot(t));
}

/*Stampa un'equazione contenuta in un Albero di Espressioni, Visita inOrder Ricorsiva*/
/*Funzione Interna: Prende extpar come parametro 1 = stampa le parentesi esterne, 0 = no */
void printExpressionTree_Internal(BTree t, int extpar){
	if(isEmptyTree(t)) return;
	if(getLeft(t) && getRight(t) && extpar) printf("("); // se siamo in un nodo radice (operatore) stampa apri parentesi
	//NB tieni a mente come stampa inOrder! 
	//sei nel nodo radice fai "(" - left(num) - radice(+-*/) - right(num) -")"
	printExpressionTree_Internal(getLeft(t), 1);
	outputItem(getBTreeRoot(t));
	printExpressionTree_Internal(getRight(t), 1);
	if(getLeft(t) && getRight(t) && extpar) printf(")"); //come per apri parentesi ma dopo la ricorsione
}

/*Stampa un'equazione contenuta in un Albero di Espressioni, Visita inOrder Ricorsiva*/
void printExpressionTree(BTree t){
	printExpressionTree_Internal(t, 0); 
}
/* 0 = non stampare le parentesi al nodo radice t (le più esterne che racchiudono tutta l'equazione)
 * se vuoi stampare anche quelle inserisci 1 (o un num != 0)*/