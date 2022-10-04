/*
|-----------------------------------------------------------------------------|
Author: Jack Geis
Date Created: 9/25/2022
Date Last Modified: 9/28/2022
Assignment: Use each member function from Unsorted.cpp at least two times.
|-----------------------------------------------------------------------------|
*/

#include "unsorted.h"

#include <iostream>
#include <array>
#include <iomanip>
#include <cmath>
#include <cstdlib>


using namespace std;


// Input: Refernce to a list of UnsortedType
// Output: Void
void printList(UnsortedType& list) {
    list.ResetList();
    int length = list.GetLength();
    ItemType item;

    // Runs through each item in the list and uses the ".Print()" function from ItemType.h to display the item
    for(int i{0}; i <  length; i++) {
        item = list.GetNextItem();
        item.Print(cout);
        cout << " ";
    }

}

int main() {
    // Two lists for manipulation
    UnsortedType listA; // stays forward
    UnsortedType listB; // will be reversed

    ItemType item; // Variable used to add items to listA and listB;

    bool found{false}; /* Boolean used for <object>.GetItem(ItemType, bool). 
     is changed by this function if the item is or is not found in the object */

    listA.MakeEmpty(); // Ensures that both lists are completely deallocated
    listB.MakeEmpty();

    if(listA.IsFull() == false) { // first uses of IsFull to tell the user wether or not the object is full
        cout << "listA contains nothing." << endl;
    }
    else{
        cout << "listA is full." << endl;
    }

    int input = 0; // Integer variable used to take user input
    do {
        cout << "\nWould you like to add another item to the list? Enter 0 to exit. ";
        cin >> input;

        if (input != 0){ //Ensures that there are no zeros in the object
            item.Initialize(input);
            listA.PutItem(item);
            cout << "\nItem added to listA\n";
        }

        if(listA.IsFull() == false) { // Tells the user wether or not the list is full
            cout << "ListA is not full\n";
        }
    } while(input != 0); // Runs until the user input is "0"

    cout << "\nListA: ";
    printList(listA);
    cout << endl;

    int len = listA.GetLength(); // Gets the length of listA
    listA.ResetList(); // Resets  the pointer to the beginning of the linked list

    for(int i{0}; i < len; i++) { // Makes a reverse copy of listA into listB
        ItemType currentItem;
        currentItem = listA.GetNextItem();
        listB.PutItem(currentItem);
    }
    cout << "Reversed list (listB): ";
    printList(listB);
    cout << endl;

    // Allows the user to delete items from listA until it is either empty or the user exits with "0"
    do {
        cout << "\nListA: ";
        printList(listA);
        cout << "\nEnter a number to delete from listA. Enter 0 to exit: ";
        cin >> input;

        if(input != 0) { //Ensures the prgram does not attempt to delete zero from the list
            item.Initialize(input);
            listA.DeleteItem(item);
        }

        if(listA.GetLength() == 0) {
            cout << "You have deleted all items in listA"
        }
    } while((input != 0) && (listA.GetLength() != 0));
    
    // Allows the user to delete items from listB until it is either empty or the user exits with "0"
    do {
        cout << "ListB: \n";
        printList(listB);
        cout << "\nEnter a number to delete from listB. Enter 0 to exit: ";
        cin >> input;

        if(input != 0) { //Ensures the prgram does not attempt to delete zero from the list
            item.Initialize(input);
            listB.DeleteItem(item);
        }

        if(listB.GetLength() == 0) {
            cout << "You have deleted all items in listB"
        }
    } while((input != 0) && (listB.GetLength() != 0));

    cout << endl;

    // Allows the user to check if a number is in listA
    do {
        cout << "\nEnter a number to see if it is in listA. Enter 0 to exit: ";
        cin >> input;

        if(input != 0) { // Ensures the program does not check if zero is in the list
            item.Initialize(input);
            listA.GetItem(item, found);
            if(found) {
                item.Print(cout);
                cout << " was in listA\n";
            }
            else {
                item.Print(cout);
                cout << " was not in listA\n";
            }
        }
    } while(input != 0);

    // Allows the user to check if a number is in listB
    do {
        cout << "\nEnter a number to see if it is in listB. Enter 0 to exit: ";
        cin >> input;

        if(input != 0) { // Ensures the program does not check if zero is in the list
            item.Initialize(input);
            listB.GetItem(item, found);
            if(found) {
                item.Print(cout);
                cout << " was in listB\n";
            }
            else {
                item.Print(cout);
                cout << " was not in listB\n";
            }
        }
    } while(input != 0);

    // Displays both lists
    cout << "ListA is: ";
    printList(listA);
    cout << "\nListB is: ";
    printList(listB);  

    // Deletes both lists to free memory
    listA.ResetList();
    listA.MakeEmpty();
    
    listB.ResetList();
    listB.MakeEmpty();

    return 0;
}