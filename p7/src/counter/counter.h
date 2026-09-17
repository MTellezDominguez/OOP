#ifndef COUNTER_H
#define COUNTER_H

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
#include "counter.h"

class Counter{
    private:
        int value_;
        int min_;
        int max_;
    public:
        Counter(int value=0, int min=0, int max=1000);
        int Get()const {return value_;};
        int GetMin()const{return min_;};
        int GetMax()const{return max_;};
        Counter& operator=(const Counter& cont);
        Counter& operator=(int value);
        Counter& operator++();//++c
        Counter operator++(int);//c++
        Counter& operator--();//--c
        Counter operator--(int);//c--
        Counter operator+(int suma) const;
        Counter operator-(int resta) const;
        friend Counter operator-(int n, const Counter& c);
        friend Counter operator+(int n, const Counter& c);
        friend std::ostream& operator<<(std::ostream& os, const Counter& c);
        friend std::istream& operator>>(std::istream& is, Counter& c);
}; 

#endif