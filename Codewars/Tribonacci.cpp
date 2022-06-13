//Tribonacci Sequence

std::vector<int> tribonacci(std::vector<int> signature, int n)
{
    if(n<3) signature.resize(n);
  
    for(int i=3;i<n;i++)
      {
      signature.push_back((signature[i-3]+signature[i-2]+signature[i-1]));
    }
    return signature;
}
