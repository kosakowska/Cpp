//Roman Numerals Decoder

#include <iostream>
#include <string>
#include<map>

using namespace std;

using std::map, std::cout, std::string;
using mapa = map<char,int>;


int solution(string roman) {
    int licz = 0;
    mapa tab = { {'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};

    for (int i = 0; i < roman.length(); i++)
    {
        if (tab[roman[i]] >= tab[roman[i + 1]]) licz += tab[roman[i]];
        else licz -= tab[roman[i]];

    }
    return licz;
}
