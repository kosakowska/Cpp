//Weight for weight

#include<sstream>
#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include <regex>

using namespace std;

class WeightSort
{
public:
    static std::string orderWeight(const std::string& strng);
};

std::string WeightSort::orderWeight(const std::string& strng)
{
    string name = std::regex_replace(strng, std::regex("^ +| +$|( ) +"), "$1");
    stringstream ss(name + " ");
    string word;
    vector<string> temp;
    vector<pair< int,string >>temp1;
    
    while (getline(ss, word, ' ')) temp.push_back(word);
    int sum{ 0 };
    for (int i = 0; i < temp.size(); i++)
    {
        for (int j = 0; j < temp[i].size(); j++)
        {
           sum+= temp[i][j] - '0';
        }        
      temp1.push_back({ sum,temp[i] });
      sum = 0;
    }
    sort(temp1.begin(), temp1.end());
    string ans="";
    for (int i = 0; i < temp1.size(); i++)
    {
        ans += temp1[i].second;
        ans += " ";
    }
    ans.pop_back();
    
    return ans;
}
