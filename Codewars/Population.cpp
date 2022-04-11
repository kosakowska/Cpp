//Growth of a Population

class Arge
{
  public:
  static int nbYear(int p0, double percent, int aug, int p);
};
int func(int p0, double percent, int aug, int p)
{
  int peop = p0 + p0 * percent + aug;
  return peop;
}

int Arge::nbYear(int p0,double percent,int aug,int p)
{
  percent = percent / 100;
  int lata = 0;
  
  
  while (p0 < p)
  {
    p0 = func(p0, percent, aug, p);
    lata++;
  }
  return lata;
}
