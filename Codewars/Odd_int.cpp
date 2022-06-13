//Find the odd int

#include <iostream>
#include <vector>
#include<map>
using std::vector, std::map, std::find;
int findOdd(const std::vector<int>& numbers) {
    map<int, int> temp;
    for (int i = 0; i < numbers.size(); i++)
    {
        auto idx = temp.find(numbers[i]);
        if (idx != temp.end()) idx->second++;
        else
            temp.insert({ numbers[i],1 });
    }
    for (auto i : temp)
    {
        if (i.second % 2 != 0)return i.first;
    }
}
