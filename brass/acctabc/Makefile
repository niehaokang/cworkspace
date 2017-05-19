acctabc : acctabc.o usebrass.o
	g++ -o acctabc acctabc.o usebrass.o
acctabc.o : acctabc.cpp acctabc.h
	g++ -c acctabc.cpp
usebrass.o : usebrass.cpp acctabc.h
	g++ -c usebrass.cpp
clean:
	rm brass1 brass.o usebrass1.o
