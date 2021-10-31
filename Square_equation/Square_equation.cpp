// Square_equation.cpp by Małgorzata Kosakowska
//

#include <iostream>
#include <cmath>
using std::cout, std::cin, std::endl;

int main()
{
    double a, b, c;
    cout << "Type in the factors of square equation a, b, c\n";
    /*cin >> a;
    cin >> b;
    cin >> c;*/
    cin >> a >> b >> c;
    double delta = b * b - 4.0 * a * c;
    if (delta < 0)
        cout << "The equation doesn't have the real solution.";
    else if (delta == 0)
        cout << "The solution of the equation is x= " << -b / 2 * a;
    else
        cout << "The solutions of the equation are x1= " << (-b - sqrt(delta)) / 2 * a << " and x2= " << (-b + sqrt(delta)) / 2 * a;
    return 0;
}
