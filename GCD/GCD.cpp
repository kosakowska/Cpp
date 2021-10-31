// GCD.cpp by Małgorzata Kosakowska
//

#include <iostream>
#include <cmath>

using std::cout, std::cin, std::endl;
int main()
{
	int a, b;
	double tmp;
	cout << "This program will count greatest common divisor.\nType in the first number:";
	cin >> a;
	cout << "Type in the second number:";
	cin >> b;
	
	while (b != 0)
	{
		tmp = b;
		b = a % b;
		a=tmp;
		
		
	}
	cout << "\nGreatest common divisor is :" << a;
	return 0;
}
