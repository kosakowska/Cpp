//Complementary DNA

#include <string>

std::string DNAStrand(const std::string& dna)
{
  std::string h="";
  for(int i=0;i<dna.size();i++)
    {
    if(dna[i]=='A') h+='T';
    if(dna[i]=='T') h+='A';
    if(dna[i]=='C') h+='G';
    if(dna[i]=='G') h+='C';
  }
  return h;
}
