all: dotmag

CC=gcc

OPTIONS=-lm -o

dotmag: main.c read_vectors.c calc_dotmag.c
	$(CC) -c read_vectors.c
	$(CC) -c calc_dotmag.c
	$(CC) -c main.c
	$(CC) $(OPTIONS) dotmag read_vectors.o calc_dotmag.o main.o
clean:
	rm -f *.o *.out
	                
