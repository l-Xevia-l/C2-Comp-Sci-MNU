#include <String>

class Hash {
public: 
    // Constructor
    Hash(int, int);

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
    int insert(string);
    int convert(string);

    int modNum{};
    int numOfStrings{};
    int tableSize{};
};
