//Find the stray number

int stray(std::vector<int> numbers) {
  for(auto i:numbers)
    {
    int mycount = std::count (numbers.begin(),numbers.end(), i);
    if(mycount==1)return i;
  }
  
};
