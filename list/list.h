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

int addListPos(List, Item, int);
int addListTail(List, Item);

/*Funzioni di Reverse e Copia*/

void reverseList(List);
List cloneList(List);
List cloneListItem(List);


/*--Recursive Functions--*/
void printListRec(List);
Item searchListRec(List, Item, int*);
int countItemListRec(List, Item);
void destroyListRec(List);

void reverselist_rec(List);