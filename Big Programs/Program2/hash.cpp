// implementation file for class hash
#include <cstdlib>
#include <String>
#include <sstream>
#include <algorithm>
#include <iostream>

#include "hash.h"

using namespace std;


Hash::Hash(int numForMod) {
    modNum = numForMod;
    
}

void Hash::add(string s){
    cout << 3 << endl;
    insert(s);
    cout << 4 << endl;
    numOfStrings++;
}

void Hash::remove(string s){

}

bool Hash::contains(string s){
    bool found;

    return found;
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
    unsigned int newKey;

    string lower_s = s;

    // Converts the string in question into all lower case so that ASCII keys are accurate.
    transform(lower_s.begin(), lower_s.end(), lower_s.begin(), ::tolower);

    // converts srting s into ASCII integers so the hash function can do it's job.
    for (char letter : lower_s){ 
        int ASCIInum = int(letter);
        newKey = newKey + ASCIInum;
    }
    
    // I could've just used <inserted>, i used two for clarity.
    while (inserted == false && notInserted == false){
        // Hash fuunction
        int index = newKey % modNum;

        // Temporary pointer
        //node_k *arrPos = table[index];
        node_k *temp = table[index]->next;

        cout << 5 << endl;
        /* Traverses to the end of the linked list. If there is a matching key, that means the item already
           exists. */
        while (temp->next != NULL){
            temp = temp;
            cout << 6 << endl;
            if (temp->key == newKey){
                notInserted = true;
            }
        }

        // Case: there is a linked list at the index.
        if (temp->key != -1){
            // Creates a new node_k and attaches it to the list, then sets temp to the new node
            temp->next = new node_k;
            temp = temp->next;
            
            /* Puts the new item's key and data into the new node, and makes sure the <next> pointer 
               is set to NULL */
            temp->key = newKey;
            temp->data = s;
            temp->next = NULL;
            inserted = true;
        }
        // Case: the array index has no linked list yet.
        else if (temp->key == -1){
            temp->key = newKey;
            temp->data = s;
            temp->next = NULL;
            inserted = true;
        }
        // Case: item already exists in the array.
        else if (temp->key == newKey){
            notInserted = true;
            cout << "Item already exists" << endl;
        }

        delete temp;
    }
}