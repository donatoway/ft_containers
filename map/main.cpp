#include <iostream>
#include <map>


using namespace std;

int main()
{
    map<string, string> uomo;
   

    uomo.insert(pair<string, string>("angelo", "cuoco"));
    uomo.insert(pair<string, string>("angeloo", "fabbro"));
    uomo.insert(pair<string, string>("bino", "meccanico"));

    map<string, string>::iterator itr;

    for (itr = uomo.begin() ;itr != uomo.end();itr++)
    {
       cout << itr->first << "-" << itr->second <<  endl;
    }
    //continuare a vedere tree (gli alberi lezioni su youtube), documentazione ecc...
    
}