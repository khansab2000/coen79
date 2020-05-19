//
//  keyed_bag.cpp
//  keyed_bag
//
//  Created by Sabiq Khan on 5/7/20.
//  Copyright © 2020 Sabiq Khan. All rights reserved.
//


#include <iostream>
#include <cassert>
#include <cstdlib>     
#include <cmath>
#include "keyed_bag.h"

using namespace std;

namespace coen79_lab4 {

    // Constructor: initializes an empty keyed_bag
    keyed_bag::keyed_bag() {
        for(int i = 0; i < CAPACITY; i++) {
            keys[i] = '\0';
            data[i] = NULL;
        }
        used = 0;
    }

    // Empties all data and keys
    void keyed_bag::erase() {
        for(int i = 0; i < used; i++) {
            keys[i] = '\0';
            data[i] = NULL;
        }
        used = 0;
    }
    
    // Search for a key, then delete data and return true, or return false if key not found
    bool keyed_bag::erase(const key_type& key) {
        assert(used > 0);                         
        for(int i = 0; i < used; i++) {
            if(keys[i] == key) {
                for(int j = i; j < used-1 ; j++) {
                    keys[j] = keys[j+1];
                    data[j] = data[j+1];
                }
                used--;
                return true;
            }
        }
        return false;
    }
    
    // entry added to data and corresponding key added
    void keyed_bag::insert(const value_type& entry, const key_type& key) {
        assert((size() < CAPACITY) && (has_key(key) == false));
        keys[used] = key;
        data[used] = entry;
        used++;
    }
    
    // Each item and key in addend bag has been added to `this` bag
    void keyed_bag::operator+=(const keyed_bag& addend) {
        assert(size() + addend.size() <= CAPACITY);
        for(int i = 0; i < addend.used; i++) {
            if( !has_key(addend.keys[i]) ) {
                keys[used] = addend.keys[i];
                data[used] = addend.data[i];
                used++;
            }
        }
    }

    // Return if given key exists or not
    bool keyed_bag::has_key(const key_type& key) const {
        for(int i = 0; i < used; i++) {
            if(keys[i] == key) {
                return true;
            }
        }
        return false;
    }
    
    // Returns value corresponding to given key
    keyed_bag::value_type keyed_bag::get(const key_type& key) const {
        assert(has_key(key));
        for(int i = 0; i < used; i++) {
            if(keys[i] == key) {
                return data[i];
            }
        }
        return NULL;
    }
    
    // Returns total number of items in current bag
    keyed_bag::size_type keyed_bag::size() const {
        return used;
    }

    // Returns total number of times target value is in data[]
    keyed_bag::size_type keyed_bag::count(const value_type& target) const {
        size_type count = 0;
        for(int i = 0; i < used; i++) {
            if(data[i] == target) {
                count++;
            }
        }
        return count;
    }
    
    // Checks for duplicate key
    bool keyed_bag::hasDuplicateKey(const keyed_bag& otherBag) const {
        for(int i = 0; i < otherBag.used; ++i) {
            if( has_key(otherBag.keys[i]) ) {
                return true;
            }
        }
        return false;
    }
    

    // Returns union of bag 1 and 2
    keyed_bag operator+(const keyed_bag& b1, const keyed_bag& b2) {
        assert((b1.size()+b2.size()) <= keyed_bag::CAPACITY);
        keyed_bag temp;
        temp += b1;
        temp += b2;
        return temp;
    }
}
