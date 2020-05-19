//
//  statistician.cpp
//  Lab2
//
//  Created by Sabiq Khan on 4/22/20.
//  Copyright © 2020 Sabiq Khan. All rights reserved.
//

#include <iostream>
#include <cassert>
#include "statistician.hpp"

using namespace coen79_lab2;
using namespace std;

namespace coen79_lab2
{
    statistician :: statistician() {
      this->reset();
    } //initializing values

    void statistician :: next(double r) {
        last = r;
        total += r;
        if (count == 0){
            smallest = r;
            largest = r;
        }
        count++;
        smallest = (r < smallest) ? r : smallest;
        largest = (r > largest) ? r : largest;
    
    } //updates all the private variables

    void statistician :: reset() {
        count = 0;
        total = 0;
        smallest = NULL;
        largest = NULL;
        last = 0;
    } //resets all the values to 0
    
    double statistician :: mean() const {
        assert(count > 0);
        return total/count;
    } // finding the mean

    double statistician :: minimum() const {
        assert(count > 0);
        return smallest;
    } //finding the minimum

    double statistician :: maximum() const {
        assert(count > 0);
        return largest;
    } //finding the maximum

    statistician operator + (const statistician &s1, const statistician &s2) {
        statistician temp(s1);
        temp.count += s2.count;
        temp.total += s2.total;
        temp.smallest = (temp.smallest < s2.smallest) ? temp.smallest : s2.smallest;
        temp.largest = (temp.largest > s2.largest) ? temp.largest : s2.largest;
        temp.last = s2.last;
        return temp;
    } // friend function which adds up the sums, the counts, and finds a new min and max, and sets the last as the last of the second set, returns statistician object

    statistician operator * (double scale, const statistician &s) {
        int swap;
        statistician temp(s);
        temp.total *= scale;
        temp.smallest *= scale;
        temp.largest *= scale;
        if (scale < 0) {
            swap = temp.smallest;
            temp.smallest = temp.largest;
            temp.largest = swap;
        }
        temp.last *= scale;
        return temp;
    } // friend function which multiplies all of the parameters by a scale, and returns a statistician object

    bool operator == (const statistician &s1, const statistician &s2) {
        if (s1.length() == 0 && s2.length() == 0)
                   return true;
        else if (s1.length() == s2.length() && s1.sum() == s2.sum() && s1.minimum() == s2.minimum() && s1.maximum() == s2.maximum()) {
                   return true;
               }
        else {
                   return false;
            }
    } // friend function which returns true if they are both empty sets, true if all the parameters match, and false otherwise
}

