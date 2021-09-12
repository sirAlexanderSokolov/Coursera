#define BOOST_TEST_MAIN

#include <boost/test/included/unit_test.hpp> 

#include "cfp_db_class.h"



/*
«Unknown command: COMMAND»
«Wrong date format: DATE»
*/

/*
Find 0-1-2
event1

Del 0-1-2
Deleted 1 events

Print
0001-02-03 event2

Del 1-2-3 event2
Deleted successfully

Del 1-2-3 event2
Event not found
*/

/*
Add 0-13-32 event1
Month value is invalid: 13
*/

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
BOOST_AUTO_TEST_CASE( test_db_class_print )
{
//cfp_DB DB;

//Add
//Print
//Find
//Del (single / multiple)
}
//---------------------------------------------------
BOOST_AUTO_TEST_CASE( test_db_class_find )
{
//cfp_DB DB;

//Add
//Print
//Find
//Del (single / multiple)
}
//---------------------------------------------------
BOOST_AUTO_TEST_CASE( test_db_class_del )
{
//cfp_DB DB;

//Add
//Print
//Find
//Del (single / multiple)
}
//---------------------------------------------------