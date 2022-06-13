//Digital Root

int digital_root(int n)
{
  std::string ans=std::to_string(n);
   int digitsSum = 0;
   for (int i = 0; i < ans.length(); i++) {
      digitsSum += ans[i] - '0';
   }
   if (digitsSum == 0) {
      return 0;
   }
   return digitsSum % 9 == 0 ? 9 : digitsSum % 9;
}
