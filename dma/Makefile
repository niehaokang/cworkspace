usedma: usedma.o dma.o
	g++ -o usedma usedma.o dma.o
usedma.o: usedma.cpp dma.h
	g++ -c usedma.cpp
dma.o: dma.cpp dma.h
	g++ -c dma.cpp
clean:
	rm *.o usedma
