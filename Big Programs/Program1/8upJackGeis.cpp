/*
|-----------------------------------------------------------------------------|
Author: Jack Geis
Date Created: 10/12/2022
Date Last Modified: 10/25/2022
Assignment: Make a game to simulate the tabletop game of 8up solitaire using 
provided files.
|-----------------------------------------------------------------------------|
*/



#include <iostream>
#include <array>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <String>
#include <time.h>
#include <chrono>
#include <thread>

#include "Deck.h"

using namespace std;

void PrintDeck(Deck);

void PrintTable(const Card[]);

void PlaceCards(Card[], Deck &deck, unsigned int &cardsDelt);

void CoverMatching(Card[], Deck &deck, bool &Win, bool &Lost, unsigned int &cardsDelt, bool);


/*
------------------------------------------------- MAIN -------------------------------------------------
*/


int main() {
  bool play = true;

  while(play) {
    // seed the rand function
    srand(time(NULL));

    bool moreOutput;
    bool Win = false;
    bool Lost = false;

    // declaration of trackers
    unsigned int attempts{1};

    Deck deck;

    deck.GenerateDeck();
    
    // Card slots on table
    Card Card1_1, Card1_2, Card1_3, Card1_4, 
         Card2_1, Card2_2, Card2_3, Card2_4;

    // Array to simulate a table
    Card cardsOnTable[8] = {Card1_1, Card1_2, Card1_3, Card1_4, 
                            Card2_1, Card2_2, Card2_3, Card2_4};

    string input;
    cout << "Would you like to see more output? y/n: ";
    cin >> input;

    if(input == "y" || input == "Y") {
      moreOutput = true;
    }
    if(input == "n" || input == "N") {
      moreOutput = false;
    }
    
    cout << "Simulation begins in: \n";
    for(unsigned int i{3}; i > 0; i--) {
      cout << "\n-" << i << "-\n";
      this_thread::sleep_for(chrono::seconds(1));
    }
    
    // Has less output and runs much faster
    while(Win == false && moreOutput == false){ 
      unsigned int cardsDelt = 0;
      deck.ResetList();
      // Shuffle the deck
      for(unsigned int i{0}; i < (rand() % 250 + 100); i++) {
        deck.Shuffle();
      }
      deck.ResetList();

      cout << "\n----- NEW ROUND -----\n";

      cout << "\ncurrent attempt: " << attempts << endl;

      cout << "\nDeck shuffled.\n" << endl;

      // Show the beginning 8 cards
      cout << "Starting cards:" << endl;
      PlaceCards(cardsOnTable, deck, cardsDelt);
      PrintTable(cardsOnTable);
      cout << "Cards delt: " << cardsDelt;
      cout << endl;

      // Plays one round, dealing cards, checking them, deciding if the round has been won/lost
      while(Lost == false && Win == false) {
        CoverMatching(cardsOnTable, deck, Win, Lost, cardsDelt, moreOutput);
      }

      // Makes sure that the game is played until it's won.
      if(Lost == true){
        cout << "\n----- Round Lost! -----\n";
        cout << "\nCards delt before loss: " << cardsDelt;
        Lost = false;
        cout << "\n\n\n  Retrying...\n\n";
      }

      attempts++;
    }

    // Has more output with better format
    while(Win == false && moreOutput == true) {
      unsigned int cardsDelt = 0;
      deck.ResetList();
      // Shuffle the deck
      for(unsigned int i{0}; i < (rand() % 250 + 100); i++) {
        deck.Shuffle();
      }

      deck.ResetList();

      cout << "\n----- NEW ROUND -----\n";

      cout << "\ncurrent attempt: " << attempts << endl;

      cout << "\nDeck shuffled.\n" << endl;

      // Show the beginning 8 cards
      cout << "Starting cards:" << endl;
      PlaceCards(cardsOnTable, deck, cardsDelt);
      PrintTable(cardsOnTable);
      cout << "Cards delt: " << cardsDelt;
      cout << endl;

      // Plays one round with more output and a delay so output is readable
      while(Lost == false && Win == false) {
        CoverMatching(cardsOnTable, deck, Win, Lost, cardsDelt, moreOutput);
        PrintTable(cardsOnTable);
        this_thread::sleep_for(chrono::milliseconds(200));
      }

      // Makes sure that the game is played until it's won.
      if(Lost == true){
        cout << "\nRound Lost!\n";
        Lost = false;
        cout << "\n\n  Retrying...\n\n";
      }
      attempts++;
    }

    if(Win) {
      cout << "\n\n-----YOU WON!-----\n\n";
    }

    cout << "\n\n  Attempts: " << (attempts - 1) << endl << endl;

    cout << "Would you like to play again? y/n: ";
    cin >> input;

    if(input == "y" || input == "Y") {
      play = true;
    }
    else /*if(input == "n" || input == "N")*/ {
      play = false;
    }
  }
  return 0;
}

