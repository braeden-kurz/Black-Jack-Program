#ifndef CARD_H
#define CARD_H
#include "Card.h"
#endif

/*******************************
 *  CARD CLASS 
*******************************/

/*
 * Card::Card(): Initializes the card object to null characters and sets
 * the weight to an abitrary value (-999 in this case)
 *
 * Return value: N/A
 */
Card::Card() {
    suit = '\0';
    value = '\0';
    weight = 0;
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
Card::Card(char suit, char value) {
    this->suit = suit;
    this->value = value;
    switch(value) {
        case 'A':
        case 'K':
        case 'Q':
        case 'J':
        case 'T':
            weight = 10;
            break;
        case '9':
            weight = 9;
            break;
        case '8':
            weight = 8;
            break;
        case '7':
            weight = 7;
            break;
        case '6':
            weight = 6;
            break;
        case '5':
            weight = 5;
            break;
        case '4':
            weight = 4;
            break;
        case '3':
            weight = 3;
            break;
        case '2':
            weight = 2;
            break;
        default:
            break;
    }
}

std::string Card::printCard() const {
    std::string thisCard;
    thisCard += '|';
    thisCard += '[';
    thisCard += suit;
    thisCard += value;
    thisCard += ']';
    thisCard += '|';
    return thisCard;
}

char Card::getValue() const {
    return value;
}

char Card::getSuit() const {
    return suit;
}

int Card::getWeight() const {
    return weight;
}

bool Card::operator<(Card rhsCard) const {
    return this->getValue() < rhsCard.getValue();
}

bool Card::operator>(Card rhsCard) const {
    return this->getValue() > rhsCard.getValue();
}

bool Card::operator!=(Card rhsCard) const {
    return this->getValue() != rhsCard.getValue() &&
            this->getSuit() != rhsCard.getSuit();
}

bool Card::operator==(Card rhsCard) const {
    return this->getValue() == rhsCard.getValue() &&
            this->getSuit() == rhsCard.getSuit();
}

/*******************************
 *  DECK CLASS 
*******************************/

Deck::Deck() {
    head = NULL;
    sizeOfDeck = 0;
}

Deck::~Deck() {
    ClearDeck();
}

void Deck::AddToTopOfDeck(Card card) {
    Hand* newHand = new Hand;
    newHand->card = card;
    newHand->next = head;
    head = newHand;
    ++sizeOfDeck;
}

Card Deck::RemoveTopCard() {
    Hand* temp = new Hand;
    temp->card = head->card;
    temp = head->next;
    delete head;
    head = temp;
    --sizeOfDeck;
    return head->card;
}

void Deck::ShuffleDeck() {
    for (int i = 0; i < GetSizeOfDeck(); i++) {
        SwapCards((*this)[i], (*this)[GetRandomCardIndex()]);
    }
}

void Deck::ClearDeck() {
    Hand* temp = NULL;

    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }
    sizeOfDeck = 0;
}

void Deck::SwapCards(Hand* h1, Hand* h2) {
    Card temp = h1->card;
    h1->card = h2->card;
    h2->card = temp;
}

int Deck::GetSizeOfDeck() const {
    return sizeOfDeck;
}

int Deck::GetRandomCardIndex() const {
    return (rand() % sizeOfDeck);
}

void Deck::PrintDeck() {
    std::cout << "-------------------------" << std::endl;
    for(int i = 0; i < sizeOfDeck; i++){
        std::cout << (*this)[i]->card.printCard();
        if((i + 1) % 4 == 0){
            std::cout << std::endl;
        }
    }
    std::cout << std::endl << "-------------------------" << std::endl;
}

/*
 * Deck::Node* Deck::operator[](int): Returns the index of the linked
 * list. Makes indexing/finding specific elements in the list much
 * easier
 * 
 * int index: The so-called 'index' of the linked list
 * 
 * Return Value: The indexed node of the list
 *
 */
Deck::Hand* Deck::operator[](int index) {
    Hand* temp = new Hand;
    temp = head;

    int iterate = 0;

    while (iterate < index) {
        if (index > sizeOfDeck || index < 0) {
            break;
        }
        temp = temp->next;
        iterate++;
    }
    return temp;
}