/* C++ program to implement basic stack
	     operations */
#include <bits/stdc++.h>
#include <string>
 
using namespace std;
 
#define MAX 1000
 
class Stack {
    int top;
     
	public:
        int a[MAX]; // Maximum size of Stack
		 
	Stack() { top = -1; }
        bool push(char x);
	char pop();
	char peek();
	bool isEmpty();
};
 
bool Stack::push(char x)
{
	if (top >= (MAX - 1)) {
            cout << "Stack Overflow";
            return false;
        }
        else {
            a[++top] = x;
            cout << x << " pushed into stack\n";
            return true;
        }
}
 
char Stack::pop()
{
	    if (top < 0) {
		            cout << "Stack Underflow";
			            return 0;
				        }
	        else {
			        char x = a[top--];
				        return x;
					    }
}
char Stack::peek()
{
	    if (top < 0) {
		            cout << "Stack is Empty";
			            return 0;
				        }
	        else {
			        char x = a[top];
				        return x;
					    }
}
 
bool Stack::isEmpty()
{
	    return (top < 0);
}
 
// Driver program to test above functions
int main()
{
    class Stack s;
    s.push('a');
    s.push('b');
    s.push('c');
    cout << s.pop() << " Popped from stack\n";
//print all elements in stack :
    cout<<"Elements present in stack : ";
    while(!s.isEmpty())
    {
    // print top element in stack
           cout<<s.peek()<<" ";
    // remove top element in stack
           s.pop();
    }
    cout<< "\n";

    /* ----------------------My Code---------------------- */
    string equation;
    class Stack parenthesis;
    bool closingPar{false}; // if set to true, means that there were too many closing brackets in the string

    cout << "Input an equation with an equal or unequal amount of parenthesis using '(' or ')': ";
    cin >> equation;

    int len = equation.length(); // gets length of the string for the while loop
    int i{0}; //counter variable to exit the while loop at the correct time

    // iterates through the entire string of equation unless too many closing parenthesis are found
    while((i < len) && (closingPar == false)) { 

        // if the current char is a opening parenthesis, pushes it onto the stack "parenthesis"
        if(equation[i] == '(') {
            parenthesis.push(equation[i]);
        }

        // if the current char is a closing parenthesis, pops an item off of the stack "parenthesis"
        if(equation[i] == ')') {

            // if the stack is empty, the member function returns zero. This means that there are too many
            // closing parentheis
            if(parenthesis.pop() == 0){
                cout << "Your equation had too many closing parenthesis!\n";
                closingPar = true; // Quits the loop
            }
        }

        i++; // increments the counter
    }

    // if the stack is empty and there were not too manu closing brackets, displays that there 
    // were the correct amount of opening and closing brackets 
    if((parenthesis.isEmpty() == true) && (closingPar == false)) {
        cout << "Your equation had an equal amount of opening and closing parenthesis.\n";
    }
    // if there are items left on the stack, there were too many opening brackets
    else if(parenthesis.isEmpty() == false){
        cout << "Your equation had too many opening parenthesis!\n";
    }

    return 0;
}
