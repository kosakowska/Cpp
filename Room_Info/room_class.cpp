//by Małgorzata Kosakowska

#include <iostream>
#include <vector>
#include <Windows.h>

using std::cin, std::cout, std::endl,std::vector,std::ostream;

class room
{
    int number, temp, R, G, B;
public:
    room(int n=0, int t=0, int r=0, int g=0, int b=0)
    {
        number = n;
        temp = t;
        R = r;
        G = g;
        B = b;
    }
    
    auto set_number(int n) { number = n; };
    auto set_temp(int t) { temp=t; };
    auto set_R(int r) { R = r; };
    auto set_G(int g) { G = g; };
    auto set_B(int b) { B = b; };

    auto get_number() { return number; };
    auto get_temp() { return temp; };
    auto get_R() { return R; };
    auto get_G() { return G; };
    auto get_B() { return B; };



};
using VD_r = vector<room>;

ostream& operator<<(ostream& os, room& a)
{
    os << "In room number: " << a.get_number() <<" temperature is: " << a.get_temp() << " and R value: " <<a.get_R() << " G value: " <<a.get_G()  << " B value: " << a.get_B()<< endl<<endl;
    return os;
}

ostream& operator<<(ostream& os, VD_r list)
{
    for (int i = 0; i < list.size(); i++)
    {
        os << list[i];
        Sleep(1000);
    }
    return os;
}

auto type(VD_r &list, room&a)
{
    for (int i = 0; i < 2; i++)
    {
        int val{ 0 };
        cout << "Type room number: ";
        cin >> val;
        a.set_number(val);
        cout << endl;
        cout << "Type in temperature: ";
        cin >> val;
        a.set_temp(val);
        cout << endl;
        cout << "Type in value of R: ";
        cin >> val;
        a.set_R(val);
        cout << endl;
        cout << "Type in value of G: ";
        cin >> val;
        a.set_G(val);
        cout << endl;
        cout << "Type in value of B: ";
        cin >> val;
        a.set_B(val);
        list.push_back(a);
        cout << endl;
    }
    
}


auto show(VD_r list)
{
    cout << list;
}

int main()
{
    VD_r list;
    room a;
    type(list, a);
    show(list);

}
