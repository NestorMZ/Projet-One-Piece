#Makefile de l'equipage de Luffy 
#MARTINEZ-AJANOHOUN
#ETE 2018

EXEC = Dumbal

#nom du compilateur et options de compilation
CC = g++
CFLAGS = -Wall -Wextra -pedantic

OBJS  = main.o Carte.o Joueur.o 

all : $(EXEC)

$(EXEC) : $(OBJS)
	$(CC) -o $@ $(OBJS) 

Joueur.o : Joueur.cpp Joueur.h
	$(CC) $(CFLAGS) -c $<

Carte.o : Carte.cpp Carte.h
	$(CC) $(CFLAGS) -c $<

main.o : main.cpp Carte.h Joueur.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm $(OBJS) $(EXEC)
