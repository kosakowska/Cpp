//by Małgorzata Kosakowska
#include <iostream>
using std::cin, std::cout;

int main()
{
    int input;
    while (cin >> input && input != 42)
      cout << '\t' << input << '\n';
    while (cin >> input);
}
