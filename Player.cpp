#ifndef PLAYER_H
#define PLAYER_H
#include "Player.h"
#endif

#ifndef IOMANIP_H
#define IOMNAIP_H
#include <iomanip>
#endif

/*******************************
 *  PLAYER CLASS 
*******************************/

/*
 * Card::Card(char, char): Sets the suit and value of the card to that
 * of the specified parameter variables. Sets the weight of the card
 * based on the suit and 
 * 
 * char suit: The suit of the card (Clubs, Spades, etc)
 * 
 * car value: The number or type of card that carries weight
 * (ace, king, 9, etc)
 * 
 * Return Value: N/A
 */
Player::Player() {
    money = 500;
    bet = 0;
}

/*
 * Card::Card(char, char): Sets the suit and value of the card to that
 * of the specified parameter variables. Sets the weight of the card
 * based on the suit and 
 * 
 * char suit: The suit of the card (Clubs, Spades, etc)
 * 
 * car value: The number or type of card that carries weight
 * (ace, king, 9, etc)
 * 
 * Return Value: N/A
 */
Player::Player(int money, int bet, Deck& dealingDeck) {
    this->money = money;
    this->bet = bet;
    AddToTopOfDeck(dealingDeck.RemoveTopCard());
    AddToTopOfDeck(dealingDeck.RemoveTopCard());
}

/*
 * Card::Card(char, char): Sets the suit and value of the card to that
 * of the specified parameter variables. Sets the weight of the card
 * based on the suit and 
 * 
 * char suit: The suit of the card (Clubs, Spades, etc)
 * 
 * car value: The number or type of card that carries weight
 * (ace, king, 9, etc)
 * 
 * Return Value: N/A
 */
Player::~Player() {
    money = 0;
    bet = 0;
    ClearDeck();
}

/*
 * Card::Card(char, char): Sets the suit and value of the card to that
 * of the specified parameter variables. Sets the weight of the card
 * based on the suit and 
 * 
 * char suit: The suit of the card (Clubs, Spades, etc)
 * 
 * car value: The number or type of card that carries weight
 * (ace, king, 9, etc)
 * 
 * Return Value: N/A
 */
int Player::getMoney() const {
    return money;
}

/*
 * Card::Card(char, char): Sets the suit and value of the card to that
 * of the specified parameter variables. Sets the weight of the card
 * based on the suit and 
 * 
 * char suit: The suit of the card (Clubs, Spades, etc)
 * 
 * car value: The number or type of card that carries weight
 * (ace, king, 9, etc)
 * 
 * Return Value: N/A
 */
int Player::getBet() const {
    return bet;
}

void Player::setBet(int bet) {
    this->bet = bet;
}

int Player::getHandValue() {
    int value = 0;
    for (int i = 0; i < GetSizeOfDeck(); i++) {
        value += (*this)[i]->card.getWeight();
    }
    return value;
}

void Player::printPlayerStats() {
    std::cout << "Player\n";
    std::cout << "-------------------------\n";
    std::cout << "Money: " << getMoney() << std::endl;    
    std::cout << "Bet: " << getBet() << std::endl;
    std::cout << "Hand Value: " << getHandValue() << std::endl;
    PrintDeck();
    std::cout << std::endl << std::endl;
}

/*******************************
 *  DEALER CLASS 
*******************************/

void Dealer::printFirstCard() {
    std::cout << (*this)[0]->card.printCard();
}

void Dealer::printSecondCard() {
    std::cout << (*this)[1]->card.printCard();
}

void Dealer::printHiddenCard() {
    std::cout << "|[??]|";
}

int Dealer::getFirstCardWeight() {
    return (*this)[0]->card.getWeight();
}

int Dealer::getSecondCardWeight() {
    return (*this)[1]->card.getWeight();
}

void Dealer::printDealerStats() {
    std::cout << "Dealer\n";
    std::cout << "-------------------\n";
    std::cout << "Hand Value: " << getHandValue() << std::endl;
    PrintDeck();
    std::cout << std::endl;
}