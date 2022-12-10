// implementation file for class hash
#include <cstdlib>
#include <String>
#include <sstream>
#include <algorithm>
#include <iostream>

#include "hash.h"

using namespace std;

string table[200'000]{""};

long int sizeOfTable = 199'999;

Hash::Hash(long int numForMod) {
    modNum = numForMod;
}

void Hash::add(string s){
    insert(s);
    numOfStrings++;
}

void Hash::remove(string s){
    if(contains(s)){
        // Variable for the new item's key.
        unsigned long int newKey{0};
        unsigned long int ASCIInum{0};

        string lower_s = s;

        // Converts the string in question into all lower case so that ASCII keys are accurate.
        transform(lower_s.begin(), lower_s.end(), lower_s.begin(), ::tolower);

        for (char letter : lower_s){ 
            ASCIInum = int(letter);
            newKey += ASCIInum;
        }
        newKey = newKey * newKey;

        // Hash function
        long int index = newKey % modNum;

        // Makes sure that the index is always in the range of table
        if (index > sizeOfTable) {
            index = 0;
        }

        //Finds and removes the item
        while (true){
            if(table[index] == lower_s){
                table[index] = "";
                return;
            }
            newKey += 3;
            index = newKey % modNum;

            // Makes sure that the index is always in the range of table
            if (index > sizeOfTable) {
                index = 0;
            }
        }
    }
}

bool Hash::contains(string s){
    bool found{false};

    // Variable for the new item's key.
    unsigned long int newKey{0};
    unsigned long int ASCIInum{0};
    unsigned long int index{0};

    string lower_s;
    lower_s.assign(s);

    // Converts the string in question into all lower case so that ASCII keys are accurate.
    transform(lower_s.begin(), lower_s.end(), lower_s.begin(), ::tolower);

    for (char letter : lower_s){ 
        ASCIInum = int(letter);
        newKey += ASCIInum;
    }
    newKey = newKey * newKey;

    // Hash function
    index = newKey % modNum;

    // Makes sure that the index is always in the range of table
    if (index > sizeOfTable) {
        index = 0;
    }

    // Finds the item
    while (true){
        if(table[index] == lower_s){
            return true;
        }
        if(table[index] == "" && inTable[index] == false){
            return false;
        }
        // Rehash
        newKey += 3;
        index = newKey % modNum;


        // Makes sure that the index is always in the range of table
        if (index > sizeOfTable) {
            index = 0;
        }
    }
    return false;
}

int Hash::size(){
    return numOfStrings;
}



/* ---------------------------     Helper Functions     --------------------------- */

// Generates a newKey and inserts the string into the list
void Hash::insert(string s){
    // Sentinels
    bool inserted{false};
    bool notInserted{false};

    // Variable for the new item's key.
    unsigned long int newKey{0};
    unsigned long int ASCIInum{0};
    unsigned long int index{0};

    string lower_s;
    lower_s.assign(s);

    // Converts the string in question into all lower case so that ASCII keys are accurate.
    transform(lower_s.begin(), lower_s.end(), lower_s.begin(), ::tolower);

    for (char letter : lower_s){ 
        ASCIInum = int(letter);
        newKey += ASCIInum;
    }
    newKey = newKey * newKey;

    //cout << "newKey in insert: " << newKey << endl;
    // Hash function
    index = newKey % modNum;

    // Makes sure that the index is always in the range of table
    if (index > sizeOfTable) {
        index = 0;
    }

    // finds and inserts the item
    while (inserted == false && notInserted == false){
        if (table[index] == "") {
            table[index].assign(lower_s);
            inTable[index] = true;
            inserted = true;
        }

        newKey += 3;
        index = newKey % modNum;
        
        //cout << index << endl;

        // Makes sure that the index is always in the range of table
        if (index > sizeOfTable) {
            index = 0;
        }
    }
}