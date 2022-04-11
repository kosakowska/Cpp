//Binary Addition

#include <cstdint>
#include <string>
#include<vector>

using std::string;

string add_binary(uint64_t a, uint64_t b) {
    uint64_t n = a + b;
    std::vector<uint64_t> j;
    string g = "";
    if(n==0)
    {
      j.push_back(0);
      g = std::to_string(j[0]);
      return g;
    }
    for (int i = 0; n > 0; i++)
    {
        j.insert(j.begin(), n % 2);
        n = n / 2;
    }
    
    for (int i = 0; i < j.size(); i++)
    {
        g = g + std::to_string(j[i]);
    }

    return g;
}
