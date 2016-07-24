CC=gcc
CFLAGS=-I. -pthread -g 
OBJ = example02-mutex.c

%.o: %.c 
	$(CC) -c -o $@  $< $(CFLAGS)

threads_t : $(OBJ)
	gcc -o $@ $^ $(CFLAGS)

clean : 
	rm *.o threads_t
