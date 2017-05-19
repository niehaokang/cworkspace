ab : a.o b.o
	g++ -o ab a.o b.o
a.o : a.c
	g++ -c a.c
b.o : b.c
	g++ -c b.c
clean:
	rm ab a.o b.o
