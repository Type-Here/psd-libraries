ES_NAME:=rev_coda_rec

link : list coda_list item_int main
	gcc list.o coda_list.o item_int.o main.o -o $(ES_NAME)

link_array: coda_array item_int main
	gcc coda_array.o item_int.o main.o -o $(ES_NAME)

vettore :
	gcc -c vettore.c

list :
	gcc -c list.c
	
coda_list :
	gcc -c coda_list.c

coda_array :
	gcc -c coda_array.c
	
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

