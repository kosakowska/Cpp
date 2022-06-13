//Duplicate Encoder

#include <string>
#include<map>
#include <cctype>
std::string duplicate_encoder(const std::string& word){
  std::map <char,int> mapa;
  for(auto i:word) mapa[std::tolower(i)]++;
  
  std::string ans="";
  for(auto i:word) ans+=(mapa[std::tolower(i)]==1)? "(":")";
  return ans;
}
