//Sort the odd

#include<algorithm>
using std::sort;

std::vector<int> sort_odd(std::vector<int> a)
  {
  std::vector<int> b;
  for(int i=0;i<a.size();i++)
    {
    if(a[i]%2!=0)
      {
      b.push_back(a[i]);
    }
  }
  sort(b.begin(),b.end());
  return b;
}


std::vector<int> change_odd(std::vector<int> arr,std::vector<int> odd)
  {
  int l=0;
  for(int i=0;i<arr.size();i++)
    {
    if(arr[i]%2!=0)
      {
      arr[i]=odd[l];
      l++;
    }
  }
  return arr;
}

class Kata
{
public:
    std::vector<int> sortArray(std::vector<int> array)
    {
      std::vector<int> odd;
      odd=sort_odd(array);
      array=change_odd(array,odd);
      
      
        return array;
    }
};
