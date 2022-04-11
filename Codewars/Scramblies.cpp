//Scramblies

#include<string>
bool scramble(const std::string& s1, const std::string& s2) {
    int licz{ 0 };
    std::string a=s1;
    
    for (int i = 0; i < s2.size(); i++)
    {
        auto found = a.find(s2[i]);
        if (found != std::string::npos)
        {
            a[found]='-';
            licz++;
        }
    }
    if (licz == s2.size()) return true;
    else return false;
}
