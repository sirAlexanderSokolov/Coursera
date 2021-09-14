#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

bool IsAna (pair<string,string> tmp_pair)
{
map <char, int> tmp_m1, tmp_m2;
if (tmp_pair.first.size()==tmp_pair.second.size())
{
    for (const auto& a:tmp_pair.first) ++tmp_m1[a];
    for (const auto& a:tmp_pair.second) ++tmp_m2[a];

    if  (tmp_m1==tmp_m2) return true;
}
return 0;
}


int main ()
{
    vector <pair <string,string>> words {{"eat", "tea"},{"find", "search"},{"master","stream"}};
    for (const auto& a:words)
    {
        cout << IsAna(a) << endl;
    }

return 0;
}
