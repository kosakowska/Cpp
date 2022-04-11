//Get the Middle Character

using std::string;

std::string get_middle(std::string input) 
{
  int len=input.size()/2;
  if(input.length()==1) return input; 
  int head=0;
  int tail=input.size()-1;
  string a="";
  for(int i=0;i<len;i++)
    {
    head++;
    tail--;
    
    if(head==tail) 
      {
      a+=input[head];
      return a;
      }
    if(head+1==tail) 
      {
      a+=input[head];
      a+=input[tail];
      return a;
     }
    }
  return a;
}
