ES_NAME:=stack

link : stack_array item_int main
	gcc stack_array.o item_int.o main.o -o $(ES_NAME)

link_list: stack_list list item_int main
	gcc stack_list.o list.o item_int.o main.o -o $(ES_NAME)

item_str :
	gcc -c item_str.c

item_int :
	gcc -c item_int.c

stack_array:
	gcc -c stack_array.c

stack_list:
	gcc -c stack_list.c

list :
	gcc -c list.c

main : 
	gcc -c main.c

clean : 
	rm -f *.o $(ES_NAME)

