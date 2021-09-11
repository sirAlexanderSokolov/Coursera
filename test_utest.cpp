#define BOOST_TEST_MODULE My Test 
#include <boost/test/included/unit_test.hpp> 
#include<string>
/*
BOOST_AUTO_TEST_CASE(first_test) 
{
  int i = 1;
  BOOST_TEST(i); 
  BOOST_TEST(i == 2); 
}

/*#define BOOST_TEST_MODULE MyTest
#define BOOST_TEST_DYN_LIN
#include <boost/test/unit_test.hpp>
*/
int add( int i, int j ) { return i+j; }
/**/
BOOST_AUTO_TEST_CASE( my_test )
{
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
}/**/