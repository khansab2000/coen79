//  Coen 20 Thursday 2:15
//  program4.cpp
//  Lab1
//
//  Created by Sabiq Khan on 4/9/20.
//  Copyright © 2020 Sabiq Khan. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    string yesno = "";  // input variable for user
    cout << "Think of a number between 1 and 20 \n";
    int guess;
    int numguesses = 0; // creating variables
    do {
        guess = (rand() % 20) + 1; // puts a value between 1 and 20 in guess
        cout << "Was your guess " << guess << endl;
        numguesses++; // increments the number of guesses
        getline(cin, yesno); // getting input from user
        if(yesno == "y"){
            cout << "Successfully guessed number in " << numguesses << " attempts \n";
            return 0;
        }
        else if(yesno == "n"){
            cout << "Let's try again \n";
        }
        else{ //checking for valid input
            cout << "Enter only 'y' or 'n'\n ";
        }
    } while (yesno != "y"); //loop continues until number is correctly guessed
    
}
