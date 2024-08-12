#include "btree.h"
#include "item.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inOrderFormula(BTree t, int check){
	if(isEmptyTree(t)) return; //P.B.
	if(getLeft(t) && getRight(t) && check) printf("(");
	inOrderFormula(getLeft(t), 1);
	outputItem(getBTreeRoot(t));
	inOrderFormula(getRight(t), 1);
	if(getLeft(t) && getRight(t) && check) printf(")");
}


int main(){
	BTree t11, t14, t1, t6, t2, tplus, tminus, tdiv, tper;
	t11=buildTree(NULL,NULL,"11");
	t14=buildTree(NULL,NULL,"14");
	t1=buildTree(NULL,NULL,"1");
	t6=buildTree(NULL,NULL,"6");
	t2=buildTree(NULL,NULL,"2");
	tplus=buildTree(t11,t14,"+");
	tminus=buildTree(tplus,t1,"-");
	tper=buildTree(t6,t2,"*");
	tdiv=buildTree(tminus,tper,"/");

	BTree rad = tdiv;

	/*printf("preorder:\t");
	preOrder(rad);
	printf("\npostorder:\t");
	postOrder(rad);
	printf("\ninorder:\t");
	inOrder(rad); */
	printf("\n\nFormula Originale:\t");
	inOrderFormula(rad, 0);

	return 0;
}