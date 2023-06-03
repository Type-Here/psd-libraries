#include "../item/item.h"

/*Definizione List pointer*/
typedef struct list *List;

/*Funzioni Base*/

List newList();
int isEmptyList(List);

void addHead(List, Item);
Item removeHead(List);
Item getHead(List);
Item getTail(List);

int sizeList(List);
void printList(List); 

/* - Funzioni di Ricerca ed Eliminazione Elemento - */

Item searchListItem(List, Item, int *);
Item removeListItem(List, Item);
Item removeListPos(List, int);

/* - Aggiunta Item - */

int addListPos(List, Item, int pos); //in posizione pos (indicizzata da zero a size-1)
int addListTail(List, Item); //aggiungi in coda

/*Funzioni di Reverse e Copia*/

void reverseList(List);
List cloneList(List);
List cloneListItem(List);


/*--Recursive Functions--*/

void printListRec(List); //printlist ricorsiva
Item searchListRec(List, Item, int*); //searchitem ricorsiva, pos passato per riferimento
int countItemListRec(List, Item); //Ritorna Numero di Occorrenze di Item in List; -1 se lista vuota, 0 se assente.

void reverseListRecursive(List); 

void destroyListRec(List); //Distruggi tutti i nodi ma rimane la lista vuota

/*--Free List--*/
int freeList(List);