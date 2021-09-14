//=======================================================================
//========coursera final project cfp_database class declaration==========
//=======================================================================

#pragma once

#ifndef CFP_DB_CLS_H
#define CFP_DB_CLS_H

#include <map>
#include <set>
#include <string>
#include <iostream>

#include "cfp_date_class.h"

using namespace std;

class cfp_DB {
protected:
public:
//========================var============================================
map <Date, set <string>> DB; 
//========================constr/d=======================================
cfp_DB();
virtual ~cfp_DB();
//========================method=========================================
void Add(const Date& date, const string& event);
void Print() const;
void Find(const Date& date) const;
void Del(const Date& date);
void Del(const Date& date, const string& event);
};

#endif