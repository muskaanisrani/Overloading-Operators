//
//  myDate.cpp
//  CECS 282 program 3
//
//  Created by Muskaan Israni on 2/29/20.
//  Copyright © 2020 Muskaan Israni. All rights reserved.
//
#include "upDate.hpp"
#include <iostream>
#include <string.h>
using namespace std;


int upDate::julian()
{
    int m, d, y;
    m = dptr[0];
    d = dptr[1];
    y = dptr[2];
    
    int jd = d-32075+1461*(y+4800+(m-14)/12)/4+367*(m-2-(m-14)/12*12)/12-3*((y+4900+(m-14)/12)/100)/4;
    
    return jd;
}


void upDate::Julian2Greg(int JD, int &month, int &day, int &year)
{
    int l=JD+68569;
    int n=4*l/146097;
    l=l-(146097*n+3)/4;
    int i=4000*(l+1)/1461001;
    l=l-1461*i/4+31;
    int j=80*l/2447;
    int k=l-2447*j/80;
    l=j/11;
    j=j+2-12*l;
    i=100*(n-49)+i+l;
    
    year=i;
    month=j;
    day=k;

}


//default constructor
upDate::upDate(){
    dptr=new int[3];
    dptr[0]=5;
    dptr[1]=11;
    dptr[2]=1959;
    count++;
}


//overloaded constructor that takes in date from user
upDate::upDate(int userm,int userd,int usery) {
    dptr=new int[3];
    dptr[0]=userm;
    dptr[1]=userd;
    dptr[2]=usery;
    if (dptr[0]>12 || dptr[1]>31) {
        dptr[0]=5;
        dptr[1]=11;
        dptr[2]=1959;
    } else {
        dptr[0]=userm;
        dptr[1]=userd;
        dptr[2]=usery;
        
    }
    count++;
    
}



//copy constructor
upDate::upDate(const upDate &m) { //copy constructor called only when an update obj needed
    dptr=new int[3];
    dptr[0]=m.dptr[0];
    dptr[1]=m.dptr[1];
    dptr[2]=m.dptr[2];
    count++;
}


//destructor
upDate::~upDate() {
    count--;
    delete []dptr;
    
}

void upDate::increaseDate(int n) {
    int juliandatetoincrease=julian();
    //cout<<juliandatetoincrease;
    juliandatetoincrease=juliandatetoincrease+n;
    Julian2Greg(juliandatetoincrease, dptr[0], dptr[1], dptr[2]);
}


void upDate::decreaseDate(int d) {
    int juliandatetodecrease=julian();
    juliandatetodecrease=juliandatetodecrease-d;
    Julian2Greg(juliandatetodecrease,dptr[0], dptr[1], dptr[2]);
}

int upDate::daysBetween(upDate user) {
    int myjuliandate=julian();
    int userjuliandate=user.julian();
    int difference=myjuliandate-userjuliandate;
    return difference;
    
    
}


void upDate::setDate(int day, int month, int year) {
    dptr[1]=day;
    dptr[0]=month;
    dptr[2]=year;
    
}



int upDate::getMonth()
{
    return dptr[0];
}

int upDate::getDay()
{
    return dptr[1];
}

int upDate::getYear()
{
    return dptr[2];
}



string upDate::getMonthName() {
    string monthname="a";
    if (dptr[0]==1) {
        monthname="January";
    } else {
        if(dptr[0]==2) {
            monthname="February";
        } else {
            if (dptr[0]==3) {
                monthname="March";
            } else {
                if (dptr[0]==4) {
                    monthname="April";
                } else {
                    if (dptr[0]==5) {
                        monthname="May";
                    } else {
                        if (dptr[0]==6) {
                            monthname="June";
                        } else {
                            if (dptr[0]==7) {
                                monthname="July";
                            } else {
                                if (dptr[0]==8) {
                                    monthname="August";
                                } else {
                                    if (dptr[0]==9) {
                                        monthname="September";
                                    } else {
                                        if (dptr[0]==10) {
                                            monthname="October";
                                        } else {
                                            if (dptr[0]==11) {
                                                monthname="November";
                                            } else {
                                                if (dptr[0]==12) {
                                                    monthname="December";
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return monthname;
}


int upDate::count = 0;

int upDate::GetDateCount()
{
    return count;
}

//OPERATORS


upDate upDate::operator+(int x) {
    upDate temp(*this);
    temp.increaseDate(x);
    return temp;
}


upDate upDate::operator=(upDate d) {
    dptr[0] = d.dptr[0];
    dptr[1] = d.dptr[1];
    dptr[2] = d.dptr[2];
    return (*this);
}

upDate upDate::operator-(int x) {
    upDate temp(*this);
    temp.decreaseDate(x);
    return temp;
}

upDate operator +(int x, upDate D)
{
    return D + x;
}

int upDate::operator -(upDate D)
{
    int num = daysBetween(D);
    return num;
}

upDate operator -(int x, upDate D)
{
    return D - x;
}

ostream &operator <<(ostream &out, upDate D)
{
    out << D.getMonth() << "/" << D.getDay() << "/" << D.getYear();
    return out;
}



upDate upDate::operator --()
{
    decreaseDate(1);
    return (*this);
}

upDate upDate::operator ++()
{
    increaseDate(1);
    return (*this);
}

upDate upDate::operator ++(int dummy)
{
    increaseDate(1);
    return (*this);
}

upDate upDate::operator --(int dummy)
{
    decreaseDate(1);
    return (*this);
}

bool upDate::operator <(upDate T)
{
    if(julian() < T.julian())
        return true;
    
    return false;
}

bool upDate::operator > (upDate T)
{
    if(julian() > T.julian())
        return true;
    
    return false;
}

bool upDate::operator ==(upDate T)
{
    if(julian() == T.julian())
        return true;
    
    return false;
}
