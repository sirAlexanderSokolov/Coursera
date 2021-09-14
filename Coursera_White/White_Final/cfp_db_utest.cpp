#define BOOST_TEST_MAIN

#include <boost/test/included/unit_test.hpp> 

#include "cfp_db_class.h"

//---------------------------------------------------
BOOST_AUTO_TEST_CASE( test_db_class )
{
Date date1(1990,7,1);
cfp_DB DB1; //default test
DB1.DB[date1].emplace("event1");
cfp_DB DB2(DB1); //copy test
BOOST_CHECK(DB2.DB[date1]==set<string>{"event1"});
}
//---------------------------------------------------
BOOST_AUTO_TEST_CASE( test_db_class_add )
{
cfp_DB DB1;
Date date1(1990,7,1);
Date date2(2021,9,12);

DB1.Add(date1,"event1");
BOOST_CHECK(DB1.DB[date1]==set<string>{"event1"});

DB1.Add(date1,"event2");
BOOST_CHECK(DB1.DB[date1]==(set<string>{"event1","event2"}));

DB1.Add(date2,"event1");
BOOST_CHECK(DB1.DB[date2]==(set<string>{"event1"}));

DB1.Add(date2,"event3");
BOOST_CHECK((DB1.DB[date2]==(set<string>{"event1","event3"}))&&(DB1.DB[date1]==(set<string>{"event1","event2"})));
}
//---------------------------------------------------