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
#include "hash.h"


using namespace std;

int main() {

    Hash hash(100);

    hash.add("Fantastic");

    hash.add("Foo");
    
    hash.add("BAR");

    cout << "number of strings in the list: " << hash.size() << endl;



    return 0;
}