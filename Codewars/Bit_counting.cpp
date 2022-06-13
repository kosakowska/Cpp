//Bit Counting

#include<string>
#include<bitset>
using std::string;
unsigned int countBits(unsigned long long n){
  int sum=0;
  std::string binary = std::bitset< 64 >( n ).to_string(); 
  for(auto i:binary)
    {
    if(i=='1') sum++;
  }
  return sum;
}
