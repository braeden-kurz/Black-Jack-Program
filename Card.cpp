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

/*
 * std::string Card::printCard() const: Prints the card of the player/
 * dealer
 * 
 * Return Value: The card, along with it's suit and value
 */
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

/*
 * char Card::getValue() const: Getter function that returns the weight
 * of the card
 * 
 * Return Value: The value of the card
 */
char Card::getValue() const {
    return value;
}

/*
 * char Card::getSuit() const: Getter function that returns the the suit
 * of the card
 * 
 * Return Value: The suit of the card
 */
char Card::getSuit() const {
    return suit;
}

/*
 * int Card::getWeight() const: Getter function that returns the weight
 * of the card
 * 
 * Return Value: The weight of the card
 */
int Card::getWeight() const {
    return weight;
}

/*
 * bool Card::operator<(Card) const: Compares the value of two cards
 * 
 * Card rhsCard: The right-hand card being compared
 * 
 * Return Value: A boolean comparison of the left and right hand-cards
 */
bool Card::operator<(Card rhsCard) const {
    return this->getValue() < rhsCard.getValue();
}

/*
 * bool Card::operator>(Card) const: Compares the value of two cards
 * 
 * Card rhsCard: The right-hand card being compared
 * 
 * Return Value: A boolean comparison of the left and right hand-cards
 */
bool Card::operator>(Card rhsCard) const {
    return this->getValue() > rhsCard.getValue();
}

/*
 * bool Card::operator!=(Card) const: Compares the value of two cards
 * 
 * Card rhsCard: The right-hand card being compared
 * 
 * Return Value: A boolean comparison of the left and right hand-cards
 */
bool Card::operator!=(Card rhsCard) const {
    return this->getValue() != rhsCard.getValue() &&
            this->getSuit() != rhsCard.getSuit();
}

/*
 * bool Card::operator==(Card) const: Compares the value of two cards
 * 
 * Card rhsCard: The right-hand card being compared
 * 
 * Return Value: A boolean comparison of the left and right hand-cards
 */
bool Card::operator==(Card rhsCard) const {
    return this->getValue() == rhsCard.getValue() &&
            this->getSuit() == rhsCard.getSuit();
}

/*******************************
 *  DECK CLASS 
*******************************/

/*
 * Deck::Deck(): Deck contructor that sets the sizeOfDeck variable to 0
 * and sets the head node to NULL
 * 
 * Card rhsCard: The right-hand card being compared
 * 
 * Return Value: A boolean comparison of the left and right hand-cards
 */
Deck::Deck() {
    head = NULL;
    sizeOfDeck = 0;
}

/*
 * Deck::~Deck(): Deck deconstructor that calls ClearDeck() to
 * deallocate the deck
 * 
 * Return Value: N/A
 */
Deck::~Deck() {
    ClearDeck();
}

/*
 * void Deck::AddToTopOfDeck(Card): Places a new card to the head node of
 * the deck, making it the first card of the deck
 * 
 * Card card: The card to be added to the top (head node) of the deck
 * 
 * Return Value: N/A
 */
void Deck::AddToTopOfDeck(Card card) {
    Hand* newHand = new Hand;
    newHand->card = card;
    newHand->next = head;
    head = newHand;
    ++sizeOfDeck;
}

/*
 * Card Deck::RemoveTopCard(): Takes the top card of the deck
 * deallocates the card, pushes the next card to the top and decrements
 * the sizeOfDeck
 * 
 * Return Value: The card of the deck being removed
 */
Card Deck::RemoveTopCard() {
    Hand* temp = new Hand;
    temp->card = head->card;
    temp = head->next;
    delete head;
    head = temp;
    --sizeOfDeck;
    return head->card;
}

/*
 * void Deck::ShuffleDeck(): Randomly swaps the place of the cards within
 * the deck
 * 
 * Return Value: N/A
 */
void Deck::ShuffleDeck() {
    for (int i = 0; i < GetSizeOfDeck(); i++) {
        SwapCards((*this)[i], (*this)[GetRandomCardIndex()]);
    }
}

/*
 * void Deck::ClearDeck(): Deallocates the deck and sets the sizeOfDeck
 * variable to 0
 * 
 * Return Value: N/A
 */
void Deck::ClearDeck() {
    Hand* temp = NULL;

    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }
    sizeOfDeck = 0;
}

/*
 * voiid Deck::SwapCards(Hand*, Hand*): Changes the place of the cards
 * in the deck
 * 
 * Hand* h1, h2: The cards being swapped
 * 
 * Return Value: N/A
 */
void Deck::SwapCards(Hand* h1, Hand* h2) {
    Card temp = h1->card;
    h1->card = h2->card;
    h2->card = temp;
}

/*
 * int Deck::GetSizeOfDeck() const: Returns the the size of the deck
 * 
 * Return Value: An integer value representing the number of cards
 * in the deck
 */
int Deck::GetSizeOfDeck() const {
    return sizeOfDeck;
}

/*
 * int Deck::GetRandomCardIndex() const: Using rand, this function
 * returns a random number that's within the size of the deck
 * 
 * Return Value: A random integer value of that will be used to grab a
 * random card fro the deck
 */
int Deck::GetRandomCardIndex() const {
    return (rand() % sizeOfDeck);
}

/*
 * void Deck::PrintDeck(): Simply prints the deck
 * 
 * Return Value: N/A
 */
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
 * Deck::Hand* Deck::operator[](int): Returns the index of the deck.
 * Makes indexing/finding specific elements in the list much
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