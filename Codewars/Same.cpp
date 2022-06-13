//Are they the "same"?

#include <vector>

class Same {
public:
    public:
    static bool comp(std::vector<int>& a, std::vector<int>& b) {

        for (int i = 0; i < a.size(); i++)
        {        
            a[i]=(a[i]*a[i]);
        }
      std::sort(a.begin(),a.end());
      std::sort(b.begin(),b.end());
      return a==b;
       }

};
