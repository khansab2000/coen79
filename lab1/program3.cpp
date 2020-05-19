//  Coen 20 Thursday 2:15
//  program3.cpp
//  Lab1
//
//  Created by Sabiq Khan on 4/9/20.
//  Copyright © 2020 Sabiq Khan. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, const char * argv[]) {
    if(argc != 2){
        cout << "Don't forget the file name";
        return 0;
    } // checking to make sure there's a file
    
    string filetemp = "";
    string temp;
    string file(argv[1]);
    // creating the variables and bringing in the file from the argument
    
    ifstream in_file;
    in_file.open(file);
    // creating file pointer and opening the file
    
    while (true) {
        filetemp = ""; //always resetting the temp string to an empty string every time it gets to a new word
        in_file >> temp; //puts words from file into temp
        if (in_file.eof()) { //checks if the pointer has reached the end of the file
            break;
        }
        for(int i = 0; i < temp.length(); i++){ // traverses the word
                if(isalpha(temp[i])){ // only does it for alphanumeric characters
                    filetemp += toupper(temp[i]); // turning characters into capitals
                }
            }
        if(filetemp.length() >= 10){  //only prints out the word if word length >=10
            cout << filetemp << endl;
        }
        
    }
    
    return 0;
    
}
