/*
|-----------------------------------------------------------------------------|
Author: Jack Geis
Date Created: 11/26/2022
Date Last Modified: 12/9/2022
Assignment: Write a class that implements a Hash Table of strings. 
    write a main program that uses your hash table class. 
    The main program will behave like simple spell checker, 
    the program is used interactively to check individual words.
|-----------------------------------------------------------------------------|
*/



#include <iostream>
#include <fstream>
#include <array>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include "hash.h"

using namespace std;

int main() {
    int pause;

    // dictionary file
    string filename = "linux.words";

    // for reading in from dictionary
    string ln;

    ifstream dict;

    dict.open(filename);

    // constructor
    Hash hash(200'000);

    cout << "\n\nLoading dictionary...\n\n";

    // Reads in the whole file and adds it to the hash
    if (dict.is_open()) {
        while (dict >> ln) {
            hash.add(ln);
        }
    }
    dict.close();

    cout << "\n\nDictioary loaded!\n\n";

    bool play{true};
    bool add{false};
    bool contains{false};
    string input{""};
    string YorN{"n"};

    // Check/add words
    while(play) {
        input = "";
        cout << "\n\nEnter a word to see if it is in the dictionary: ";
        cin >> input;

        contains = hash.contains(input);

        cout << "contains: " << contains << endl;

        if (contains == false) {
            cout << "That word is not in the dictionary, would you like to add it? y/n: ";
            cin >> YorN;
            if(YorN == "y" || YorN == "Y") {
                add = true;
            }    
            else {
                add = false;
            }
            if (add) {
                hash.add(input);
                cout << "added " << input << endl;
            }
        }
        else {
            cout << "\nThat word is in the dictionary!\n";
        }

        cout << "Would you like to check another word? y/n: ";
        cin >> YorN;
        if(YorN == "y" || YorN == "Y") {
            play = true;
        }    
        else {
            play = false;
        }
    }

    cout << "\nYou added " << (hash.size()) - 124'801 << " words. \n";

    cout << "\nWould you like to remove any words? y/n: ";
    cin >> YorN;
    if(YorN == "y" || YorN == "Y") {
        play = true;
    }    
    else {
        play = false;
    }
    
    //Remove words
    while (play) {
        input = "";
        cout << "\nEnter a word to remove: ";
        cin >> input;

        contains = hash.contains(input);

        if (contains) {
            hash.remove(input);
            cout << endl << input << "removed!\n";
        }
        else {
            cout << "\nCannot remove a word that isn't in the dictionary\n";
        }
        cout << "\nWould you like to remove another word? y/n: ";
        cin >> YorN;

        if(YorN == "y" || YorN == "Y") {
            play = true;
        }    
        else {
            play = false;
        }
    }

    return 0;
}