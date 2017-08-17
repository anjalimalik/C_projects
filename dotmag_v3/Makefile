all: libmymathlib.so mymain

libmymathlib.so: main.o read_vectors.o calc_dotmag.o calc_diff.o calc_power.o
		gcc -shared -o libmymathlib.so main.o read_vectors.o calc_dotmag.o calc_diff.o calc_power.o

main.o: main.c dotheader.h
	gcc -c -fPIC main.c
read_vectors.o: read_vectors.c dotheader.h
	gcc -c -fPIC read_vectors.c
calc_diff.o: calc_diff.c dotheader.h
	gcc -c -fPIC calc_diff.c
calc_dotmag.o: calc_dotmag.c dotheader.h
	gcc -c -fPIC calc_dotmag.c
calc_power.o: main.c dotheader.h
	gcc -c -fPIC calc_power.c

mymain: main.o read_vectors.o calc_dotmag.o calc_diff.o calc_power.o
	gcc -o mymain main.o -L . -l mymathlib -lm 
		

