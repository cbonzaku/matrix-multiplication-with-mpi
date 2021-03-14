all: mpi
    

mpi: main.o initmatrix.o calculmatrix.o allocation.o
	mpicc -o mpi main.o initmatrix.o calculmatrix.o allocation.o

main.o: main.c
	mpicc -c main.c -o main.o

initmatrix.o: initmatrix.c
	gcc -c initmatrix.c -o initmatrix.o

calculmatrix.o: calculmatrix.c
	gcc -c calculmatrix.c -o calculmatrix.o

allocation.o: allocation.c
	gcc -c allocation.c -o allocation.o

clean: 
	rm -f main.o initmatrix.o calculmatrix.o allocation.o
