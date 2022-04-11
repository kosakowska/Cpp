//Find The Parity Outlier

int find_odd(std::vector<int> arr)
  {
  for(int i=0;i<arr.size();i++)
    {
    if(arr[i]%2!=0) return arr[i];
  }
}

int find_even(std::vector<int>arr)
  {
    for(int i=0;i<arr.size();i++)
    {
    if(arr[i]%2==0) return arr[i];
  }
}
int FindOutlier(std::vector<int> arr)
{
  int licz{0};
  for(int i=0;i<arr.size();i++)
    {
    if(arr[i]%2==0) licz++;
  }
    if(licz>1)return find_odd(arr);
    
    else return find_even(arr);
}
