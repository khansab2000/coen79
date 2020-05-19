//
//  mystring.cpp
//  lab5
//
//  Created by Sabiq Khan on 5/14/20.
//  Copyright © 2020 Sabiq Khan. All rights reserved.
//

#include <iostream>
#include <cassert>
#include <string.h>
#include "mystring.h"
#include <cctype>              //isspace()
using namespace std;

namespace coen79_lab5 {
    
    // CONSTRUCTORS
    
    // creates string with char from str[]
    string::string(const char str[]){
        current_length = strlen(str);
        allocated = current_length + 1;                              // allocate for length of str +1
        characters = new char[allocated];
        strncpy(characters, str, allocated);                         // copy to destination characters from str with size allocated
    }

    // creates string with c and null
    string::string(char c){
        current_length = 1;
        allocated = current_length + 1;                              // allocate for length+1
        characters = new char[allocated];
        characters[0] = c;                                           // put c into characters
        characters[1] = '\0';                                        // end with null
    }
    
    // creates copy of source
    string::string(const string& source){
        current_length = source.current_length;
        allocated = source.allocated;
        characters = new char[source.current_length];                // create new array of same size
        strncpy(characters, source.characters, source.current_length); // copy to new array
    }

    // destructor
    string::~string(){
        current_length = 0;                                          // set all variables to 0
        allocated = 0;
        delete[] characters;                                         // delete characters array on heap
    }

    // MODIFICATION MEMBER FUNCTIONS

    void string::operator+=(const string& addend){
        current_length = current_length + addend.current_length;
        allocated = current_length + 1;                              // allocated is lengths+1
        reserve(allocated);                                            //reserve more space
        current_length = current_length + addend.current_length;
        strncat(characters, addend.characters, addend.current_length); // then concat addend to current string
    }
    
    // Addend array of chars
    void string::operator+=(const char addend[]){
        allocated = current_length + 1 + strlen(addend);                              // allocated is lengths+1
        reserve(allocated);                                          // reserve more space
        current_length = current_length + strlen(addend);
        strncat(characters, addend, strlen(addend));                 // then concat addend[] to current string
    }

    // Addend single char
    void string::operator+=(char addend){
        current_length += 1;
        allocated = current_length + 1;                              // increase allocated by one
        reserve(allocated);
        characters[current_length] = addend;
        characters[current_length + 1] = '\0';
    }

    // reserving space
    void string::reserve(size_t n){
        char* tmp = new char[n];                                     // Create new heap array with size n
        if (characters != NULL){                                     // check that calling string isn't empty
            strncpy(tmp, characters, current_length);                // copy characters -> tmp
            delete[] characters;
        }
        characters = tmp;
    }

    // Assigns source to a pointer of changed string `this`
    string& string::operator=(const string& source){
        this->dlt(0, current_length);                                // Delete all characters in `this` string
        if (current_length != source.current_length){                // check if we need to change size of `this` string
            allocated = source.allocated;
            reserve(allocated);                                      // reserve more/less size to source's size
        }
        strncpy(characters, source.characters, source.current_length);
        current_length = source.current_length;                      // update length with source's length
        return *this;                                                //return dereferenced ptr
    }
    
    // Inserts a source string into `this` string at given index `position`
    void string::insert(const string& source, unsigned int position){
        assert(position <= length());
        size_t total_length = current_length + source.current_length;
        if (allocated < (total_length))                              // check if we need to reserve more array size
            reserve(total_length);                                   // reserve more array size
        for(int i = length(); i > position; i--)                     // shift string to make space
            characters[i] = characters[i-1];
        for(int i = 0; i < source.length(); i++)
            characters[position+i] = source.characters[i];           // input in made space
        current_length = total_length;
    }
    
    // deletes a certain amount of characters starting at a specific index
    void string::dlt(unsigned int position, unsigned int num){
        assert( (position + num) <= length() );                      // Check that we're not deleting past length of array
        for(int i = position; i < length(); i++)
            characters[i] = characters[i+num];
        current_length = current_length -num;
    }
    
