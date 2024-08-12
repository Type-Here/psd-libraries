#include <stdio.h>
#include <string.h>

#include "btree.h"
#include "item.h"

int main(){
	BTree h,a,c,d,l,p,s,o,q;
	BTree compare1, cmpleaf, compare4;
	
	/*Alberi vuoti*/
	BTree compare2 = newTree(); 
	BTree compare3 = newTree();
	
	int node_number;
	int altezza;
	Item el, search;
	int i3 = 3, i4 = 4, i5 = 5, i20 = 20, i6 = 6, i7 = 7, i8 = 8, i1 = 1, i2 = 2;
	int i15 = 15, i0 = 0;
	
	/*Foglie*/
	q = buildTree(NULL, NULL, (Item) &i3);
	d = buildTree(NULL, NULL, (Item) &i4);
	o = buildTree(NULL, NULL, (Item) &i5);
	p = buildTree(NULL, NULL, (Item) &i20);
	s = buildTree(NULL, NULL, (Item) &i6);
	
	/*SottoAlberi*/
	l = buildTree(o, q, (Item) &i7);
	a = buildTree(d, l, (Item) &i8);
	c = buildTree(p, s, (Item) &i1);
	
	/*Radice*/
	h = buildTree(a, c, (Item) &i2);
	
	/*Costruiamo compare1*/
	cmpleaf = buildTree(NULL, NULL, (Item) &i0);
	compare1 = buildTree(cmpleaf, q, (Item) &i15);
	
	compare4 = buildTree(q, cmpleaf, (Item) &i15);
	
	
	/*compare2 e compare3 vuoti*/
	
	printf("\nIl nostro albero (preOrder): ");
	preOrder(h);
	
	node_number = btreeNodeNumber(h);
	printf("\n\nNumero nodi totali = %d", node_number);
	
	altezza = btreeHeight(h);
	printf("\nAltezza albero binario= %d", altezza);
	
	//Search
	/*PRE: tree != nil; (item != nil)
	 *POST: Item found = return tree->value; if not found or tree is empty: return NULL;
	 */
	
	printf("\nCerca un elemento: ");
	el = inputItem();
	search = searchItemBTree(h, el);
	if(!search) printf("\nItem non trovato\n");
	else{
		printf("\nItem trovato :");
		outputItem(search);
		printf("\n");
	}
	printf("\nIl massimo in albero: ");
	outputItem(maxItemBTree(h));
	//Max
	/*PRE: tree != nil;
	 *POST: Item max_found = max(tree values); if tree is empty return NULL*/
	 
	//areEqualBtrees
	/* PRE: tree != nil;
	 * POST: Return 1 if are equal; 0 if they aren't. */
	printf("\nConfronto fra due alberi:\n");
	printf("\n- Confrontiamo prima l'albero con sé stesso\n");
	printf("\nAlbero 1: ");
	preOrder(h);
	printf("\nAlbero 2: ");
	preOrder(h);
	if(areEqualBtrees(h, h)) {
		printf("\n\tI due alberi sono uguali.\n");
	}else{
		printf("\n\tI due alberi sono diversi.\n");
	}
	
	printf("\n- Confrontiamo due alberi diversi\n");
	printf("\nAlbero 1: ");
	preOrder(h);
	printf("\nAlbero 2: ");
	preOrder(compare1);
	if(areEqualBtrees(h, compare1)) {
		printf("\n\tI due alberi sono uguali.\n");
	}else{
		printf("\n\tI due alberi sono diversi.\n");
	}
	
	printf("\n- Confrontiamo 2 alberi vuoti\n");
	printf("\nAlbero 1: ");
	preOrder(compare2);
	printf("\nAlbero 2: ");
	preOrder(compare3);
	if(areEqualBtrees(compare2, compare3)) {
		printf("\n\tI due alberi sono uguali.\n");
	}else{
		printf("\n\tI due alberi sono diversi.\n");
	}
	
	printf("\n- Confrontiamo infine 2 alberi simmetrici\n");
	printf("\nAlbero 1: ");
	preOrder(compare1);
	printf("\nAlbero 2: ");
	preOrder(compare4);
	if(areEqualBtrees(compare1, compare4)) {
		printf("\n\tI due alberi sono uguali.\n");
	}else{
		printf("\n\tI due alberi sono diversi.\n");
	}
	
	
	
	printf("\n\n END\n");
	
	freeBTree(h);
	return 0;
}