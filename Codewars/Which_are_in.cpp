//Which are in?

#include<string>
#include <vector>
#include <algorithm>
class WhichAreIn
{

public:
    static std::vector<std::string> inArray(std::vector<std::string>& array1, std::vector<std::string>& array2);
};
std::vector<std::string> WhichAreIn::inArray(std::vector<std::string>& array1, std::vector<std::string>& array2)
{
    int licz{ 0 };
    std::vector<std::string> res;
    std::sort(array1.begin(), array1.end());
    std::sort(array2.begin(), array2.end());
    for (int i = 0; i < array1.size(); i++)
    {
        for (int j = 0; j < array2.size(); j++)
        {
            auto found = array2[j].find(array1[i]);
            if (found != std::string::npos)
            {
                res.push_back(array1[i]);
                break;
            }
        }
        
    }
    return res;
}
