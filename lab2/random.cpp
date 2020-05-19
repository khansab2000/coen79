//
//  random.cpp
//  Lab2
//
//  Created by Sabiq Khan on 4/22/20.
//  Copyright © 2020 Sabiq Khan. All rights reserved.
//

#include "random.hpp"
#include <stdio.h>

using namespace std;
using namespace coen79_lab2;

namespace coen79_lab2 {
    rand_gen :: rand_gen(int seed, int multiplier, int increment, int modulus) {
        this->seed = seed;
        this->multiplier = multiplier;
        this->increment = increment;
        this->modulus = modulus;
    } //using the this pointer to access the class and assign values to the variablesfrom the arguments
    
    void rand_gen :: set_seed(int seed) {
        this->seed = seed;
    } //setting a new seed value given by the argument of the function
    
    int rand_gen :: next() {
        int temp;
        temp = (this->multiplier * this->seed + this->increment) % this->modulus;
        this->seed = temp;
        return temp;
    } //changing the seed by using (Multiplier * Seed + Increment) % modulus
    
    void rand_gen :: print_info() const {
        cout << " Seed: " << this->seed << endl;
        cout << " Multiplier: " << this->multiplier << endl;
        cout << " Increment: " << this->increment << endl;
        cout << " Modulus: " << this->modulus << endl << endl;
    } //printing out values
}




