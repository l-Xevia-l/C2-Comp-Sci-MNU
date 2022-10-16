/*
|-----------------------------------------------------------------------------|
Author: Jack Geis
Date Created: 10/12/2022
Date Last Modified: 10/12/2022
Assignment: 
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

void PlaceCards(Card[], Deck);

void CoverMatching(Card &topOfDeck, Card[], Deck, bool &Win, bool &Lost, int &matches);

int main() {
  srand(time(NULL));

  bool Win{false};
  bool Lost{false};

  int attempts{0};

  Deck deck;
  deck.GenerateDeck();
  
  // Card slots on table
  Card Card1_1, Card1_2, Card1_3, Card1_4, 
       Card2_1, Card2_2, Card2_3, Card2_4;

  // Array to simulate a table
  Card cardsOnTable[8] = {Card1_1, Card1_2, Card1_3, Card1_4, 
                          Card2_1, Card2_2, Card2_3, Card2_4};

  Card topOfDeck;
  
  int mostMatches{0};

  while(Win == false){ 
    int matches{0};

    // Generate and shuffle the deck
    for(unsigned int i{0}; i < (rand() % 100 + 50); i++) {
      deck.Shuffle();
    }

    // Show the beginning 8 cards
    cout << "Starting cards:" << endl;
    PlaceCards(cardsOnTable, deck);
    cout << endl;
    // Makes sure that the cards in cardsOnTable are not compared to themselves
    for(unsigned int i{0}; i < 8; i++) {
      deck.GetNextItem();
    }

    // Plays one round
    while(Lost == false && Win == false) {
      cout << "-------------------------------------------------------";
      topOfDeck = deck.GetNextItem();
      CoverMatching(topOfDeck, cardsOnTable, deck, Win, Lost, matches);
    }
    if(matches > mostMatches) {
      mostMatches = matches;
    }
    if(Lost == true){
      Lost = false;
      cout << "\n\n\n\n\n\n\n  ------------Attempts: " << attempts << "------------\n\n\n\n\n\n\n";
      cout << "\n  ------------highest match spree: " << mostMatches << "------------\n";
      cout << "\n\n  Retrying...\n\n";
    }
    //this_thread::sleep_for(std::chrono::nanoseconds(1));    // for debugging
    attempts++;
  }
  cout << "\n\n  Attempts: " << attempts << endl << endl;
  return 0;
}

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
  for(unsigned int i{0}; i < 8; i++) {
    Card card = cardsOnTable[i];
    string strcard = card.ToString();

    if((i < 4) || (i > 4)) {
      cout << strcard << ", ";
    }
    else{
      cout << "\n" << strcard << ", ";
    }
  }
}

void PlaceCards(Card *cardsOnTable, Deck deck) {
  for(unsigned int i{0}; i < 8; i++) {
    cardsOnTable[i] = deck.GetNextItem();
  }
  PrintTable(cardsOnTable);
}

void CoverMatching(Card &topOfDeck, Card *cardsOnTable, Deck deck, bool &Win, bool &Lost, int &matches) {
  //for(unsigned int x{0}; x < 8; x++) {
    unsigned int y{0};
    int newMatch = matches;

    // Display the current cards before matching and stacking
    cout << "\nTable: \n";
    PrintTable(cardsOnTable);

    // shows the card that is being compared to all of the cards on top of the table
    cout << "\nCard on top of deck: " << topOfDeck.ToString() << endl;
    cout << endl;
    if((matches + 8) == 50) { // Check if the deck is empty by seeing if 42 matches have been made (The deck is 50 cards large, 8 cards are needed to start)
      cout << endl;
      PrintTable(cardsOnTable);
      cout << "\n\nYou Won!\n";
      Win = true;
    }
    else {
      while((y <= 8 && Lost == false) && Win == false){

        Card currentComparison = cardsOnTable[y];

        if(topOfDeck.GetRank() == currentComparison.GetRank()){ //compare the card on the top of the deck to the current card
          Card cardUnder = cardsOnTable[y];
          cardsOnTable[y] = topOfDeck; // put the card on top of it's match
          matches++; // increment the amount of matches made

          cout << "Matches: " << matches << endl << endl; // display the amount of matches
          cout << topOfDeck.ToString() << " stacked onto " << cardUnder.ToString() << endl;
          cout << endl;

          if((matches + 8) == 50) { // Check if the deck is empty by seeing if 42 matches have been made (The deck is 50 cards large, 8 cards are needed to start)
            cout << endl;
            PrintTable(cardsOnTable);
            cout << "\n\nYou Won!\n";
            Win = true;
          }
        }
        y++; //Increment counter
      }
      if(matches == newMatch) { // Check if there aren't any matching cards
          cout << "No matches were found! Round Lost.\n";
          Lost = true;
      }

    }
  //}
}