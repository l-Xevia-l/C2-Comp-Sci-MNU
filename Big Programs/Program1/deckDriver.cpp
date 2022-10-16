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

#include "Deck.h"

using namespace std;

void PrintDeck(Deck);

void PrintTable(const Card[]);

void PlaceCards(Card[], Deck);

void CoverMatching(Card[], Deck);

int main() {
  bool WorL{false};
  Deck deck;
  deck.GenerateDeck();
  deck.ResetList();
  for(unsigned int i{0}; i < 20; i++) {
    deck.Shuffle();
  }

  // Card slots on table
  Card Card1_1, Card1_2, Card1_3, Card1_4, 
       Card2_1, Card2_2, Card2_3, Card2_4;

  // Array to simulate a table
  Card cardsOnTable[8] = {Card1_1, Card1_2, Card1_3, Card1_4, 
                          Card2_1, Card2_2, Card2_3, Card2_4};
  
  PlaceCards(cardsOnTable, deck);

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
      cout << strcard << ' ';
    }
    else{
      cout << '\n' << strcard << ' ';
    }
  }
}

void PlaceCards(Card *cardsOnTable, Deck deck) {
  for(unsigned int i{0}; i < 8; i++) {
    cardsOnTable[i] = deck.GetNextItem();
  }
  PrintTable(cardsOnTable);
}

void CoverMatching(Card *cardsOnTable, Deck deck) {
  for(unsigned int x{0}; x < 8; x++) {
    Card currentCard = cardsOnTable[i];
    for(unsigned int y{0}; y < 8; y++){
      Card currentComparison = cardsOnTable[y];
      if(currentCard.GetRank() == currentComparison.GetRank()){

      }
    }
  }
}