ES_NAME:=selection_rec

link : utils vettore item_int main
	gcc utils.o vettore.o item_int.o main.o -o $(ES_NAME)

link_str: utils vettore item_str main
	gcc utils.o vettore.o item_str.o main.o -o $(ES_NAME)

vettore :
	gcc -c vettore.c

utils :
	gcc -c utils.c

item_str :
	gcc -c item_str.c

item_int :
	gcc -c item_int.c

main : 
	gcc -c main.c

clean : 
	rm -f *.o $(ES_NAME)

