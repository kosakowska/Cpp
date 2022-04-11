//Count characters in your string

#include <map>
#include <string>
using namespace std;

map<char, unsigned> count(const string& string) {
    map<char, unsigned> tab;
    if (string.empty()) return {};

    for (int i = 0; i < string.size(); i++)
    {

        map<char, unsigned>::iterator it = tab.find(string[i]);

        if (tab.find(string[i]) != tab.end()) it->second++;

        else tab.insert({ string[i], 1 });

    }
    return tab;

}
