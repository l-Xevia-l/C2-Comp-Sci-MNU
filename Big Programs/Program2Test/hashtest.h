#include <String>

using namespace std;

struct node_k {
    string data; 
    int key = -1; 
};

class Hash {
public: 
    // Constructor
    Hash(int);

    // Function to add the string s to the table, if it's not already there.
    void add(string);

    // Function to remove the string s from the table, if it's there.
    void remove(string);

    // Function to check whether string s is in the table and returns T/F.
    bool contains(string);

    // Function that returns the number of strings in the table.
    int size();

    void test();

private:
    // Hash function to compute the hash code of a string.
    void insert(string);

    int modNum{};
    int numOfStrings{0};

    // the <150'000> is the size of the table.
    node_k table[150'000];
};
