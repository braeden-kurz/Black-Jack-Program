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
 * Player::Player(): Player constructor. Initializes the player's money
 * count to $100
 * 
 * return value: N/A
 */
Player::Player() {
    money = 100;
    bet = 0;
}

/*
 * Player::Player(int, int, Deck&): Customized player constructor. May
 * delete due to unnecessary use within program
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
 * Player::~Player(): Player deconstructor. Sets money and bet to 0 and
 * calls ClearDeck() to deallocate memory in the player's hand
 * 
 * Return Value: N/A
 */
Player::~Player() {
    money = 0;
    bet = 0;
    ClearDeck();
}

/*
 * int Player::getMoney() const: Getter function that returns the
 * player's count
 * 
 * Return Value: The money of the player
 */
int Player::getMoney() const {
    return money;
}


/*
 * int Player::getBet() const: Getter function that returns the bet
 * of the player
 * 
 * Return Value: The player's bet
 */
int Player::getBet() const {
    return bet;
}

/*
 * void Player::setBet(): Setter function that sets the player's
 * bet to the amount specified
 * 
 * Return Value: N/A
 */
void Player::setBet(int bet) {
    this->bet = bet;
}

/*
 * void Player::addMoney(int): Adds money to the player's account
 * 
 * Return Value: N/A
 */
void Player::addMoney(int num) {
    money += num;
}

/*
 * void Player::subMoney(int): Subtracts money from the player's account
 * 
 * Return Value: N/A
 */
void Player::subMoney(int num) {
    money -= num;
}

/*
 * int Player::getHandValue(): Getter function that returns the hand
 * value of the player
 * 
 * Return Value: The sum of the player's hand
 */
int Player::getHandValue() {
    int value = 0;
    for (int i = 0; i < GetSizeOfDeck(); i++) {
        value += (*this)[i]->card.getWeight();
    }
    return value;
}

/*
 * void Player::printPlayerStats(): Prints the player's account balance
 * the bet amount, the player's hand value, and the player's hand
 * 
 * Return Value: N/A
 */
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

/*
 * void Dealer::printFirstCard(): Prints the first card of the dealer's
 * hand
 * 
 * Return Value: N/A
 */
void Dealer::printFirstCard() {
    std::cout << (*this)[0]->card.printCard();
}

/*
 * void Dealer::printSecondCard(): Prints the second card of the dealer's
 * hand
 * 
 * Return Value: N/A
 */
void Dealer::printSecondCard() {
    std::cout << (*this)[1]->card.printCard();
}

/*
 * void Dealer::printHiddenCard(): Prints a hidden card of the dealer's
 * hand
 * 
 * Return Value: N/A
 */
void Dealer::printHiddenCard() {
    std::cout << "|[??]|";
}

/*
 * int Dealer::getFirstCardWeight(): Getter function that returns the
 * weight of the dealer's first card
 * 
 * Return Value: The weight of the dealer's card
 */
int Dealer::getFirstCardWeight() {
    return (*this)[0]->card.getWeight();
}

/*
 * int Dealer::getSecondCardWeight(): Getter function that returns the
 * weight of the dealer's seond card
 * 
 * Return Value: The weight of the dealer's second card
 */
int Dealer::getSecondCardWeight() {
    return (*this)[1]->card.getWeight();
}

/*
 * void Dealer::printDealerStats(): Prints the hand value and the hand
 * of the dealer
 * 
 * Return Value: N/A
 */
void Dealer::printDealerStats() {
    std::cout << "Dealer\n";
    std::cout << "-------------------\n";
    std::cout << "Hand Value: " << getHandValue() << std::endl;
    PrintDeck();
    std::cout << std::endl;
}