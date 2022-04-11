//Convert a string to an array
#include <vector>
#include <string>
#include <sstream>

using namespace std;
vector<string> string_to_array(const string& s) {
    stringstream ss(s+" ");
    string word;
    vector<string> a;
    while(getline(ss,word,' ')) a.push_back(word);
    return a;
}
