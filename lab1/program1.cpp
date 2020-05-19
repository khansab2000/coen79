//  Coen 20 Thursday 2:15
//  program1.cpp
//  Lab1
//
//  Created by Sabiq Khan on 4/9/20.
//  Copyright © 2020 Sabiq Khan. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    string sentence = "";
    int alphacnt = 0;
    int nonalphacnt = 0;  //setting variables
    
    cout << "Say something \n";
    getline(cin, sentence); //getting input from user
    int i = 0;
    
    for (i = 0; i < sentence.length(); i++) {
        if(sentence[i] != ' '){     //discounting spaces
            if(isalnum(sentence[i])){
                alphacnt++;  //incrementing alphanumeric count
            }
            else{
                nonalphacnt++;  //incrementing non alphanumeric count
            }
        }
    }
    
    cout << sentence << " has " << alphacnt << " alphanumeric characters and " << nonalphacnt << " non-alphanumeric characters \n";
    
    
    
    return 0;
}
