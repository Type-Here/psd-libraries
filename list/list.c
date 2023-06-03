#include <stdlib.h>
#include <stdio.h>

#include "list.h"
#include "../item/item.h"

/* -- DEFINIZIONE STRUTTURE -- */

struct node{
    Item value;
    struct node * next;
};

struct list {
    int size;
    struct node *head;
    struct node *tail;
};

/**-- FUNZIONI BASE --**/

/*Alloca nuova lista e assegna NULL a puntatori, 0 a size*/
List newList(){
    List l = malloc(sizeof(struct list));
        if(!l){fprintf(stderr, "\nFailed to Allocate Memory\n"); return NULL;}
    l->size = 0;
    l->head = NULL;
    l->tail = NULL;
    return l;
}

/*Check su Size; 1 se vuota, 0 altrimenti*/
int isEmptyList(List l){
    if(l->size == 0) return 1;
    return 0;
}

/*Aggiunge nodo in testa a lista con value=el. Aggiorna param head e tail se necessario*/
void addHead(List l, Item el){
    struct node * newHead = malloc(sizeof(struct node));
        if(!newHead){fprintf(stderr, "\nFailed to Allocate Memory\n"); return;}
    struct node * head = l->head;
    
    newHead->value = el;
    newHead->next = head;
    l->head = newHead;

    if(!(l->tail)) l->tail = newHead; //se la coda è vuota, la lista è vuota e la testa sarà anche la coda
    
    (l->size)++;
}

/*Rimuove Nodo in Testa, Ritorna il suo Value*/
Item removeHead(List l){
    if(isEmptyList(l)) return NULL;
    
    struct node * rem = l->head;
    l->head = rem->next;
    (l->size)--;

    Item removed = rem->value;
    free(rem);

    if(isEmptyList(l)){ //se ora la lista è vuota azzera anche il puntatore a coda
        l->tail = NULL;
    }

    return removed;
}

/*Ritorna Value di Head*/
Item getHead(List l){
    if(isEmptyList(l)) return NULL;
    return l->head->value;
}

Item getTail(List l){
    if(isEmptyList(l)) return NULL;
    return l->tail->value;
}

/*Ritorna list size*/
int sizeList(List l){
    return l->size;
}

/*Stampa Lista*/
void printList(List l){
    if(isEmptyList(l)) return;
    struct node * temp = l->head;
    while(temp){
        outputItem(temp->value);
        printf(" ");
        temp = temp->next;
    }   
}

/* -- FUNZIONI DI RICERCA ED ELIMINAZIONE ITEM -- */

/* Cerca in Lista per Item uguale (ritorna prima occorrenza). 
 * Assegna a pos (passato per argomento) la posizione, 
 * Ritorna l'Item in Nodo */
Item searchListItem(List l, Item el, int * pos){
    *pos = 0;
    struct node * temp;

    for(temp = l->head; temp != NULL; temp = temp->next, (*pos)++){
        if(cmpItem(temp->value, el) == 0){
            return temp->value;
        }
    }
    *pos = -1;
    return NULL;
}

/*Cerca un Item per valore e lo elimina se presente*/
Item removeListItem(List l, Item el){
    if(isEmptyList(l)) return NULL;
    Item removed;
    struct node * t;
    struct node * prev = NULL;

    for(t = l->head; t != NULL; t = t->next){
        if(cmpItem(t->value, el) == 0){
            if(t == l->head) return removeHead(l); //se el è in testa fai gestire a removeHead per i passaggi extra
            if(t == l->tail) l->tail = prev; //aggiorna coda a precedente in caso il nodo da eliminare sia l'ultimo
            removed = t->value; //assegna a removed il valore del nodo
            prev->next = t->next; //rimuovi nodo da catena 
            free(t); //libera il nodo da memoria
            (l->size)--;
           
            return removed; //ritorna l'item
        }
        prev = t; //prev uguale a temp per tenere puntatore a precedente nodo
    }
    return NULL;
}

/*Elimina Elemento per Posizione in lista
* Elementi "indicizzati" come array quindi pos max = size - 1.
* Ritorna Item (value) del nodo rimosso*/
Item removeListPos(List l, int pos){
    if(pos < 0 || pos >= l->size) return NULL;
    if(pos == 0) return removeHead(l); //facciamo gestire a removeHead i passaggi extra in caso di rimoz testa
    Item el;
    int count = 0;
    struct node * t = l->head;
    struct node * prev = NULL;
    while(t && count < pos) {
        prev = t;
        t = t->next;
        count++;
        }

    el = t->value; //assegna a removed il valore del nodo
    if(t == l->tail) l->tail = prev; //aggiorna coda a precedente in caso il nodo da eliminare sia l'ultimo
    prev->next = t->next; //rimuovi nodo da catena 
    free(t); //libera il nodo da memoria
    (l->size)--;
    
    return el;
}

/* Aggiunge elemento in posizione pos.
 * Ritorna size se possibile altrimenti -1 */
int addListPos(List l, Item el, int pos){
    if(pos < 0 || pos > l->size) return -1;
    if(pos == l->size) return addListTail(l,el); //uguale perché size è maggiore di 1 rispetto alla posizione indicizzata
    if(pos == 0) {
        addHead(l,el);
        return l->size;
    }
    int count = 0;
    struct node * newNode = malloc(sizeof(struct node));
        if(!newNode){fprintf(stderr, "\nFailed to Allocate Memory\n"); return -1;}
    struct node * t = l->head;
    
    while(count < pos - 1 && t){ //arriviamo al nodo precedente, controllo su t non necessario ma utile a gestire eventuali errori
        t=t->next;
    }
    newNode->value = el;
    newNode->next = t->next;
    t->next = newNode;
    return ++(l->size);

}

