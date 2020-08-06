//
//  upDate.hpp
//  CECS 282 PROG 4 overloading operators
//
//  Created by Muskaan Israni on 4/17/20.
//  Copyright © 2020 Muskaan Israni. All rights reserved.
//

#ifndef upDate_hpp
#define upDate_hpp
#include <iostream>
using namespace std;
#include <stdio.h>


class upDate {
    
private:
   /* int M;
    int D;
    int Y;
    */
    int *dptr;
    static int count;
    
public:
    
    upDate();
    upDate(int userm,int userd,int usery);
    upDate(const upDate &m);
    upDate(int j);
    ~upDate();
    void setDate(int D, int M, int Y);
    string getMonthName();
    int getMonth();
    int getDay();
    int getYear();
    void increaseDate(int n);
    void decreaseDate(int d);
    int daysBetween(upDate user);
    static int GetDateCount();
    int julian();
    void Julian2Greg(int JD, int &month, int &day, int &year);
    
    upDate operator+(int n);
    upDate operator-(int n);
    upDate operator =(upDate T);
    bool operator==(upDate D);
    bool operator<(upDate D);
    bool operator>(upDate D);
    int operator -(upDate D);
    friend upDate operator +(int n, upDate D);
    friend upDate operator -(int n, upDate D);
    
    
    
    
    friend ostream &operator <<(ostream &out, upDate D);
    
    
     
    upDate operator ++(int d);
    upDate operator ++();
    upDate operator --(int d);
    upDate operator --();


    
    
    
    
    
    
};

#endif 




