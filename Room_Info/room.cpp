//by Małgorzata Kosakowska

#include <iostream>
#include <vector>
#include <Windows.h>

using std::cin, std::cout, std::endl,std::vector,;

using VD = vector<int>;

auto type(VD& room, VD &temp, VD& R, VD &G, VD &B)
{
    
    for (int i = 0; i < 2; i++)
    {
        int val{ 0 };
        cout << "Type in room number: ";
        cin >> val;
        room.push_back(val);
        cout << endl;
        cout << "Type in temperature: ";
        cin >> val;
        temp.push_back(val);
        cout << endl;
        cout << "Type in value of R: ";
        cin >> val;
        R.push_back(val);
        cout << endl;
        cout << "Type in value of G: ";
        cin >> val;
        G.push_back(val);
        cout << endl;
        cout << "Type in value of B: ";
        cin >> val;
        B.push_back(val);
        cout << endl;
    }

}

auto show(VD room,VD temp,VD R, VD G, VD B)
{
    for (int i = 0; i < room.size(); i++)
    {
        cout << "In room number: " << room[i] << " the temperature is: " << temp[i] << " R value: " << R[i] << " G value: " << G[i] << "B value: " << B[i] << endl;
        Sleep(1000);
    }

}


int main()
{
    VD room, temp, R, G, B;
    type(room, temp, R, G, B);
    show(room, temp, R, G, B);
}
