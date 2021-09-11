#include <iostream>
#include <string>
#include "cfp.h"
#include <numeric>
#include <array>
#include <sstream>
#include <iomanip>

//#include "cfp_date_functions.h"
//#include "cfp_date_class.h"
//setlocale(LC_ALL, "C.UTF-8");
// yyyy-mm-dd
using namespace std;
int y = 1990;
unsigned short int m = 7;
unsigned short int d = 22;
array <unsigned short int, 12> days_in_month = {31,28,31,30,31,30,31,31,30,31,30,31};
string a1, a2, a3;
int main () 
{
short int tmp;
y<=0 ? tmp=-1 : tmp=1;

int total_days = (365 * y)+((accumulate(days_in_month.begin(),days_in_month.begin()+m-1,0) + d) * tmp);
cout<<to_string(total_days)<<'\n';

int yy,mm,dd;
yy = total_days/365;
yy<0 ? tmp=-1 : tmp=1;
dd = total_days - (yy * 365);
dd*=tmp;
for (mm=0; dd>0; mm++) dd -= days_in_month[mm];
dd+=days_in_month[mm-1];


ostringstream ss;
ss << setfill('0') << setw(4) << y << setw(1) << "-" << setw(2) << m << setw(1) << "-" << setw(2) << d;

cout << ss.str();

//cin >> a1 >> a2 >> a3;
//Date d(1,1,1);

//if (cfp_Parse_Date(a2,d)) cout << "ok";
//else cout << "no";


return 0;
}





