//=======================================================================
//========coursera final project cfp_database class definition==========
//=======================================================================

#include "cfp_db_class.h"

//========================constr/d=======================================
cfp_DB::cfp_DB()
{}
//-----------------------------------------------------------------------
cfp_DB::~cfp_DB()
{}
//========================method=========================================
void cfp_DB::Add(const Date& date, const string& event)
{
DB[date].emplace(event);
}
//-----------------------------------------------------------------------
void cfp_DB::Print() const
{
for (auto i:DB) 
    {
    for (auto ii:i.second) cout<<i.first.DateToStr()<<" "<<ii<<'\n';
    }
}
//-----------------------------------------------------------------------
void cfp_DB::Find(const Date& date) const
{
auto it = DB.find(date);
if (it!=DB.end()) for (auto i : it->second) cout << i << '\n';
else cout<<"No entries found\n";
}
//-----------------------------------------------------------------------
void cfp_DB::Del(const Date& date)
{
auto it = DB.find(date);
if (it!=DB.end()) 
    {
    int tmp=it->second.size();
    it->second.clear();
    cout<< "Deleted " <<tmp<<" events\n";
    }
else cout<<"No entries found\n";
}
//-----------------------------------------------------------------------
void cfp_DB::Del(const Date& date, const string& event)
{
auto it1 = DB.find(date);
if (it1!=DB.end())
{
auto it2 = it1->second.find(event);
if (it2!=it1->second.end()) 
    {
    it1->second.erase(event);
    cout<<"Deleted successfully\n";
    }
else cout<<"Event not found\n";
}
else cout<<"No entries found\n";
}



