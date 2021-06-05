#ifndef CARD_H
#define CARD_H
#include "Card.h"
#endif

#ifndef IO_H
#define IO_H
#include <iostream>
#endif

#ifndef RAND_H
#define RAND_H
#include <stdlib.h> 
#include <time.h>
#endif

/*******************************
 *  PLAYER CLASS 
*******************************/

class Player: public Deck {
    private:
        int money;
        int bet;
    public:
        Player();
        Player(int money, int bet, Deck& dealingDeck);
        ~Player();
        int getMoney() const;
        int getBet() const;
        int getHandValue();
        void setBet(int bet);
        void printPlayerStats();

};

class Dealer: public Player {
    public:
        void printFirstCard();
        void printSecondCard();
        void printHiddenCard();
        int getSecondCardWeight();
        int getFirstCardWeight();
        void printDealerStats();
};