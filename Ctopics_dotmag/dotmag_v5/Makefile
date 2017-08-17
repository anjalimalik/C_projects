all: dotprodcomplex

CC=gcc

OPTIONS=-lm -o

dotprodcomplex: main.c read_vectors_complex.c calc_dotprod_complex.c
	$(CC) -c read_vectors_complex.c
	$(CC) -c calc_dotprod_complex.c
	$(CC) -c main.c
	$(CC) $(OPTIONS) dotprodcomplex read_vectors_complex.o calc_dotprod_complex.o main.o
clean:
	rm -f *.o *.out
	                
