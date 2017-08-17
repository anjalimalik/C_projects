all: libmymathlib.so mymain

CC = gcc 
OBJ = main.o read_vectors.o calc_dotmag.o calc_diff.o calc_power.o 
CFLAGS = -c -fPIC

libmymathlib.so: $(OBJ)
		$(CC) -shared -o libmymathlib.so $(OBJ)

main.o: main.c dotheader.h
	$(CC) $(CFLAGS) main.c
read_vectors.o: read_vectors.c dotheader.h
	$(CC) $(CFLAGS) read_vectors.c
calc_diff.o: calc_diff.c dotheader.h
	$(CC) $(CFLAGS) calc_diff.c
calc_dotmag.o: calc_dotmag.c dotheader.h
	$(CC) $(CFLAGS) calc_dotmag.c
calc_power.o: main.c dotheader.h
	$(CC) $(CFLAGS) calc_power.c

mymain: $(OBJ)
	$(CC) -o mymain main.o -L . -l mymathlib -lm 
		

