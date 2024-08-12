# makefile
# usare tab non spazi, attenzione spaziatura

DIR_FLAG := -I..
SOURCE := ..
ERR_FLAG := -Wall -Wextra

ES_NAME = lab1

link : utils.o vettor.o $(ES_NAME).o
	gcc $(DIR_FLAG) $(ERR_FLAG) utils.o vettor.o $(ES_NAME).o -o $(ES_NAME).exe
	
utils.o :
	gcc -c $(SOURCE)/utils.c .
	
vettor.o :
	gcc -c $(SOURCE)/vettor.c .

$(ES_NAME).o :
	gcc -c $(DIR_FLAG) $(ES_NAME).c

.PHONY: clean cleanall

clean :
	rm -f utils.o vettor.o $(ES_NAME).o

cleanall :
	rm -f utils.o vettor.o $(ES_NAME).o $(ES_NAME).exe