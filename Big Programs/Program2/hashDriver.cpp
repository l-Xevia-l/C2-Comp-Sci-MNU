/*
|-----------------------------------------------------------------------------|
Author: Jack Geis
Date Created: //2022
Date Last Modified: //2022
Assignment: 
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

    // dictionary file
    string filename = "linux.words";

    // for reading in from dictionary
    string ln;

    ifstream dict;

    dict.open(filename);

    // constructor
    Hash hash(150'000);

    // Reads in the whole file and adds it to the hash
    if (dict.is_open()) {
        while (getline(dict, ln)) {
            hash.add(ln);
        }
    }
    dict.close();


    bool play{true};
    bool add{false};
    string input{""};

    while(play) {
        cout << "\n\nEnter a word to see if it is in the dictionary: ";
        cin >> input;

        if (!(hash.contains(input))) {
            cout << "That word is not in the dictionary, would you like to add it? y/n: ";
            cin >> add;
            if (add) {
                hash.add(input);
                cout << "added " << input;
            }
        }
        if (hash.contains(input)) {
            cout << "\nThat word is in the dictionary!\n";
        }

        cout << "Would you like to add another word? y/n: ";
        cin >> play;    
    }

    cout << "\nYou added " << (hash.size()) - 124'801 << " words. \n";

    cout << "\nWould you like to remove any words? y/n: ";
    cin >> play;
    
    while (play) {
        cout << "\nEnter word to remove: ";
        cin >> input;

        if (hash.contains(input)) {
            hash.remove(input);
            cout << endl << input << "removed!\n";
        }
        else {
            cout << "\nCannot remove a word that isn't in the dictionary\n";
        }
        cout << "\nWould you like to remove another word? y/n: ";
        cin >> play;
    }

    return 0;
}