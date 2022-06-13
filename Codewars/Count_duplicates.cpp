//Counting Duplicates

#include<string>
#include<map>
#include <cctype>
#include <algorithm>
using namespace std;

size_t duplicateCount(const char* in)
{
    map<char,int> temp1;
  for(int i=0;in[i]!=0;i++)
    {
    temp1[std::tolower(in[i])]++;
  }
    size_t ans{0};
  for(auto i:temp1)
    {
    if(i.second>1) ans++;
  }
  return ans;
}
