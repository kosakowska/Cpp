//Sum of numbers
int get_sum(int a, int b)
{
  
  if(a==b)return a;
  int sum{0};
  if(a>b)
    {
    for(int i=b;i<=a;i++)
      {
      sum+=i;
    }
  }
  else
  {
    for(int i=a;i<=b;i++)
      {
      sum+=i;
    }
  }
  return sum;
}
