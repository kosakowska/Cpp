//Create Phone Number

#include <string>

std::string createPhoneNumber(const int arr [10]){
  std::string num="";
  for(int i=0;i<10;i++)
    {
    num+=std::to_string(arr[i]);
  }
  num.insert(0,"(");
  num.insert(4,") ");
  num.insert(9,"-");
  
  return num;
}
