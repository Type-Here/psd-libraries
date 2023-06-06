typedef void* Item;

Item inputItem();
void outputItem(Item);
int cmpItem(Item,Item);

/*Funzione Per Stampare BTree visivamente, non necessaria saperla*/
void outputItemLen(Item it, int len);

/*Funzione Per generare BTree casuali, non necessaria saperla*/
Item randomItem();