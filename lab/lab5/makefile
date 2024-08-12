ES_NAME := play
FLAGS := -Wall -Wextra
ITEM_TYPE := item_str

link : lista main playlist song item_struct
	gcc $(FLAGS) lista.o main.o playlist.o song.o item_struct.o -o $(ES_NAME).exe

link-str :  lista main item_str 
	gcc $(FLAGS) lista.o main.o item_str.o -o $(ES_NAME).exe

link-struct :  lista main playlist song item_struct
	gcc $(FLAGS) lista.o main.o playlist.o song.o item_struct.o -o $(ES_NAME).exe

item_struct :
	gcc -c item_struct.c
	
playlist :
	gcc -c playlist.c

song :
	gcc -c song.c

item_str :
	gcc -c item_str.c

item_int :
	gcc -c item_int.c
	
lista :
	gcc -c lista.c

array :
	gcc -c array.c

utils :
	gcc -c utils.c

main : 
	gcc -c main.c

clean : 
	rm -f *.o *.exe

