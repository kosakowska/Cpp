//Multiples of 3 or 5

int solution(int number) 
{
  if(number<0)return 0;
  int ans{0};
  for(int i=0;i<number;i++)
    {
    if(i%3==0||i%5==0) ans+=i;
  }
  return ans;
}
