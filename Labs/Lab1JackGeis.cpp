// C++ program to illustrate call-by-methods in C++

#include <bits/stdc++.h>
using namespace std;
//Pass-by-Value
int square1(int n)
{
	//Is the address of n in square1() the same as n1 in main()??? Why???
	// No, becasue in the fuction call passed what n1 contained in memory, not the memory addr. of n1.
	cout << "address of n1 in square1(): " << &n << "\n";
	
	// clone modified inside the function
	n *= n;
	return n;
}
//Pass-by-Reference with pointers
void square2(int *n)
{
	//Is the address of n in square2() the same as n2 in main()??? Why???
	// Yes, because the address is passed to the function, not the value stored in the address.
	// Using dereferencing the function is able to access the value stored in the address.
	cout << "address of n2 in square2(): " << n << "\n";
	
	// Explicit de-referencing to get the value pointed-to
	*n *= *n;
}
//Pass-by-Reference with arguments
void square3(int &n)
{
	//Is the address of n in square3() the same as n3 in main()??? Why???
	// Yes, because the address is passed to the function, not the value stored in the address.
	// Using dereferencing the function is able to access the value stored in the address.
	cout << "address of n3 in square3(): " << &n << "\n";
	
	// Implicit de-referencing (without '*')
	n *= n;
}
void geeks()
{
	//Call-by-Value
	int n1=8;
	cout << "address of n1 in main(): " << &n1 << "\n";
	cout << "Square of n1: " << square1(n1) << "\n";
	cout << "n1: " << n1 << "\n";
	//Is there a change to n1??? Why???
	// No, because a value is passed to square1, not the memory location of where that value is store.
	// So, square1 cannot change what is contained in n1.

	//Call-by-Reference with pointers
	int n2=8;
	cout << "address of n2 in main(): " << &n2 << "\n";
	square2(&n2);
	cout << "Square of n2: " << n2 << "\n";
	cout << "n2: " << n2 << "\n";
	//Is there a change to n2??? Why???
	// Yes, because the addr. is passed to the function, so the function goes to the addr. and changes 
	// the value stored inside.
	
	//Call-by-Reference with arguments
	int n3=8;
	cout << "address of n3 in main(): " << &n3 << "\n";
	square3(n3);
	cout << "Square of n3: " << n3 << "\n";
	cout << "Change reflected in n3: " << n3 << "\n";
	// Is there a change to n3??? Why???
	// Yes, because the function uses an argument to recieve the address of n3, so changes
	// the value stored at that address.
	
	
}
//Driver program
int main()
{
	geeks();
}

//What is the output of this program???
// The memory addresses of n in square1, 2, and 3, along with what is contained within the addresses.
// the memory addresses of n1, n2, and n3 along with what is contained within the addresses after the
// respective functions have executed.

//How many functions are in this program???
// four

//How many different ways were data passed to the functions???
// three, value, reference with pointers, and reference with arguments

//What is the Principle of Least Privilege???
// constant data passed as a constant
// constant data passed as a non-constant
// non-constant data passed as a constant
// non-constant data passed as a non-constant

//Put the ways that data was passed to functions in order from least privilege to most privilege???
/* Compile and run the program and past the results here

address of n1 in main(): 0xffffcbec
Square of n1: address of n1 in square1(): 0xffffcbc0
64
n1: 8
address of n2 in main(): 0xffffcbe8
address of n2 in square2(): 0xffffcbe8
Square of n2: 64
n2: 64
address of n3 in main(): 0xffffcbe4
address of n3 in square3(): 0xffffcbe4
Square of n3: 64
Change reflected in n3: 64

*/ 
