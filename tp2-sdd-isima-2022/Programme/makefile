Programme:objet/file.o objet/pile.o objet/main.o
	gcc -o Programme objet/file.o objet/pile.o objet/main.o -g

objet/main.o:sources/main.c headers/pile.h
	gcc -c sources/main.c -Wall -Wextra -o objet/main.o -g

objet/pile.o:sources/pile.c headers/pile.h headers/file.h
	gcc -c sources/pile.c -Wall -Wextra -o objet/pile.o -g

objet/file.o:sources/file.c headers/file.h
	gcc -c sources/file.c -Wall -Wextra -o objet/file.o -g

