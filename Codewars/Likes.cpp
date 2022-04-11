//Who likes it?

std::string likes(const std::vector<std::string> &names)
{
  std::string temp;
  int num=names.size();
  switch(num){
      case 0:
      return "no one likes this";
      case 1:
      {
        temp=names[0];
        temp+=" likes this";
        break;
      }
      case 2:
      {
        temp=names[0] +" and "+ names[1]+" like this";
        break;
      }
      case 3:
      {
        temp=names[0] +", "+ names[1]+ " and " + names[2] + " like this";
        break;
      }
      default:
      {
        temp=names[0]+", "+names[1]+" and "+ std::to_string(num-2) +" others like this" ;
        break;
      }
      
  }
  
return temp;
}
