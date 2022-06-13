//Delete occurrences of an element if it occurs more than n times

std::vector<int> deleteNth(std::vector<int> arr, int n)
{
  std::vector<int> ans;
  for(auto i:arr)
    {
    if(count(ans.begin(),ans.end(),i)<n) ans.push_back(i);
  }
  return ans;
}
