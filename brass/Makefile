brass1 : brass.o usebrass1.o
	g++ -o brass1 brass.o usebrass1.o
brass.o : brass.cpp brass.h
	g++ -c brass.cpp
usebrass1.o : usebrass1.cpp brass.h
	g++ -c usebrass1.cpp
clean:
	rm brass1 brass.o usebrass1.o
