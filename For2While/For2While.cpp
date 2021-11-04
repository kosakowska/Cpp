// For2While.cpp by Małgorzata Kosakowska
//

#include <iostream>
#include <vector>
#include <iomanip>


using std::cout, std::cin, std::endl, std::vector;

using VD = vector<double>;
using MAT = vector<VD>;

auto Func1(MAT a)
{
    double sum{};
    for (int i = 0; i < a.size(); ++i)
    {
        for (int j = 0; j < a[0].size(); ++j)
        {
            if (i != j)
            {
                sum += a[i][j];
            }
        }
    }
    return sum;
}


auto Func2(MAT a)
{
    double sum{};
    int i = 0;
    
    while (i < a.size())
    {
        int j = 0;
        while (j < a[0].size())
        {   
            if (i != j)
            {
                sum += a[i][j];
            }
            
            j++;
        }
        i++;

    }
    return sum;
}



int main()
{
    MAT a(3, VD(3, 0));
    a = { {1,2,3},
        {3,4,1},
        {5,2,8}};

    double b = Func1(a);
    double c = Func2(a);

    cout << "Func1:" << b;
    cout << "\n\nFunct2:" << c;

}

