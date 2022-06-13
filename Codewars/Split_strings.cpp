//Split Strings

#include <string>
#include <vector>

std::vector<std::string> solution(const std::string& s)
{
    std::string temp = s;
    std::vector<std::string> ans;
    for (int i = 0; i < temp.length() ; i++)
    {
      std::string tem="";
      if(i==temp.length()-1)tem+=temp[i];
      else
        tem=tem+temp[i]+temp[i+1];
      ans.push_back(tem);
      i++;
    }

    if (s.length() % 2 == 0) return ans;
    else
    {
        ans.back() += '_';
        return ans;
    }
}