    // The characters in `this` string starting at index `position` replaced by character c in `this`
    void string::replace(char c, unsigned int position){
        assert(position < length());                                 // Check that replacing position isn't past the array length
        characters[position] = c;
    }
    
    // string is replaced by source string from specific index
    void string::replace(const string& source, unsigned int position){
        assert( (position + source.length() ) <= length() );
        int i, j;
        for(i = position, j = 0; i < (position + source.length()); i++)
            characters[i] = source[j++];
    }
    
    // CONSTANT MEMBER FUNCTIONS

    // returns the character at index
    char string::operator[](size_t position) const{
        assert(position < length());
        return characters[position];
    }

    // Return index of first occurrence of input
    int string::search(char c) const{
        for(int i = 0; i < length(); i++){
            if (characters[i] == c)
                return i;
        }
        return -1;                                                   // if we don't find character, return -1
    }

    // Returns index of first occurrence of substring in input
    int string::search(const string& substring) const{
        char* temp = strstr(characters, substring.characters);       // strstr returns a pointer to where substring starts in string
        if(temp != NULL) {                                           // check that pointer isn't null (strstr didn't fail)
            return temp[0] - characters[0];                          // take location of temp subtract location of characters
        }
        return -1;                                                   // if strstr failed (aka substring doesn't exist), return -1
    }
    
    // Returns how many occurrences of input exists in `this` string
    unsigned int string::count(char c) const{
        unsigned int counter = 0;
        for(int i = 0; i < length(); i++){
            if(characters[i] == c)
                counter++;
        }
        return counter;
    }

    // NON-MEMBER FUNCTIONS
    // Returns the concatenation of string s1 and s2
    string operator+(const string& s1, const string& s2){
        string temp;                                                 // Create temporary string
        temp.reserve(s1.length()+s2.length()+1);
        temp += s1;
        temp += s2;
        return temp;                                                 // return our temporary string
    }

    // Returns the concatenation of string s1 and char array addend[]
    string operator +(const string& s1, const char addend[ ]){
        string temp;
        temp.reserve(s1.length()+strlen(addend)+1);
        temp += s1;
        temp += addend;
        return temp;
    }

    // A string has been read from istream ins and returns a new istream object with the
    // sequence of characters without whitespace (no blanks, newlines, tabs)
    std::istream& operator >> (std::istream& ins, string& target){
        char* buffer = new char[100];                                // Create new buffer
        while(ins && isspace(ins.peek()))
            ins.ignore();                                            // ignore all whitespace
        ins >> buffer;                                               // input -> buffer
        target = string(buffer);
        return ins;
    }

    // FRIEND FUNCTIONS
    // Returns ostream object containing sequence of characters from source
    std::ostream& operator <<(std::ostream& outs, const string& source){
        outs << source.characters;
        return outs;
    }

    bool operator ==(const string& s1, const string& s2)              // check for same string
        { return (strcmp(s1.characters, s2.characters) == 0); }

    bool operator !=(const string& s1, const string& s2)             // check if not same string
        {
            return (strcmp(s1.characters, s2.characters) != 0); }
    
    bool operator > (const string& s1, const string& s2)            // check for higher ASCII
        {
            return (strcmp(s1.characters, s2.characters) > 0); }
    
    bool operator < (const string& s1, const string& s2)           // check for lower ASCII
        {
            return (strcmp(s1.characters, s2.characters) < 0); }
    
    bool operator >=(const string& s1, const string& s2)            // check if higher ascii or equal to
        {
            return ((s1 > s2) || (s1 == s2)); }                       // reuse our > and == operator
    
    bool operator <=(const string& s1, const string& s2)           // check if lower ascii or equal to
        {
            return ((s1 < s2) || (s1 == s2)); }
}