/*Aggiunge Nodo a Coda, Ritorna Size (o 1 se successo (commentato)); -1 se fallito*/
int addListTail(List l, Item el){
    if(isEmptyList(l)) {
        addHead(l, el); //se lista vuota aggiunta in coda equivale a aggiunta in testa
        return l->size;
    }
    struct node * oldTail = l->tail;
    struct node * newTail = malloc(sizeof(struct node));
        if(!newTail){fprintf(stderr, "\nFailed to Allocate Memory in %s\n", __func__); return -1;} //__func__ in C99 ok
    newTail->value = el;
    newTail->next = NULL;
    
    l->tail = newTail; //aggiorna coda in list
    oldTail->next = newTail; //aggiungi nodo a vecchia coda
    return ++(l->size);
    //return 1; 
}

/* -- COPIA LISTA E REVERSE -- */

/*Inverte internamente una lista, da controllare con printList la riuscita*/
void reverseList(List l){
    if(isEmptyList(l) || l->size == 1) return;
    struct node *temp, *prev, *next;
    temp = l->head;
    prev = NULL;
    while(temp){
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }
    l->tail = l->head;
    l->head = prev;
}

/* Ritorna una seconda Lista l2 con puntatori ai nodi di l! 
 * Ogni modifica a l sarà in l2 e viceversa!
 * NB Le funzioni di CloneList e CloneListItem in libreria dei prof potrebbero essere invertite!!*/
List cloneList(List l){
    List l2 = newList();
    l2->size = l->size;
    l2->head = l->head;
    l2->tail = l->tail;
    return l2;
}

/* Ritorna una copia completa di Lista l ma con sua allocazione di memoria.
 * Le modifiche a una non si ripercuotono sull'altra. */
List cloneListItem(List l){
    List copy = newList();
    int counter = 0;
    struct node * temp = l->head;
    for(; temp != NULL; temp = temp->next){
        addListTail(copy, temp->value);
        //printf("\n%s %d",__func__, counter++);
    }
    return copy;
}


/* -- FUNZIONI RICORSIVE -- */

/*Chiamata Ricorsiva Interna per Stampa Lista*/
void printListRec_Internal(struct node *t){
    if(!t) return;
    outputItem(t->value);
    printf(" ");
    printListRec_Internal(t->next);
}


/* - Main Func: PrintList Recursive*/
void printListRec(List l){
    struct node * temp = l->head;
    printListRec_Internal(temp);
}

/* Si potrebbero fare anche in una sola funzione senza funzione ombra, ma occuperebbe più spazio
 * allocando memoria per una lista temporanea di un solo elemento. 
 * Un esempio qui per printlist ma vale per quasi tutte le ricorsive. */

/* - Stampa Lista ricorsiva in una sola funzione, non disponibile fuori dal modulo*/
void printListRec_Alternative(List l){
    if(l->head == NULL) return;
    List temp = newList();
    temp->head = l->head->next;
    outputItem(l->head->value);
    printListRec_Alternative(temp);
    free(temp);
}

/*SearchList by Item Recursive Internal */
Item searchListRec_Internal(struct node *temp, Item el, int* pos){
    if(temp == NULL) {
        return NULL;
        *pos = -1;
    }
    if(cmpItem(temp->value, el) == 0) return temp->value;
    (*pos)++;
    return searchListRec_Internal(temp->next, el, pos);
}

/* - Main Func: SearchList by Item Recursive */
Item searchListRec(List l, Item el, int* pos){
    struct node *temp = l->head;
    *pos = 0;
    return searchListRec_Internal(temp,el,pos);
}

/*Internal ItemListRec*/
int countItemListRec_Internal(struct node *temp, Item el, int *count){
    if(temp == NULL) return -1; //valore di ritorno non usato per differente implementazione
    if(cmpItem(temp->value, el) == 0) (*count)++;
    return countItemListRec_Internal(temp->next, el, count);
}

/* - Main Func: Conta Numero di Ricorrenze di Item el in Lista*/
int countItemListRec(List l, Item el){
    if(isEmptyList(l)) return -1;
    struct node * temp = l->head;
    int count = 0;
    countItemListRec_Internal(temp, el, &count);
    return count;
}

/*Inverte Lista Ricorsivamente*/
void reverseListRecursive(List l){
    if(isEmptyList(l)) return;
    Item el = removeHead(l);
    reverseListRecursive(l);
    addListTail(l, el);
}


/*Distruggi tutti i nodi ma rimane la lista vuota*/
void destroyListRec(List l){
    if(isEmptyList(l)) return;
    //free(removeHead(l)); //commentato per testing senza allocazione dinamica degli item
    removeHead(l);
    destroyListRec(l);
}

/*-- FREE LIST --*/

/*Free List and all its nodes*/
int freeList(List l){
    while(!isEmptyList(l)){
        //free(removeHead(l)); //commentato per testing senza allocazione dinamica degli item
        removeHead(l);
    }
    free(l);
    return 1;
}