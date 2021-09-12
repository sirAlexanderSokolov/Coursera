#define BOOST_TEST_MAIN

#include <boost/test/included/unit_test.hpp> 

#include "cfp_date_functions.h"
#include "cfp_date_class.h"

//---------------------------------------------------
BOOST_AUTO_TEST_CASE( test_date_class )
{
Date date1;
Date date2(1990,07,1);

BOOST_CHECK_EQUAL(date1, date2);

BOOST_CHECK(date2.GetDay() == 1);
BOOST_CHECK(date2.GetMonth() == 7);
BOOST_CHECK(date2.GetYear() == 1990);

BOOST_CHECK(date2.DateToStr() == "1990-07-01");
BOOST_CHECK(date2.Date_To_Days() == 726532); //1990*365 + 31+28+31+30+31+30 + 1

BOOST_CHECK_NO_THROW(date2.Days_To_Date(726533));
date2.Days_To_Date(726533);
BOOST_CHECK_MESSAGE(date2.DateToStr() == "1990-07-02", "Days_To_Date function failure, result: "<<date2.DateToStr());

BOOST_CHECK_NO_THROW(date2(1,2,3));
date2(1,2,3);
BOOST_CHECK_MESSAGE(date2.DateToStr() == "0001-02-03", "Date.operator() failure, result: "<<date2.DateToStr());

date1.SetYear(3);
date1.SetMonth(4);
date1.SetDay(1);
BOOST_CHECK_MESSAGE(date1.DateToStr() == "0003-04-01", "Setter failure, result: "<<date1.DateToStr());

BOOST_CHECK((date1!=date2) == true);
BOOST_CHECK((date1==date2) == false);
BOOST_CHECK((date1>date2) == true);
BOOST_CHECK((date1>=date2) == true);
BOOST_CHECK((date1<date2) == false);
BOOST_CHECK((date1<=date2) == false);

BOOST_CHECK_GE( date1, date2 ); //d1>d2
BOOST_CHECK_GT( date1, date2 ); //d1>=d2
BOOST_CHECK_LE( date2, date1 ); //d2<d1
BOOST_CHECK_LT( date2, date1 ); //d2<=d1

date2++;
BOOST_CHECK_MESSAGE(date2.DateToStr() == "0001-02-04", "Date.operator++ failure, result: "<<date2.DateToStr());
++date2;
BOOST_CHECK_MESSAGE(date2.DateToStr() == "0001-02-05", "Date.operator++() failure, result: "<<date2.DateToStr());
date2--;
BOOST_CHECK_MESSAGE(date2.DateToStr() == "0001-02-04", "Date.operator-- failure, result: "<<date2.DateToStr());
--date2;
BOOST_CHECK_MESSAGE(date2.DateToStr() == "0001-02-03", "Date.operator--() failure, result: "<<date2.DateToStr());

BOOST_CHECK_MESSAGE((date1 - date2) == 787, "result (date1 - date2): "<< date1.Date_To_Days() << " - " << date2.Date_To_Days() <<"=" << (date1 - date2));
}
//---------------------------------------------------
BOOST_AUTO_TEST_CASE( test_check_day )
{
BOOST_CHECK(cfp_CheckDay(1) == true);
BOOST_CHECK(cfp_CheckDay(31) == true);
BOOST_CHECK(cfp_CheckDay(0) == false);
BOOST_CHECK(cfp_CheckDay(-1) == false);
BOOST_CHECK(cfp_CheckDay(32) == false);
}
//---------------------------------------------------
BOOST_AUTO_TEST_CASE( test_check_month )
{
BOOST_CHECK(cfp_CheckMonth(1) == true);
BOOST_CHECK(cfp_CheckMonth(12) == true);
BOOST_CHECK(cfp_CheckMonth(0) == false);
BOOST_CHECK(cfp_CheckMonth(-1) == false);
BOOST_CHECK(cfp_CheckMonth(13) == false);
}
//---------------------------------------------------
BOOST_AUTO_TEST_CASE( test_parse_date )
{
Date date1(1,1,1);
BOOST_CHECK(cfp_Parse_Date("1-1-1", date1) == true);
BOOST_CHECK(cfp_Parse_Date("-1-1-1", date1) == true);
BOOST_CHECK(cfp_Parse_Date("1--1-1", date1) == false);
BOOST_CHECK(cfp_Parse_Date("1---1-1", date1) == false);
BOOST_CHECK(cfp_Parse_Date("1-+1-+1", date1) == true);
BOOST_CHECK(cfp_Parse_Date("0-1-1", date1) == true);
BOOST_CHECK(cfp_Parse_Date("0-1-0", date1) == false);
BOOST_CHECK(cfp_Parse_Date("0-0-1", date1) == false);
BOOST_CHECK(cfp_Parse_Date("2000-12-31", date1) == true);
BOOST_CHECK(cfp_Parse_Date("2000-13-31", date1) == false);
BOOST_CHECK(cfp_Parse_Date("1000-1-111", date1) == false);
BOOST_CHECK(cfp_Parse_Date("00001-21-51", date1) == false);
}
//---------------------------------------------------
  /*
  // seven ways to detect and report the same error:
  BOOST_CHECK( add( 2,3 ) == 4 ); // #1 continues on error
 // В этом варианте используется BOOST_CHECK, который показывает сообщение об ошибке (по умолчанию он его выводит в std::cout), которое включает в себя выражение, не прошедшее проверку, имя файла с исходниками, и строку в нём. А также он увеличивает счётчик ошибок. При завершении программы счётчик ошибок будет автоматически показан средствами Unit Test Framework.
  BOOST_REQUIRE( add( 2,2 ) == 4 );// #2 throws on error
  //Этот вариант использует BOOST_REQUIRE, средство, во всём подобное #1, за исключением того, что после вывода сообщения об ошибке генерируется исключение, отлавливаемое затем Unit Test Framework. Это используется тогда, когда возникшая ошибка настолько серьёзна, что делает дальнейшее выполнение программы бессмысленным. BOOST_REQUIRE отличается от макроса assert() стандартной библиотеки тем, что перенаправляет обнаруженную ошибку в унифицированную процедуру генерации отчётов из Unit Test Framework.
  if( add( 2,2 ) != 4 )
  BOOST_ERROR("Ouch..." ); // #3 continues on error
  //Вариант использования, похожий на #1, за исключением того, что обнаружение ошибки и сообщение об этом кодируются по отдельности. Это может быть полезно при сложном условном операторе с несколькими условиями, о провале каждого из которых можно сообщить отдельно.
  if( add( 2,2 ) != 4 )
  BOOST_FAIL( "Ouch..." );  // #4 throws on error
  //Вариант использования, похожий на #2, за исключением того, что обнаружение ошибки и сообщение об этом кодируются по отдельности. Это может быть полезно при сложном условном операторе с несколькими условиями, о провале каждого из которых можно сообщить отдельно.
  if( add( 2,3 ) != 4 ) throw "Ouch...";// #5 throws 
  //Этот вариант бросает исключение, отлавливаемое затем Unit Test Framework. Показываемое сообщение об ошибке будет более информативным, если исключение было унаследовано от std::exception, или является char* или std::string.
  // on error 
  BOOST_CHECK_MESSAGE( add( 2,3 ) == 4, // #6 continues
  //Этот вариант использует средство BOOST_CHECK_MESSAGE, похожее на #1, за исключением того, что подобно варианту #3 показывает альтернативное сообщение об ошибке, описанное во втором аргументе.
    // on error
  "add(..) result: " << add( 2,3 ) );
  BOOST_CHECK_EQUAL( add( 2,3 ), 4 ); // #7 continues
  //Этот вариант использует средство BOOST_CHECK_EQUAL, похожее на #1. Лучше всего это подходит для проверки на равенство двух переменных, так как в случае несовпадения показывает оба значения.
  // on error
  }*/
