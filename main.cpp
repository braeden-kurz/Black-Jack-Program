/*
 * Name: Braeden Kurz, 2001429594, Black Jack Personal Project
 * 
 * Description: My own personal project that simulates a game of
 * Blackjack. There will be two players; the dealer and the one
 * playing against the dealer. Each player will be dealt two
 * cards of shown value. The dealer will be dealt 2
 * 
 * Input:
 * 
 * Output:
 *
 */

#ifndef IO_H
#define IO_H
#include <iostream>
#endif

#ifndef VECTOR_H
#define VECTOR_H
#include <vector>
#endif

#ifndef CARD_H
#define CARD_H
#include "Card.h"
#endif

#ifndef RAND_H
#define RAND_H
#include <time.h>
#include <stdlib.h>
#endif

#ifndef PLAYER_H
#define PLAYER_H
#include "Player.h"
#endif

#ifndef IOMANIP_H
#define IOMNAIP_H
#include <iomanip>
#endif

using namespace std;

// FUNCTION DEFINITIONS
void printRules() {
    cout << "The Rules of Blackjack" << endl;
    cout << "=======================================================\n";
    cout << "1. The goal of Blackjack is to beat the dealer's hand\n";
    cout << "   going over 21\n";
    cout << "2. Each player starts with two card, one of the\n";
    cout << "   dealer's cards is faced down.\n";
    cout << "3. (H)it - ask for another card, (S)tand - hold card\n";
    cout << "4. If the player goes over 21, this is called a 'bust',\n";
    cout << "   the dealer wins regardless\n";
    cout << "5. If you are dealt a 21 (an Ace and a 10), you\n";
    cout << "   automatically win a 'blackjack' and earn 1.5 times\n";
    cout << "   the amount you orignally bet on\n";
    cout << "6. The Dealer will 'hit' until his/her cards are '17'\n";
    cout << "   or higher\n";
    cout << "7. 'Doubling' in Blackjack lets you hit again, but you\n";
    cout << "   only get one more card\n";
    cout << "8. 'Splitting' is optional when you want to bet on\n";
    cout << "   another hand from two identical cards, doubling\n";
    cout << "   your bet when you win both hands\n";
    cout << "9. You can double on a splitting hand, tripling or\n";
    cout << "   quadrupling your bet\n";
    cout << endl << endl;
};

void printTitle() {
    cout << "=============================================\n";
    cout << "||             Blackjack in C++            ||\n";
    cout << "=============================================\n";
    cout << "1. (S)tart a new game" << endl;
    cout << "2. (R)ules...so you don't lose all of your money" << endl;
    cout << "3. (Q)uit the game" << endl;
    cout << endl;
}

void printResults(Player player, Dealer dealer) {
    cout << endl;
    cout << "                   Results" << endl;
    cout << "=============================================" << endl;
    cout << "Player: " << player.getHandValue() << " \n";
    player.PrintDeck();
    cout << "Dealer: " << dealer.getHandValue() << "\n";
    dealer.PrintDeck();
    cout << endl;
    if (dealer.getHandValue() < player.getHandValue() || dealer.getHandValue() < 21) {
        cout << "Player Wins: " << player.getBet() << endl << endl;
        return;
    }
    else if (player.getHandValue() == dealer.getHandValue()) {
        cout << "Draw" << endl << endl;
        return;
    }
    else if (player.getHandValue() > 21 || player.getHandValue() < dealer.getHandValue()) {
        cout << "Player Loses: " << player.getBet() << endl << endl;
        return;
    }
}

void runGame() {
    char choice = ' ';
    // 1. Create a dealing deck
    Deck DealingDeck;

    for(int i = 2; i <= 14; i++ ){ // Cards 2 through Ace
        char val;
        switch(i){
            case(14):{val = 'A'; break;}
            case(13):{val = 'K'; break;}
            case(12):{val = 'Q'; break;}
            case(11):{val = 'J'; break;}
            case(10):{val = 'T'; break;}
            default:{val = i + 48; break;} // i+48 converts and int to its char representation.
            // int x = 5; char z = 5 + 48; --> '5'
        }
        DealingDeck.AddToTopOfDeck(Card('S', val)); // Spade
        DealingDeck.AddToTopOfDeck(Card('H', val)); // Heart
        DealingDeck.AddToTopOfDeck(Card('C', val)); // Club
        DealingDeck.AddToTopOfDeck(Card('D', val)); // Diamond
    }
    DealingDeck.PrintDeck();
    cout << endl;

    // 2. Shuffle the deck to get random cards
    DealingDeck.ShuffleDeck();

    // 3. Have the player/players place their bets
    Player p1;
    Dealer dealer;

    while (true) {
        int bet;
        cout << "Place your bets champ (1, 10, 20, 50): ";
        cin >> bet;
        cout << "=============================================" << endl;
        switch(bet) {
            case 1:
            case 10:
            case 20:
            case 50:
                p1.setBet(bet);
                cout << endl << endl;
                break;
            default:
                cout << "Invalid input, enter the correct amounts shown\n";
                cout << endl << endl;
                cin.clear();
                cin.ignore(100, '\n');
                continue;
        }
        break;
    }

    // 4. Hand out cards to player and dealer
    for (int i = 0; i < 2; i++) {
        p1.AddToTopOfDeck(DealingDeck.RemoveTopCard());
        dealer.AddToTopOfDeck(DealingDeck.RemoveTopCard());
    }

        // 5. Print the player's stats and deck
        p1.printPlayerStats();

        // 6. Print the dealer's hand
        cout << "Dealer's Hand Value: ";
        cout << dealer.getFirstCardWeight() << endl;
        cout << "-------------------------" << endl;
        dealer.printFirstCard();
        cout << " ";
        dealer.printHiddenCard();
        cout << endl << endl;

    // 7. Prompt user to hit, stand, or double
    while(true) {
        // If player's hand equals 21, they win
        if (p1.getHandValue() == 21) {
            cout << "BLACKJACK!!!" << endl;
            cout << "You win!" << endl;
            cout << endl;
            break;
        }

        if (p1.getHandValue() > 21) {
            cout << "You lose." << endl;
            cout << endl;
            break;
        }

        // Prompt player if they want to hit, stand, or double
        cout << "=============================================" << endl;
        cout << "(H)it, (S)tand, or (D)ouble?: ";
        cin >> choice;
        cout << endl;
        switch(choice) {
            // Adds another card to the player's hand
            case 'H':
            case 'h':
                break;
            case 'S':
            case 's':
                break;
            case 'D':
            case 'd':
                break;
            default:
                cout << "Invalid entry! Please choose from the following\n";
                cout << endl;
                cin.clear();
                cin.ignore(40, '\n');
                continue;
        }
    }


};

int main() {
    srand(time(0));
    char choice = ' ';
    bool continueGame = true;

    // Display the game menu
    while(continueGame == true) {
        printTitle();
        cout << endl;
        cout << "Enter your selection: ";
        cin >> choice;
        
        switch(choice) {
            case 'S':
            case 's':
                // Start a new game
                runGame();
                break;

            case 'R':
            case 'r':
                // Prints the rules of the game
                cout << endl << endl;
                printRules();
                cout << "Press the 'Enter' key to conitinue...\n";
                cin.ignore();
                cin.get();
                cout << endl << endl;
                break;

            case 'Q':
            case 'q':
                // Exits the program
                continueGame = false;
                break;
            default:
                cout << endl << endl;
                cout << "Wrong input, please select the appropirate options\n";
                cout << endl;
                cin.clear();
                cin.ignore(40, '\n');
                break;
        }
    }
    return 0;
}