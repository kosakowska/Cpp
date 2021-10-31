// Sqrt_Approx.cpp by Małgorzata Kosakowska
//

#include <iostream>
#include <cmath>
using std::cout, std::cin, std::endl;

int main()
{
    int x;
    cout << "The program will count the approximate value of a square root.\nType the number you want to extract the root of: ";
    cin >> x;
    double lower_bnd, upper_bnd, mid_val,sol;
    lower_bnd = 1;
    upper_bnd = x / 2;
    while (upper_bnd >= lower_bnd)
    {
        mid_val = (lower_bnd + upper_bnd) / 2;
        if (mid_val * mid_val > x)
            upper_bnd = mid_val - 1;
        else
            lower_bnd = mid_val + 1;
        sol = (lower_bnd + upper_bnd) / 2;
    }
    cout << "The answer is:" << sol;
    cout << "\nComparison with build-in function sqrt():" << sqrt(x);
    return 0;

}
