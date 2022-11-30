# Compilator's variables

CC := gcc
FLAGS :=
DELETE := del	# Windows
FILES := $(wildcard *.c)
OBJ := $(FILES:.c=.o)

all: main

# Last execution

main: $(OBJ)
	$(CC) $(FLAGS) $^ -o $@ -lm
	$(DELETE) *.o
	./main

# All files obj compilation

%.o: %.c headers/%.h
	$(CC) $(FLAGS) -o $@ -c $<

# May come in handy

clear:
	$(DELETE) *.o ; $(DELETE) main.exe