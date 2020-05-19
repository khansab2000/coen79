//
//  sequence.cpp
//  Lab3
//
//  Created by Sabiq Khan on 4/29/20.
//  Copyright © 2020 Sabiq Khan. All rights reserved.
//

#include <cassert>
#include <stdio.h>
#include <iostream>
#include <cmath>
#include "sequence1.h"

using namespace std;

namespace coen79_lab3 {
    
    sequence::sequence(){
        used = 0;
        cur_index = 0;
    }

    
    void sequence::start(){
       cur_index = 0;
    }
    
    void sequence::end(){
        cur_index = size () - 1;
    }
    
    void sequence::last(){
        cur_index = CAPACITY - 1;
        
    }
    
    void sequence::advance(){
        assert(is_item());
        if(cur_index < used)
            cur_index++;
    }
    
    void sequence::retreat(){
        if(cur_index > 0)
            cur_index--;
    }
    
    void sequence::insert(const value_type& entry){
        assert(size() < CAPACITY);
        cur_index = (cur_index < size()) ? cur_index : 0;
        for (size_type i = used; i > cur_index; i--){
            data[i] = data[i - 1];
        }
        data[cur_index] = entry;
        used++;
    }

    void sequence::attach(const value_type& entry){
        assert(size() < CAPACITY);
        cur_index = (cur_index + 1 < size()) ? cur_index + 1 : size();
            for (size_type i = used; i > cur_index; i--){
                data[i] = data[i - 1];
            }
            data[cur_index] = entry;
            
            used++;
        }
    
    void sequence::remove_current(){
        assert(is_item());
        for(size_type i = cur_index; i < size() - 1; i++){
            data[i]=data[i + 1];
        }
        used--;
    }
    
    void sequence::insert_front(const value_type& entry){
        assert(size() < CAPACITY);
        cur_index = 0;
        insert(entry);
        used++;
    }
    
    void sequence::attach_back(const value_type& entry) {
        assert(size() < CAPACITY);
        data[used] = entry;
        cur_index = size();
        used++;
    }
   
    void sequence::remove_front() {
        assert(is_item());
        for(size_type i = 0; i < used - 1; ++i)
            data[i]=data[i+1];
        used--;
    }
    
    void sequence::operator +=(const sequence& rhs){
        assert((used + rhs.used) < CAPACITY);
        size_type tmp = rhs.used;
        for(int i = 0; i < tmp; i++) {
            data[used++] = rhs.data[i];
        }
    }

    sequence::size_type sequence::size() const{
        return used;
    }
    
    bool sequence::is_item() const {
        return cur_index < size();
    }

    sequence::value_type sequence::current() const{
        assert(is_item());
        return data[cur_index];
    }
    
    sequence::value_type sequence::operator[](int index) const{
        assert(index < used);
        return data[index];
    }
    
    double sequence::mean() const {
        double temp = 0;
            for(size_type i = 0; i < size(); i++){
                temp += data[i];
            }
            return temp/size();
        }

    double sequence::standardDeviation() const {
        value_type stdev = 0.0;
        value_type mean = sequence::mean();
        for(int i = 0; i < used; ++i) {
            stdev += pow(data[i] - mean, 2);
        }
        return sqrt(stdev/used);
    }
    
    sequence operator+(const sequence& lhs, const sequence& rhs){
        assert((lhs.size() + rhs.size()) <= sequence::CAPACITY);
        sequence(tmp);
        tmp += lhs;
        tmp += rhs;
        return tmp;
    }
    
    sequence::value_type summation(const sequence &s){
        sequence temp = s;
        sequence::value_type sum = 0;
        temp.start();
        for(sequence::size_type i = 0; i < temp.size(); i++){
            sum += temp.current();
            temp.advance();
        }
        return sum;
    }
}
