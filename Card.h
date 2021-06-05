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
 *  CARD CLASS 
*******************************/

class Card {
    private:
        char value;
        char suit;
        int weight;
    public:
        Card(); // Default constructor
        Card(char suit, char value); // Custom constructor
        std::string printCard() const; // Prints card
        char getValue() const;
        char getSuit() const;
        int getWeight() const;
        bool operator<(Card rhsCard) const; // Compares LHS < RHS
        bool operator>(Card rhsCard) const; //Compares LHS > RHS
        bool operator!=(Card rhsCard) const;
        bool operator==(Card rhsCard) const;
};

/*******************************
 *  DECK CLASS 
*******************************/

class Deck {
    private:
        struct Hand {
            Card card;
            Hand* next;
        };
        Hand* head;
        int sizeOfDeck;
    protected:
        Hand* operator[](int index);
    public:
        // Default Constructor
        Deck();
        // Rule of Three
        ~Deck();
        //void operator=(const Deck &copy);
        //Deck(const Deck &copy);
        // Member Functions
        void AddToTopOfDeck(Card card);
        Card RemoveTopCard();
        void ShuffleDeck();
        void ClearDeck();
        //void SortDeck();
        void SwapCards(Hand* n1, Hand* n2);
        // Getters
        int GetSizeOfDeck() const;
        //bool isEmpty() const;
        int GetRandomCardIndex() const;
        void PrintDeck();
};