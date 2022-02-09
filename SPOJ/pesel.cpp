//by Małgorzata Kosakowska
//Check if PESEL is correct

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
using vect = vector<string>;
using vect_n = vector<int>;
int main()
{
    int t{};
    cin >> t;
    vect a{};
    for (int i = 0; i < t; i++)
    {
        string g{};
        //cout << "wpisz:";
        cin >> g;
        a.push_back(g);
    }
    
    vect_n g = { 1,3,7,9,1,3,7,9,1,3,1 };

    int pom{ 0 }, suma{ 0 };
    char p{};
    
    for (int j = 0; j < a.size(); ++j)
    {
        for (int k = 0; k < a[j].size(); k++)
        {
            p=a[j][k];
            pom = p - '0';
            pom = pom * g[k];
            suma += pom;

        }
        if (suma % 10 == 0)cout << "D"<<endl; //Correct
        else cout << "N"<<endl; //Incorrect
        suma = 0;
        pom = 0;
    }
    
}
