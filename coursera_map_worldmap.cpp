#include <iostream>
#include <map>
#include <string>

using namespace std;

map <string,string> world_map;
string command;  
pair <string,string> tmp;

int main ()
{

world_map["Russia"]="MSK";
world_map["USA"]="WASH";
world_map["KZ"]="Astana";

entrance:

command="";
tmp={"", ""};

cout << "============================" <<endl;
cout << "Hi! Please enter the command" <<endl;
cout << "============================" <<endl;

if ((cin.peek()==68)||(cin.peek()==69)||(cin.peek()==10)) getline(cin, command); //kostyl vmesto parsera
else cin >> command >> tmp.first >> tmp.second;

if ((command=="CHANGE_CAPITAL")&&(tmp.first!="")&&(tmp.second!=""))
    {
        if ((world_map.find(tmp.first)!=world_map.end())&&(tmp.second == world_map[tmp.first])) cout << "Country "<< tmp.first <<" hasn't changed its capital" <<  endl; 
        else 
        {
            if (world_map.find(tmp.first)==world_map.end()) cout << "Introduce new country " << tmp.first << " with capital " << tmp.second << endl;
            else cout << "Country " << tmp.first  << " has changed its capital from " << world_map[tmp.first] << " to " <<  tmp.second << endl;
            world_map.emplace(tmp);
        }
    }
else if ((command=="RENAME")&&(tmp.first!="")&&(tmp.second!=""))
    {   
        if (
            (world_map.find(tmp.first)!=world_map.end())&&
            (world_map.find(tmp.second)==world_map.end())&&
            (tmp.first!=tmp.second)
            )
        {   
            auto a=world_map.extract(tmp.first);
            a.key()=tmp.second;
            world_map.insert(move(a));
            cout << tmp.first << " with capital " << world_map[tmp.second] << " has been renamed to " << tmp.second << endl;
        }
        else cout << "Incorrect rename, skip" << endl;
    }
else if ((command=="ABOUT")&&(tmp.first!="")&&(tmp.second!=""))
    {
        if (world_map.find(tmp.first)!=world_map.end()) cout <<"Country " << tmp.first << " has capital " << world_map[tmp.first] << endl;
        else cout << "Country " << tmp.first << " doesn't exist" << endl;
    }
else if (command=="DUMP")
    {
        if (world_map.size()>0) for (auto &i : world_map) cout << i.first << "/" << i.second << endl;
        else cout << "There are no countries in the world" << endl;
        
    }
else if (command=="EXIT")
    {
         return 0;
    }
else cout << "Command is unknown";

goto entrance;

return 0;
}
