//=======================================================================

//=======================================================================

#include "cfp_date_functions.h"

//-----------------------------------------------------------------
//======= is day value correct ====================================

bool cfp_CheckDay(const int& day)
{
    if ((day>0)&&(day<32)) return true;
    else
    {
    cout<<"Day value is invalid: "<<to_string(day)<<'\n';
    return false;
    }
}
//-----------------------------------------------------------------
//======= is month value correct ==================================

bool cfp_CheckMonth(const int &month)
{
    if ((month>0)&&(month<13)) return true;
    else
    {
    cout<<"Month value is invalid: "<<to_string(month)<<'\n';
    return false;    
    } 
}
//-----------------------------------------------------------------
//======= string to date function =================================
//======= date => cfp_classes =====================================

bool cfp_Parse_Date(const string date_str, Date& date)
{
if  (
    (!date_str.empty())
    && ((count(date_str.begin(),date_str.end(),'-')==2)||(count(date_str.begin(),date_str.end(),'-')==3)) //year can be negative value
    && (date_str.find_first_not_of("1234567890-+")==string::npos) //string can contain only numers
    )
{
//parser
string day_str,month_str,year_str; //substrings
stringstream ss1; 
ss1<<date_str<<'\n';
try
{ 
    if (date_str[0]=='-') ss1.ignore(1); //negative value of year
    getline(ss1 >> ws ,year_str,'-');
    getline(ss1 >> ws ,month_str,'-');
    getline(ss1 >> ws ,day_str,'\n');
    //is values correct
    if  (
        (year_str.empty()) ||
        (month_str.empty()) || 
        (day_str.empty()) || 
        (!cfp_CheckDay(stoi(day_str))) || 
        (!cfp_CheckMonth(stoi(month_str)))
        ) goto error1; //Wrong date format

    date(stoi(year_str),stoi(month_str),stoi(day_str));
    return true;
    }
catch (exception &ex)
    {
    goto error1; //Wrong date format
    }
}
else 
{
error1:
cout<<"Wrong date format: " << date_str <<'\n'; 
return false;
}
}
//-----------------------------------------------------------------

