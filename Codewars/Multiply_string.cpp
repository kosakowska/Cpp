//Multiplying numbers as strings

#include <iostream>
#include <string>

using namespace std;

string multiply(string a, string b) {
    if (a == "0" || b == "0")return "0";
    string prod(a.size() + b.size(), 0);
    for (int i = a.length() - 1; i >= 0; i--)
    {
        for (int j = b.length() - 1; j >= 0; j--)
        {
            int n = (a[i] - '0') * (b[j] - '0') + prod[i + j + 1];
            prod[i + j + 1] = n % 10;
            prod[i + j] += n / 10;
        }
    }
    for (int i = 0; i < prod.size(); i++) {
        prod[i] += '0';
    }

    return prod.erase(0, prod.find_first_not_of('0'));

}
