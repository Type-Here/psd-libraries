# makefile
# usare tab non spazi, attenzione spaziatura

DIR_FLAG := -I..
SOURCE := ..
ERR_FLAG := -Wall -Wextra

ES_NAME = main

link : utils.o vettore.o $(ES_NAME).o
	gcc $(DIR_FLAG) $(ERR_FLAG) utils.o vettore.o $(ES_NAME).o -o $(ES_NAME).exe
	
utils.o :
	gcc -c $(SOURCE)/utils.c .
	
vettore.o :
	gcc -c $(SOURCE)/vettore.c .
	
$(ES_NAME).o :
	gcc -c $(DIR_FLAG) $(ES_NAME).c

.PHONY: clean cleanall

clean :
	rm -f utils.o vettore.o $(ES_NAME).o

cleanall :
	rm -f utils.o vettore.o $(ES_NAME).o $(ES_NAME).exe