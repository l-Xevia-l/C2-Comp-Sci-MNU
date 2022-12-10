#include <String>

using namespace std;

class Hash {
public: 
    // Constructor
    Hash(long int);

    // Function to add the string s to the table, if it's not already there.
    void add(string);

    // Function to remove the string s from the table, if it's there.
    void remove(string);

    // Function to check whether string s is in the table and returns T/F.
    bool contains(string);

    // Function that returns the number of strings in the table.
    int size();

private:
    // Hash function to compute the hash code of a string.
    void insert(string);

    long int modNum{200'000};
    long int numOfStrings{0};

    // the <200'000> is the size of the table.
    string table[200'000]{""};
    
    // This allows the contains function to find items, even if items above it have been deleted.
    bool inTable[200'000]{false};
};
