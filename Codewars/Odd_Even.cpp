//Odd or Even?

#include <string>
#include <vector>

std::string odd_or_even(const std::vector<int> &arr)
{
  int sum{0};
    for(int i=0;i<arr.size();i++)
      {
      sum+=arr[i];
    }
  if(sum%2==0)return "even";
  else 
    return "odd"; 
}
