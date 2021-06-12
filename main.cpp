/*
 * Name: Braeden Kurz, Black Jack Personal Project
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

// Not necessary in the program, may have to toss
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

/******************************
 *  MAIN FUNCTIONS
*******************************/

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

void runGame() {
    // Initialize variables within program
    bool runningGame = true;
    char choice = ' ';

    // Create player and dealer objects
    Player p1;
    Dealer dealer;

    // This loop will keep running the game until the player enters 'q'
    while (runningGame == true) {
        // Create the deck and shuffle the deck
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
        DealingDeck.ShuffleDeck();

        // Prompt user for bet amount
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
                    cout << "You have betted $" << p1.getBet() << endl;
                    cout << endl;
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

        // Hand out cards to player and dealer and display hands
        for (int i = 0; i < 2; i++) {
            p1.AddToTopOfDeck(DealingDeck.RemoveTopCard());
            dealer.AddToTopOfDeck(DealingDeck.RemoveTopCard());
        }

        // Print the dealer's hand
        cout << "Dealer's Hand Value: ";
        cout << dealer.getFirstCardWeight() << endl;
        cout << "-------------------------" << endl;
        dealer.printFirstCard();
        cout << " ";
        dealer.printHiddenCard();
        cout << endl << endl << endl;

        // Print the player's stats and deck
        p1.printPlayerStats();

        while (true) {
            // If player gets hard blackjack, they win 1.5 their bet
            if (p1.getHandValue() == 21) {
                cout << "Results\n" << endl;
                p1.printPlayerStats();
                dealer.printDealerStats();
                cout << endl;
                cout << "BLACKJACK!\n";
                cout << "You Win $" << p1.getBet() << endl;
                p1.addMoney(p1.getBet() * 1.5);
                break;
            }

            /* This section is left blank
             * Needs to take an 'A' valued card and change the value from
             * 11 to 1 if the hand goes over 21
             */

            // Prompt the player with the foloowing options
            cout << "(H)it, (S)tand, or (D)ouble?: ";            
            cin >> choice;
            switch (choice) {
                // Add a card to the player's deck
                case 'H':
                case 'h':
                    cout << endl;
                    p1.AddToTopOfDeck(DealingDeck.RemoveTopCard());
                    p1.printPlayerStats();
                    // If the player gets a 21, they win
                    if (p1.getHandValue() == 21) {
                        cout << "Results\n" << endl;
                        p1.printPlayerStats();
                        dealer.printDealerStats();
                        cout << endl;
                        cout << "You Win $" << p1.getBet() << endl;
                        p1.addMoney(p1.getBet());
                        break;
                    }
                    // If player goes over 21, they lose
                    else if (p1.getHandValue() > 21) {
                        cout << "Results\n" << endl;
                        p1.printPlayerStats();
                        dealer.printDealerStats();
                        cout << endl;
                        cout << "You lose $" << p1.getBet() << endl;
                        p1.subMoney(p1.getBet());
                        break;
                    }
                    else {
                        continue;
                    }
                    break;
                // The player stays and the dealer deals cards to self
                case 'S':
                case 's':
                    // Flip dealer's 2nd card and add cards until >=17
                    cout << endl;
                    dealer.printDealerStats();
                    while (dealer.getHandValue() < 17) {
                        dealer.AddToTopOfDeck(DealingDeck.RemoveTopCard());
                        dealer.printDealerStats();
                    }
                    // Dealer's hand is 21 == Player Loss
                    if (dealer.getHandValue() == 21) {
                        cout << "Results" << endl;
                        cout << "=============================================\n";
                        p1.printPlayerStats();
                        dealer.printDealerStats();
                        cout << endl;
                        cout << "You lose $" << p1.getBet() << endl;
                        p1.subMoney(p1.getBet());
                        break;
                    }
                    // Dealer's hand goes over 21 == Player win
                    else if (dealer.getHandValue() > 21) {
                        cout << "Results" << endl;
                        cout << "=============================================\n";
                        p1.printPlayerStats();
                        dealer.printDealerStats();
                        cout << endl;
                        cout << "You Win $" << p1.getBet() << endl;
                        p1.addMoney(p1.getBet());
                        break;
                    }
                    // Dealer's hand equals player's == Push
                    else if (dealer.getHandValue() == p1.getHandValue()) {
                        cout << "Results" << endl;
                        cout << "=============================================\n";
                        p1.printPlayerStats();
                        dealer.printDealerStats();
                        cout << endl;
                        cout << "Push" << endl;
                        break;
                    }
                    // Dealer's hand greater than player's == Player loss
                    else if (dealer.getHandValue() > p1.getHandValue()) {
                        cout << "Results" << endl;
                        cout << "=============================================\n";
                        p1.printPlayerStats();
                        dealer.printDealerStats();
                        cout << "You lose $" << p1.getBet() << endl;
                        p1.subMoney(p1.getBet());
                        break;
                    }
                    // Dealer's hand less than player's == Player win
                    else if (dealer.getHandValue() < p1.getHandValue() ||
                        p1.getHandValue() > dealer.getHandValue()) {
                        cout << "Results" << endl;
                        cout << "=============================================\n";
                        p1.printPlayerStats();
                        dealer.printDealerStats();
                        cout << "You Win $" << p1.getBet() << endl;
                        p1.addMoney(p1.getBet());
                        break;
                    }
                // Doubles the player's bet, but will stay for the round
                case 'D':
                case 'd':

                    break;
                // Display error message and clear cin stream
                default:
                    cout << "Wrong input!\n";
                    cin.clear();
                    cin.ignore(40, '\n');
                    continue;
            }
            break;
        }

        // Prompt player to continue game
        cout << "Would you like to continue the game, (Y)es or (N)o?: ";
        while (true) {
            cin >> choice;
            switch (choice) {
                // Reset each deck and prompt player for another bet
                case 'Y':
                case 'y':
                    DealingDeck.ClearDeck();
                    p1.ClearDeck();
                    dealer.ClearDeck();
                    break;
                // End the game and return to the menu
                case 'N':
                case 'n':
                    runningGame = false;
                    break;
                // Display error message, clear cin, and repeat
                default:
                    cout << endl;
                    cout << "Wrong input! Continue game, (Y)es or (N)o: ";
                    cin.clear();
                    cin.ignore(40, '\n');
                    continue;
            }
            break;
        }
    }

};

int main() {
    srand(time(0));
    char choice = ' ';
    bool continueGame = true;

    // Display the game menu and prompt player with options
    while(continueGame == true) {
        printTitle();
        cout << endl;
        cout << "Enter your selection: ";
        cin >> choice;
        switch(choice) {
            // Run a brand new game
            case 'S':
            case 's':
                // Start a new game
                runGame();
                break;
            // Prints the rules of the game
            case 'R':
            case 'r':
                cout << endl << endl;
                printRules();
                cout << "Press the 'Enter' key to conitinue...\n";
                cin.ignore();
                cin.get();
                cout << endl << endl;
                break;
            // Exits the program
            case 'Q':
            case 'q':
                continueGame = false;
                break;
            // Displayer error message, clear cin, and repeat
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