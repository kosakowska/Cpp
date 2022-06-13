#include <vector>
#include <string>
#include<sstream>

using namespace std;
std::vector<std::string> string_to_array(const std::string& s) {
    stringstream ss(s+" ");
    string word;
    vector<string> a;
    while(getline(ss,word,' ')) a.push_back(word);
    return a;
}
