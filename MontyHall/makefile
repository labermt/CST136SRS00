CC := g++
CFLAGS := -g -Wall

OBJECTS := LetsMakeADeal.o main.o

simulation: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o simulation

LetsMakeADeal.o: LetsMakeADeal.cpp
	$(CC) -c LetsMakeADeal.cpp

main.o: main.cpp
	$(CC) -c main.cpp

clean:
	rm -rf simulation *.o
