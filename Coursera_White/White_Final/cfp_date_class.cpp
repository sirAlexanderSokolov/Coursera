//=======================================================================
//==========coursera final project cfp_date class definition=============
//=======================================================================

#include "cfp_date_class.h"

//=======================================================================

Date::Date()
{
y=1990;
m=7;
d=1;
}
//-----------------------------------------------------------------------
Date::Date(int year,unsigned short int month,unsigned short int day):Date()
{
y=year;
m=month;
d=day;
}
//-----------------------------------------------------------------------
Date::Date(const Date &other) //конструктор копирования
{
this->operator()(other.GetYear(),other.GetMonth(),other.GetDay());
}
//-----------------------------------------------------------------------
Date::~Date()
{
}
//-----------------------------------------------------------------------

//=======================================================================
//=============================functions=================================
//=======================================================================

string Date::DateToStr() const
{
ostringstream ss;
ss << setfill('0') << setw(4) << y << setw(1) << "-" << setw(2) << m << setw(1) << "-" << setw(2) << d;
return ss.str();
}
//-----------------------------------------------------------------------
int Date::Date_To_Days () const
{
short int tmp;
this->y<=0 ? tmp=-1 : tmp=1;
return (365 * this->y)+((accumulate(days_in_month.begin(),days_in_month.begin()+this->m-1,0) + this->d) * tmp);
}
//-----------------------------------------------------------------------
void Date::Days_To_Date(const int& total_days)
{
this->y = total_days/365;
int dd = total_days - (this->y * 365);

short int tmp;
this->y<0 ? tmp=-1 : tmp=1;
dd*=tmp;
for (this->m=0; dd>0; this->m++) dd -= days_in_month[this->m];
this->d=dd+days_in_month[this->m-1];
}
//-----------------------------------------------------------------------

//=======================================================================
//=============================setters===================================
//=======================================================================

void Date::operator()(const int& year, const unsigned short int& month, const unsigned short int& day)
{
this->y=year;
this->m=month;
this->d=day;
}
//-----------------------------------------------------------------------
void Date::SetYear(const int& year)
{
this->y=year;
}
//-----------------------------------------------------------------------
void Date::SetMonth(const unsigned short int& month)
{
this->m=month;
}
//-----------------------------------------------------------------------
void Date::SetDay(const unsigned short int& day)
{
this->d=day;
}
//-----------------------------------------------------------------------

//=======================================================================
//=============================getters===================================
//=======================================================================

unsigned short int Date::GetDay() const
{
return this->d;
}
//-----------------------------------------------------------------------
unsigned short int Date::GetMonth() const
{
return this->m;
}
//-----------------------------------------------------------------------
int Date::GetYear() const
{
return this->y;
}
//-----------------------------------------------------------------------

//=======================================================================
//=============================operators=================================
//=======================================================================

Date & Date::operator =(const Date &other) //перегрузка оператора присвоения
{
this->y=other.y;
this->m=other.m;
this->d=other.d;
return *this;
}
//-----------------------------------------------------------------------
Date & Date::operator++() //перегрузка префиксного инкремента
{
this->Days_To_Date(this->Date_To_Days()+1);
return *this;
}
//-----------------------------------------------------------------------
Date & Date::operator++(int) //перегрузка постфиксного инкремента 
{
Date tmp(*this);
this->Days_To_Date(this->Date_To_Days()+1);
return tmp;
}
//-----------------------------------------------------------------------
Date & Date::operator --() //перегрузка префиксного декремнета
{
this->Days_To_Date(this->Date_To_Days()-1);
return *this;
}
//-----------------------------------------------------------------------
Date & Date::operator--(int) //перегрузка постфиксного декремента 
{
Date tmp(*this);
this->Days_To_Date(this->Date_To_Days()-1);
return tmp;
}
//-----------------------------------------------------------------------
int Date::operator-(Date &other) //перегрузка оператора вычитания
{ 
return this->Date_To_Days() - other.Date_To_Days();
}
//-----------------------------------------------------------------------
bool Date::operator==(const Date &other) const//перегрузка оператора равенства
{
return (this->Date_To_Days() == other.Date_To_Days()); 
}	
//-----------------------------------------------------------------------
bool Date::operator!=(const Date &other) const //перегрузка оператора неравенства
{
return !(this->Date_To_Days() == other.Date_To_Days());
}
//-----------------------------------------------------------------------
bool Date::operator>(const Date &other)  const//перегрузка оператора больше
{
return (this->Date_To_Days() > other.Date_To_Days()); 
}
//-----------------------------------------------------------------------
bool Date::operator<(const Date &other) const //перегрузка оператора меньше
{
return (this->Date_To_Days() < other.Date_To_Days());  
}
//-----------------------------------------------------------------------
bool Date::operator>=(const Date &other) const //перегрузка оператора больше равно
{
return (this->Date_To_Days() >= other.Date_To_Days());
}
//-----------------------------------------------------------------------
bool Date::operator<=(const Date &other) const //перегрузка оператора меньше равно
{
return (this->Date_To_Days() <= other.Date_To_Days());
}
//-----------------------------------------------------------------------
ostream& operator<<(ostream& os, const Date &item) //перегрузка оператора потокового вывода
{ 
os << setfill('0') << setw(4) << item.y << setw(1) << "-" << setw(2) << item.m << setw(1) << "-" << setw(2) << item.d;
return os;
}
//-----------------------------------------------------------------------
istream& operator>>(istream& is, Date &item) //перегрузка оператора потокового вывода
{ 
int yy, mm, dd;
char ch1, ch2;
is >> yy >> ch1 >> mm >> ch2 >> dd;

if (!is) return is;

if (ch1 != '-' || ch2 != '-')
{
is.clear (ios_base::failbit); // Ошибка формата
return is ;
}

item = Date(yy,mm,dd); 
return is ;
}
//-----------------------------------------------------------------------*/

