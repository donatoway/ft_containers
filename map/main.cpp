#include <iostream>
#include <map>


using namespace std;

int main()
{
    map<string, string> uomo;
   

   uomo.insert(pair<string, string>("carlone", "cuoco"));

    map<string, string>::iterator itr;

    uomo["carletto"];
    for (itr = uomo.begin() ;itr != uomo.end();itr++)
    {
       cout << itr->first << "-" << itr->second <<  endl;
    }
    
}