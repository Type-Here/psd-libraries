ES_NAME:=lab10

link : list coda stack btree item_int main
	gcc list.o coda_list.o stack_list.o btree.o item_int.o main.o -o $(ES_NAME)

link_str : list coda stack btree item_str main
	gcc list.o btree.o coda_list.o stack_list.o item_str.o main.o -o $(ES_NAME)

stack :
	gcc -c stack_list.c
	
list :
	gcc -c list.c
	
coda :
	gcc -c coda_list.c

item_str :
	gcc -c item_str.c

item_int :
	gcc -c item_int.c
	
btree :
	gcc -c btree.c

main : 
	gcc -c main.c

clean : 
	rm -f *.o $(ES_NAME)

