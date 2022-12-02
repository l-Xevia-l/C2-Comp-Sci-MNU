// implementation file for class hash
#include <cstdlib>
#include <String>
#include <sstream>

#include "hash.h"

using namespace std;

Hash::Hash(int Size, int numForMod) {
    struct node_k {
        string data;
        node_k * next;
    };

    tableSize = Size;
    modNum = numForMod;
}

void Hash::add(string s){
    insert(s);
    numOfStrings++;
}

void Hash::remove(string s){

}

bool Hash::contains(string s){

}

int Hash::size(){
    return numOfStrings;
}

//-----------------------Helper Functions---------------------------

// generates a key and inserts the string into the list
int Hash::insert(string s){
    int key;
    s = convertToLower(s);
    for (int i = 0; i < s.length(); i++){
        char x = s.at(i);
        key = key + x;
    }
    int index = key % modNum;
    while( != ){

    }
}

string convertToLower(string s){
    string lowerS;

    return lowerS;
}