//Unique In Order

#include <string>
#include <vector>

template <typename T> std::vector<T> uniqueInOrder(const std::vector<T>& iterable){
  std::vector<T> ans;
  std::vector<T> temp=iterable;
  for(int i=0;i<temp.size()-1;i++)
    {
    if (temp[i] == temp[i + 1])
        {
            temp.erase(temp.begin() + i);
            i--;
        }
    }
    for (auto i : temp)
    {
        ans.push_back(i);
    }

    return ans;
  
}
std::vector<char> uniqueInOrder(const std::string& iterable) {

    std::string temp = iterable;
    std::vector<char> ans;
    if (iterable.size() == 0)return ans;
    for (int i = 0; i < temp.size() - 1; i++)
    {
        if (temp[i] == temp[i + 1])
        {
            temp.erase(temp.begin() + i);
            i--;
        }
    }
    for (auto i : temp)
    {
        ans.push_back(i);
    }

    return ans;
}
