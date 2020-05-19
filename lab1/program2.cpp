//  Coen 20 Thursday 2:15
//  program2.cpp
//  Lab1
//
//  Created by Sabiq Khan on 4/9/20.
//  Copyright © 2020 Sabiq Khan. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    string digits = "";
    cout << "Enter 10 digits\n";
    getline(cin, digits);  //getting digit input from user
    
    if(digits.length() != 10){
        cout << "Must be 10 digits \n";
        return 0;  //making sure they input 10 digits
    }
    
    string originaldigits = digits;  //creating an array to hold the original digits
    int n = digits.length();
    for(int i = 0; i < n/2; i++){
        swap(digits[i], digits[n-i-1]); // inverting the digits and storing them in the digits array
    }
    
    cout << originaldigits;
    cout << "     " << digits << endl;
    
    cout << " " << originaldigits;
    cout << "      " << digits << endl;
    
    cout << "  " << originaldigits;
    cout << "       " << digits << endl;
    
    cout << "   " << originaldigits;
    cout << "        " << digits << endl;
    
    cout << "    " << originaldigits;
    cout << "         " << digits << endl;
    
    //printing out the digits in the manner it was assigned
    
    
    
}
