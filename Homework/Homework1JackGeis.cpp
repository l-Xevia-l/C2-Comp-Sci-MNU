/*
|-----------------------------------------------------------------------------|
Author: Jack Geis
Date Created: 9/20/2022
Date Last Modified: 9/20/2022
Assignment: Add two functions to Lab3. is_present and delete_value.

 is_present is passed a pointer to the head and a value and returns true
 if that value is in the linked list.

 delete_value is passed a pointer to the head of the list and a value. 
 Uses is_present to see if the value is in the linked list, the deletes it.
|-----------------------------------------------------------------------------|
*/
#include <iostream>

using namespace std;

struct node_t{
    int data;
    node_t* next;
};

// Adds the value on the end of the linked list starting from node.
node_t * push_back(int value, node_t* node){
    if(node == NULL) {
        node = new node_t;
        node->data = value;
        node->next = NULL;
    }
    else {
        // Walk to end
        node_t * temp = node;
        while(temp->next != NULL){
            temp = temp->next;
        }
        // put a node on the end
        temp->next = new node_t;
        temp->next->data = value;
        temp->next->next = NULL;
    }
    return node;
}

// Prints the linked list starting from node.
void print(node_t* node){
    // Walk the list and print
    while(node->next != NULL){
        cout << node->data << " ";
        node = node->next;
    }
    cout << node->data << " ";
    cout << endl;
}

// Add value to every element of the linked list.
void add(node_t* node, int value){
    while(node != NULL){
        node->data += value;
        node = node->next;
    }
}

// Returns a new linked list, based on one starting with node, but in the reverse
// order.
node_t* reverse(node_t* node){
    if(!node)return NULL;
    // Walk down the good linked list
    node_t* last = NULL;
    while(node != NULL){
        node_t* temp = new node_t;
        temp->data = node->data;
        temp->next = last;
        node = node->next;
        last = temp;
    }
    return last;
}

void freeMem(node_t* node){
    node_t * temp = new node_t;
    while(node) {
        temp = node->next;
        delete node;
        node = temp;
    }
}

/*  Input: node_t pointer to the head and an integer value
    Output: Boolean value
    Desc: Takes a pointer to the head and an integer value. Returns true if the integer value is in the
        linked list */
bool is_present(node_t * node, int value){
    bool present = false;
    node_t * temp = node;
    
    // iterates through the linked list until the end of the list or the value is found.
    while((temp != NULL) & (present == false)) {
        if (temp->data == value){
            return true;
        }
        temp = temp->next;
    }
    return false;
}

/*  Input: node_t pointer to a head and an integer value
    Output: N/A
    Desc: If the passed integer value is present in the passed linked list, deletes that value */
void delete_value(node_t * &node, int value){
    // Checks if the integer value is in the linked list
    if (is_present(node, value)) {

        // If the value the first in the list, uses a different means to delete it.
        if (node->data == value){
            node_t * temp = node;
            node = node->next;
            delete temp;
        }
        // If the integer is in the middle or end of the list...
        else{
            // temporary ptr
            node_t * previousNode = NULL;
            node_t * temp = node;
            // iterates until the node that temp is pointing to contains the value to delete
            while(temp->data != value) {

                // keeps a pointer to the node that is pointing to the same node as temp
                previousNode = temp;

                // Moves temp up the list by one node
                temp = temp->next;
            }
            
            previousNode->next = temp->next;
            delete temp;
        }
    }
}

int main(){
    node_t * head = NULL;
    
    head = push_back(1, head);
    head = push_back(2, head);
    head = push_back(3, head);
    head = push_back(4, head);
    
    cout << "Should be 1 2 3 4 = ";
    print(head);
    
    
    add(head, 10);
    
    cout << "Should be 11 12 13 14 = ";
    print(head);
    
    node_t* rev = reverse(head);
    cout << "Should be 14 13 12 11 = ";
    print(rev);
    
    cout << boolalpha << "Is 13 in the list? Should be true = " << is_present(head, 13) << endl;
    cout << boolalpha << "Is 15 in the list? Should be false = " << is_present(head, 15) << endl;
    
    delete_value(head, 13);

    cout << "Should be 11 12 14 = ";
    print(head);

    delete_value(head, 11);
    
    cout << "Should now be 12 14 = ";
    print(head);

    // Return the memory from the linked lists
    freeMem(head);
    head = NULL;
    freeMem(rev);
    rev = NULL;
}