//Isograms

#include <algorithm>
#include<cctype>
using namespace std;
bool is_isogram(std::string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    for (int i = 0; i < str.length(); i++)
    {
        auto it = str.find(str[i], i + 1);
        if (it != std::string::npos) return false;
    }
    return true;
}
