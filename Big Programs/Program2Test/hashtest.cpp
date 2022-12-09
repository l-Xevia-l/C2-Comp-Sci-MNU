// implementation file for class hash
#include <cstdlib>
#include <String>
#include <sstream>
#include <algorithm>
#include <iostream>

#include "hashtest.h"

using namespace std;


Hash::Hash(int numForMod) {
    modNum = numForMod;
}

void Hash::add(string s){
    //cout << endl;
    insert(s);
    //cout << endl;
    numOfStrings++;
}

void Hash::remove(string s){

}

bool Hash::contains(string s){
    bool found{false};
    unsigned int newKey{0};
    string lower_s;
    lower_s.assign(s);
    int ASCIInum{0};

    // Converts the string in question into all lower case so that ASCII keys are accurate.
    transform(lower_s.begin(), lower_s.end(), lower_s.begin(), ::tolower);

    // converts srting s into ASCII integers so the hash function can do it's job.
    for (char letter : lower_s){ 
        ASCIInum = int(letter);
        newKey = newKey + ASCIInum;
    }

    // Hash function
    int index = newKey % modNum;

    // Temporary pointer
    node_k *temp = table[index];

    // Somethings' wrong around here. Using temp->next/key/data or table[index]->next/key/data causes a seg fault.
    // Another problem is that temp is always NULL. This shouldn't be the case because table[index] is pointing at a node
    // I've checked to make sure.

    /* Traverses to the end of the linked list. If there is a matching key, that means the item 
    exists. */
    while (temp != NULL){
        cout << "temp is not NULL" << endl;
        if (temp->key == newKey){
            cout << "temp->key == newKey" << endl;
            temp = NULL;
            delete temp;
            return true;
        }
        temp = temp->next;
    }

    cout << "";

    temp = NULL;
    delete temp;
    return false;
}

int Hash::size(){
    return numOfStrings;
}

void Hash::test(){

}

/* ---------------------------     Helper Functions     --------------------------- */

// Generates a newKey and inserts the string into the list
void Hash::insert(string s){
    // Sentinels
    int ASCIInum{0};

    // Variable for the new item's key.
    unsigned int newKey{0};

    string lower_s;
    lower_s.assign(s);


    // Converts the string in question into all lower case so that ASCII keys are accurate.
    transform(lower_s.begin(), lower_s.end(), lower_s.begin(), ::tolower);

    // converts srting s into ASCII integers so the hash function can do it's job.
    for (char letter : lower_s){ 
        ASCIInum = int(letter);
        newKey = newKey + ASCIInum;
    }
    
    // Hash fuunction
    int index = newKey % modNum;

    // Temporary pointer
    node_k *temp = table[index];

    /* Traverses to the end of the linked list. If there is a matching key, that means the item already
        exists. */
    
    while (temp != NULL){
        if (temp->key == newKey){
            cout << "duplicate item" << endl;
            temp = NULL;
            delete temp;
            return;
        }
        temp = temp->next;
    }

    
    if (temp == NULL){
        temp = new node_k;

        temp->key = newKey;
        temp->data.assign(lower_s);
        temp->next = NULL;    
    }
    cout << "temp->key: " << temp->key << " newKey: " << newKey << " " << endl;
    temp = NULL;
    delete temp;
    
}