/*
------------------------------------------------- FUNCTION DEFINITIONS -------------------------------------------------
*/

void PrintDeck(Deck deck) {
  if (deck.GetLength() == 0)
    cout << "Deck is empty." << endl;
  else
  {
    deck.ResetList();
    Card card;
    for (int counter = 1; counter <= deck.GetLength(); counter++)
    {
      card = deck.GetNextItem();
      cout << card.ToString() << endl;
    }
  }
  cout << endl;
}

void PrintTable(const Card cardsOnTable[8]) {
  // iterates 8 times to traverse cardsOnTable
  cout << "\n|---------------------------------------------------------------------|\n";
  for(unsigned int i{0}; i < 8; i++) {
    // selects the card in the current index and copies it into a string variable
    Card card = cardsOnTable[i];

    string strcard = card.ToString();

    // outputs the string-copy of the card in a format of 2 rows of 4
    if(i == 0){
      cout << "| ";
    }
    if((i < 4) || (i > 4)) {
      cout << strcard << ", ";
    }
    else{
      cout << "\n| " << strcard << ", ";
    }
  }
  cout << "\n|---------------------------------------------------------------------|\n";
}

void PlaceCards(Card *cardsOnTable, Deck &deck, unsigned int &cardsDelt) {
  // Populates cardsOnTable with the first eight cards in the deck
  for(unsigned int i{0}; i < 8; i++) {
    cardsOnTable[i] = deck.GetNextItem();
    cardsDelt++;
  }
}

// finds two matching cards and places a card from dack into their spot in cardsOnTable
void CoverMatching(Card *cardsOnTable, Deck &deck, bool &Win, bool &Lost, unsigned int &cardsDelt, bool moreOutput) {
    bool foundMatch = false;

    // numOfMatches is used to tell if there were any matches at all. If no matches are made the round has been lost
    unsigned int numOfMatches{0};
    unsigned int sizeOfDeck{52};

    // counter variables for the nested while loop
    unsigned int x{0};
    unsigned int y{0};

    Card currentCard;
    Card comparison;

    // If the amount of cards delt from the deck is equal to the size of the deck, the game has been won.
    if(cardsDelt >= sizeOfDeck) {
      Win = true;
    }

    // nested while loops to compare each card to every other card until a match is found
    while((x < 8 && foundMatch == false) && Win == false) {
      y = 0;
      currentCard = cardsOnTable[x];

      while((y < 8 && foundMatch == false) && Win == false) {
        // makes sure a card is not compared to itself
        if(x != y) {
          comparison = cardsOnTable[y];

          // comppares cards
          if(currentCard.GetRank() == comparison.GetRank()){
            numOfMatches++;
 
            // places the cards from the deck onto the matching cards
            cardsOnTable[y] = deck.GetNextItem();
            cardsDelt++;
            cardsOnTable[x] = deck.GetNextItem();
            cardsDelt++;

            if (moreOutput) {
            cout << currentCard.ToString() << " matched with " << comparison.ToString() << "!\n";
            cout << "Cards delt: " << cardsDelt << endl;
            }

            foundMatch = true;
            
            // IF the whole deck has been used, the game has been won.
            if(cardsDelt >= sizeOfDeck) {
              Win = true;
            }

          }
        }
        y++;
      }
      x++;
    }

    // IF no matches were found on the table, the game is lost.
    if(numOfMatches < 1) {
      Lost = true;
    }
}
