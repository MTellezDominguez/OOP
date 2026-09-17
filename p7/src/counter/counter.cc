#include "counter.h"
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <limits.h>
#include <list>
#include <map>
#include "persons.h"
#include "catalog.h"
#include "stage.h"
#include "gclist.h"

Counter::Counter(int value, int min, int max) {
    if (min > max || value < min || value > max) {
        value_ = 0;
        min_ = 0;
        max_ = 1000;
    } else {
        min_ = min;
        max_ = max;
        value_ = value;
    }
}

Counter& Counter::operator=(const Counter& cont) {
    if (this == &cont) {
        return *this;
    }
    min_=cont.min_;
    max_=cont.max_;
    value_=cont.value_;
    return *this;
}

Counter& Counter::operator=(int value) {
    if (value > max_) {
        value_ = max_;
    }
    else if (value < min_) {
        value_ = min_;
    }
    else {
        value_ = value;
    }
    return * this;
}

Counter& Counter::operator++() {
    value_++;
    if((value_)>max_){
        value_ = max_;
    }
    return *this;
}

Counter Counter::operator++(int) {
    Counter temp=*this;
    value_++;
    if((value_)>max_){
        value_ = max_;
    }
    return temp;
}

Counter& Counter::operator--() {
    value_--;
    if((value_)<min_){
        value_=min_;
    }
    return *this;
}

Counter Counter::operator--(int) {
    Counter temp=*this;
    value_--;
    if((value_)<min_){
        value_=min_;
    }
    return temp;
}

Counter Counter::operator+(int suma) const{
    int nuevo_val = value_ + suma;
    
    if (nuevo_val > max_) nuevo_val = max_;
    if (nuevo_val < min_) nuevo_val = min_;
    
    return Counter(nuevo_val, min_, max_);
}

Counter Counter::operator-(int resta) const{
    int nuevo_val = value_ - resta;
    
    if (nuevo_val < min_) nuevo_val = min_;
    if (nuevo_val > max_) nuevo_val = max_;
    
    return Counter(nuevo_val, min_, max_);
}

Counter operator+(int n, const Counter& c) {
    int nuevo_val = n + c.value_;
    
    if (nuevo_val > c.max_) nuevo_val = c.max_;
    if (nuevo_val < c.min_) nuevo_val = c.min_;
    
    return Counter(nuevo_val, c.min_, c.max_);

}

Counter operator-(int n, const Counter& c) {
    int nuevo_val = n - c.value_;
    
    if (nuevo_val > c.max_) nuevo_val = c.max_;
    if (nuevo_val < c.min_) nuevo_val = c.min_;
    
    return Counter(nuevo_val, c.min_, c.max_);
}

std::ostream& operator<<(std::ostream& os, const Counter& c) {
    os<<c.value_;
    return os;
}

std::istream& operator>>(std::istream& is, Counter& c) {
int input;
    while(true) {
        is >> input;
        
        if (is.fail()) {
            is.clear();
            is.ignore(1000, '\n');
            continue;
        }

        if (input >= c.min_ && input <= c.max_) {
            c.value_ = input;
            break;
        }

    }
    return is;
}