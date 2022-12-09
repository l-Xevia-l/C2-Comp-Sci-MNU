/*
|-----------------------------------------------------------------------------|
Author: Jack Geis
Date Created: //2022
Date Last Modified: //2022
Assignment: 
|-----------------------------------------------------------------------------|
*/



#include <iostream>
#include <array>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include "hashtest.h"


using namespace std;

int main() {

    Hash hash(100);

    hash.add("Bar");

    hash.add("Bar");

    cout << "should be 1: " << hash.contains("Bar") << endl;

    cout << "should be 0: " << hash.contains("foobar") << endl;
    
    hash.add("foobar");

    cout << "should be 1: " << hash.contains("foobar") << endl;
    
    return 0;
}