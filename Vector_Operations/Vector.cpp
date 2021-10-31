// Vector.cpp by Małgorzata Kosakowska
//


#include <iostream>
#include <vector>
#include <random>

using std::cout, std::cin, std::endl, std::vector;
using VD = std::vector<double>;
using VD2 = std::vector<std::vector<double>>;

//Random values
int random(VD a,VD b)
{

    cout << "Wektor a: \n";
    for (auto i : a)
    {
        a[i] = rand();
        cout << a[i];
        cout << endl;
    }
    cout << endl << endl;
    cout << "Wektor b: \n";
    for (auto i : b)
    {
        b[i] = rand();
        cout << b[i];
        cout << endl;
    }

    //cout << "\nSize: " << a.size();
    return 0;
}

//Inner product
int inner_product(VD a, VD b)
{    

    double c = 0.0;
    cout << "Vector a: \n";
    for (int i = 0;i < a.size();i++)
    {
        cout << a[i];
        cout << endl;
    }
    cout << endl << endl;
    cout << "Vector b: \n";
    for (int i = 0;i <b.size();i++)
 
    {
        cout << b[i];
        cout << endl;
    }

    for (int g=0;g<a.size();g++)
    
    {
        c += a[g] * b[g];
    }
    cout << "\n\nSum: " << c;


    cout << "\nSize: " << a.size();
    return 0;
}

//Outer product
int outer_product(VD a, VD b)
{


    cout << "Vector a: \n";
    for (int r = 0; r < a.size();r++)
    {
 
        cout << a[r];
        cout << endl;
    }
    cout << endl << endl;
    cout << "Vector b: \n";
    for(int d = 0; d < b.size();d++)
    {

        cout << b[d];
        cout << endl;
    }

    cout << endl;
    VD2 c(a.size(), VD(b.size(),0));
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < b.size(); j++)
        {
            c[i][j] = a[i] * b[j];
            cout << c[i][j]<<"  ";
            
        }
        cout << endl;
    }



    return 0;
}




int main()
{
    VD a(5, 8);
    VD b(5, 2);
    //random(a,b);
    
    //inner_product(a,b);
    outer_product(a,b);
}

