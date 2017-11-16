fork: main.o
	gcc -o fork main.o
	make clean

main.o: main.c
	gcc -c main.c

clean:
	rm *.o

run:
	./fork
