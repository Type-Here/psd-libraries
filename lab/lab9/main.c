#include <stdio.h>
#include <string.h>

#include "btree.h"
#include "item.h"

int main(){
	BTree h,a,c,d,l,p,s,o,q;
	int node_number;
	int altezza;
	
	/*Foglie*/
	q = buildTree(NULL, NULL, "q");
	d = buildTree(NULL, NULL, "d");
	o = buildTree(NULL, NULL, "o");
	p = buildTree(NULL, NULL, "p");
	s = buildTree(NULL, NULL, "s");
	
	/*SottoAlberi*/
	l = buildTree(o, q, "l");
	a = buildTree(d, l, "a");
	c = buildTree(p, s, "c");
	
	/*Radice*/
	h = buildTree(a, c, "h");
		
	node_number = btreeNodeNumber(h);
	printf("\n\n Numero nodi totali = %d", node_number);
	
	altezza = btreeHeight(h);
	printf("\n Altezza albero binario= %d", altezza);
	
	printf("\n\nPrint per Livelli dell'albero: ");
	print_binary_tree_per_level(h); 
	printf("\n\n");
	
	printf("\nPreorder Recursive: ");
	preOrder(h);
	printf("\nPreorder Iterative: ");
	PreOrder_Iterative(h);
	
	printf("\n\nPostorder Recursive: ");
	postOrder(h);
	printf("\nPostorder Iterative: ");
	PostOrder_Iterative(h);
	
	printf("\n\nInorder (simmetrica): ");
	inOrder(h);
	printf("\nInorder Iterative: ");
	InOrder_Iterative(h);
	
	
	printf("\n\n END\n");
	
	freeBTree(h);
	return 0;
}