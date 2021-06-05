blackjack: main.o Card.o Player.o
	g++ main.o Card.o Player.o -o blackjack

main.o: main.cpp
	g++ -c main.cpp

Card.o: Card.cpp Card.h
	g++ -c Card.cpp

Player.o: Player.cpp Player.h
	g++ -c Player.cpp

clean:
	rm *.o blackjack