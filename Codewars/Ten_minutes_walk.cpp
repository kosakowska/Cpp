//Take a Ten Minutes Walk
#include<vector>

bool isValidWalk(std::vector<char> walk) {
  int poz_x{0}, poz_y{0};
  if(walk.size()!=10)return false;
  
  for(auto i :walk)
    {
      if(i=='n') poz_y++;
      else if(i=='s') poz_y--;
      else if(i=='e') poz_x++;
      else if(i=='w') poz_x--;
    }
  if (poz_x==0 &&poz_y==0) return true;
  else return false;
}
