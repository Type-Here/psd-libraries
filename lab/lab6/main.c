/* ESERCIZIO LABORATORIO 6: PARENTESI BILANCIATE DI UNA ESPRESSIONE */
/* --- Uso dello stack --- */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack.h"
#include "item.h"

#define BUFFER 50

int check_balance(char*);
void input_expression();
int brackets_compare(char, char);

int main (){
	printf("Verifichiamo bilanciamento parentesi espressioni.\n");
	printf("Inserisci la tua espressione qui: \n\t$ ");
	char exp[BUFFER];
	//input_expression(exp);
	fgets(exp, BUFFER, stdin);
	
	printf("\n\nLa stringa considerata è %s\n", exp);
	
	if(check_balance(exp)){
		printf("\nCheck superato.\n");	
	} else {
		printf("\nCheck non superato\n");
	}
	
	return 0;
}


int check_balance(char* a){
	Stack parentesi = newStack();
	int i = 0;
	
	while(a[i] != '\0'){
		if(a[i] == '(' || a[i] == '[' || a[i] == '{'){
			Item el = &(a[i]);
			
			push(parentesi, el);
			
			printf("\nInserito %c", a[i]);
			printf("\tElementi in Stack = %d\n", stackDim(parentesi));
			
		} else if(a[i] == ')' || a[i] == ']' || a[i] == '}'){
			if(top(parentesi) == NULL) return 0;
			else{
				char *head = (char *) top(parentesi);
				printf("\nHead = %d", *head);
				if(brackets_compare(*head,(int)a[i])) {
					char * rimosso = (char *) pop(parentesi);
					printf("\nRimosso = %c", *rimosso);
					printf("\tElementi in Stack = %d\n", stackDim(parentesi));
					}
				else return 0;
			}
		}
		i++;
	}
	if(isEmptyStack(parentesi))	{
		printf("\nStack Vuota.\n");
		freeStack(parentesi);
		return 1;
		}
	else {
		freeStack(parentesi);
		return 0;
	}
	//freeStack(parentesi);
	return 1;
}

void input_expression(char** a){
	fgets(*a, BUFFER, stdin);
}

int brackets_compare(char a, char b){
	if(a == 40 && b == 41) return 1;  //Ascii Char (=40  )=41
	else if(a == 91 && b == 93) return 1; //Ascii for []
	else if(a == 123 && b == 125) return 1; // Ascii for {}
	return 0;
}