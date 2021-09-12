//=======================================================================
//==========coursera final project cfp_date class declaration============
//=======================================================================

#pragma once

#ifndef CFP_DATE_CLS_H
#define CFP_DATE_CLS_H

#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <numeric>
#include <array>

using namespace std;

//=======================================================================

class Date {
protected: 
    int y; //year
    unsigned short int m,d; //month //day
    array <unsigned short int,12> days_in_month = {31,28,31,30,31,30,31,31,30,31,30,31};
    //functions
public:
    void Days_To_Date(const int& total_days);
    int Date_To_Days () const;
    string DateToStr() const;
    //constructors
    Date();
    Date(int year, unsigned short int month, unsigned short int day);
    Date(const Date &other); 
    //destructor
    virtual ~Date();
//=======================================================================
    //functions
    //setters
    void operator()(const int& year, const unsigned short int& month, const unsigned short int& day);
    void SetYear(const int& year);
    void SetMonth(const unsigned short int& month);
    void SetDay(const unsigned short int& day);
    //getters
    int GetYear() const;
    unsigned short int GetMonth() const;
    unsigned short int GetDay() const; 
//=======================================================================
    //operators
    Date & operator =(const Date &other); //перегрузка оператора присвоения
	Date & operator++(); //перегрузка префиксного инкремента
	Date & operator++(int); //перегрузка постфиксного инкремента
	Date & operator --(); //перегрузка префиксного декремнета
	Date & operator--(int); //перегрузка постфиксного декремента 
    int operator-(Date &other); //перегрузка оператора вычитания	
//=======================================================================
	bool operator==(const Date &other) const; //перегрузка оператора равенства	
	bool operator!=(const Date &other) const;  //перегрузка оператора неравенства
	bool operator>(const Date &other) const;  //перегрузка оператора больше
	bool operator<(const Date &other) const;  //перегрузка оператора меньше
	bool operator>=(const Date &other) const;  //перегрузка оператора больше равно
	bool operator<=(const Date &other) const;  //перегрузка оператора меньше равно
//=======================================================================
	friend ostream& operator<<(ostream& os, const Date &item); //перегрузка оператора потокового вывода
	friend istream& operator>>(istream& is, Date &item); //перегрузка оператора потокового вывода
//=======================================================================
};
#endif