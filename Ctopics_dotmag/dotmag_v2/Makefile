all: dotmag archive add

dotmag: main.c read_vectors.c calc_dotmag.c
			gcc -g -o mymain main.c read_vectors.c calc_dotmag.c calc_diff.c -lm

archive: 
			gcc -c main.c -c read_vectors.c -c calc_dotmag.c -c calc_diff.c -lm

add: 
		ar rcs libmymath.a read_vectors.o calc_diff.o calc_dotmag.o
push:
		gcc -o mymain main.o -static -L -lib -l mymath -lm
