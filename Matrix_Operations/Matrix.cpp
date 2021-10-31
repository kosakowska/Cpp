// Matrix.cpp by Małgorzata Kosakowska
//

#include <iostream>
#include <vector>
#include <iomanip>

using std::cout, std::cin, std::endl, std::vector,std::setw;
using VD = vector<double>;
using MAT = vector<VD>;

//Creating Matrix
auto Create(int rows, int cols)
{
    MAT a(rows, VD(cols, 0));
    return a;
}

//Printing Matrix
auto Print(MAT a)
{
    for (int i = 0;i < a.size();++i)
    {
        for (int j = 0;j < a[0].size();++j)
        {
            cout << setw(6) <<a[i][j];
        }
        cout << endl;
    }
    return 0;
}

//Addition of diagonal elements
auto Diag(MAT a)
{
    double c{};
    for (int i = 0;i < a.size();++i)
    {
        for (int j = 0;j < a.size();++j)
        {
            if (i == j)
            {
                c += a[i][j];
            }
        }
    }
    
    return c;
}

//Addition of nondiagonal elements
auto Non_Diag(MAT a)
{
    double c{};
    for (int i = 0;i < a.size();++i)
    {
        for (int j = 0;j < a.size();++j)
        {
            if (i != j)
                c += a[i][j];
        }
    }
    return c;
}

//Addition of two Matrices
MAT Add(MAT a, MAT b)
{
    if ((a.size() != b.size()) || (a[0].size() != b[0].size()))
    {
        cout << "Wrong size of matrix" << endl;
        return { {0} };
    }
    MAT c = Create(a.size(), a[0].size());
    for (int i = 0;i < a.size();++i)
    {
        for (int j = 0;j < a.size();++j)
        {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
    return c;
}

//Multiplation of two Matrices
MAT Mult(MAT a, MAT b)
{
    if (a[0].size() != b.size())
    {
        cout << "Wrong size of matrix" << endl;
        return { {0} };
    }
    MAT c = Create(a.size(), b[0].size());
    for (int i = 0;i < a.size();++i)
    {
        for (int j = 0;j < b[0].size();++j)
        {
            for (int k = 0;k < a[0].size();++k)
            {
                c[i][j] += a[i][k] * b[j][k];
            }
        }
    }
    return c;


}


int main()
{
    //Print(Create(4, 8));
    MAT a;
    a = { {1,2,3,1},
        {3,2,5,7},
        {9,7,5,3},
        {4,3,7,6} };
    MAT b;
    b = { {2,3,2,1},
        {5,4,2,4},
        {5,3,21,8},
        {5,43,87,54} };
    //Print(Add(a, b));
    Print(Mult(a, b));
    //MAT b(4, VD(4, 7));
    //cout<< Diag(a);
    //cout << Non_Diag(a);
}


