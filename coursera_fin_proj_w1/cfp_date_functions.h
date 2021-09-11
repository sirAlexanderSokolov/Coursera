#pragma once
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
#include "cfp_date_class.h"

using namespace std;

bool cfp_CheckDay(const int& day);
bool cfp_CheckMonth(const int &month);
bool cfp_Parse_Date(const string date_str, Date& date);