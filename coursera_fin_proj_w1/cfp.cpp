//=======================================================================
//=================coursera final project definitions====================
//=======================================================================
#include "cfp.h"
#include <sstream>
//-----------------------------------------------------------------------
int main () 
{
Date date; //tmp vars
string command, sdate, event, tmp, line; //tmp vars
stringstream iss; //tmp vars

programm_start:

cout<<"============================\nGreetings! Enter the command\n============================\n";
getline(cin, line);
iss<<line;

//parse input
while (iss >> tmp) 
{    
if (command.empty()) command = tmp;
else if (sdate.empty()) sdate = tmp;
else if (event.empty()) event+=tmp;
else event=event+" "+tmp;
}

//use command
if (command == "Print") DB.Print();
else if (command == "Exit") exit(0);
else if (command == "Help") cout<<"PROPER COMMANDS:\nAdd yyyy-mm-dd event\nDel yyyy-mm-dd event\nDel yyyy-mm--dd\nFind yyyy-mm-dd\nPrint\nExit\n";
else if (command == "Add") {if ( (cfp_Parse_Date(sdate, date)) && (!event.empty()) ) DB.Add(date, event);}
else if (command == "Find") {if ( (cfp_Parse_Date(sdate, date)) )  DB.Find(date);}
else if (command == "Del") 
{
    if(cfp_Parse_Date(sdate, date)) 
    {  
    if (!event.empty()) DB.Del(date, event);
    else DB.Del(date);
    }
}
else cout<<"Unknown command: "<<command<<'\n'<<'\n';

//clear vars
command.clear();
command.shrink_to_fit();
sdate.clear();
sdate.shrink_to_fit();
event.clear();
event.shrink_to_fit();
line.clear();
tmp.clear();

iss.clear();

//go to start : line 13
goto programm_start;
return 0;
}
//-----------------------------------------------------------------------




