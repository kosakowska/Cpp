//Fruit Machine

#include <iostream>
#include<vector>
#include <array>
#include <map>
using namespace std;

unsigned fruit(const array<vector<string>, 3>& reels, const array<unsigned, 3>& spins)

{
    string name;
    vector<string> temp;
    for (int i = 0; i < 3; i++) {
        temp.push_back(reels[i][spins[i]]);
    }
  
    vector<pair<string, int>> ex = { {"Wild",10},{"Star",9},{"Bell",8},{"Shell",7},{"Seven",6},{"Cherry",5},{"Bar",4},{"King",3},{"Queen",2},{"Jack",1} };
    int sum{ 0 };
    auto it0 = find(temp.begin(), temp.end(), "Wild");
    if (it0 != temp.end()) {
        if (temp[0] == temp[1] && temp[1] == temp[2]) //Wild,Wild,Wild
        {
            //auto it = find_if(ex.begin(), ex.end(), temp[0]);
            auto it = std::distance(ex.begin(), std::find_if(ex.begin(), ex.end(), [&](const auto& pair) { return pair.first == temp[0]; }));

            if (it < ex.size())return (ex[it].second) * 10;
        }
        else if ((temp[0] == temp[1] || temp[0] == temp[2])&&((temp[0]=="Wild"&&(temp[0]==temp[1]||temp[0]==temp[2]))) )//Wild,Wild +coś
        {
            auto it = std::distance(ex.begin(), std::find_if(ex.begin(), ex.end(), [&](const auto& pair) { return pair.first == temp[0]; }));

            if (it < ex.size())return ex[it].second;
        }

        else if ((temp[1] == temp[2] || temp[0] == temp[2]) && ((temp[2] == "Wild" && ((temp[0] == temp[2]) ||temp[2] == temp[1]))))
        {           
            auto it = std::distance(ex.begin(), std::find_if(ex.begin(), ex.end(), [&](const auto& pair) { return pair.first == temp[2]; }));

            if (it < ex.size())return ex[it].second;            
        }
        

        else if ((temp[0] == temp[1] || temp[0] == temp[2]))
        {
            auto it = std::distance(ex.begin(), std::find_if(ex.begin(), ex.end(), [&](const auto& pair) { return pair.first == temp[0]; }));

            if (it < ex.size())return ex[it].second*2;
        }
        else if (temp[1] == temp[2] || temp[0] == temp[2])
        {
            auto it = std::distance(ex.begin(), std::find_if(ex.begin(), ex.end(), [&](const auto& pair) { return pair.first == temp[2]; }));

            if (it < ex.size())return ex[it].second*2;
        }
        return 0;

    }
    else
    {
        if (temp[0] == temp[1] && temp[1] == temp[2])
        {
            //auto it = find_if(ex.begin(), ex.end(), temp[0]);
            auto it = std::distance(ex.begin(), std::find_if(ex.begin(), ex.end(), [&](const auto& pair) { return pair.first == temp[0]; }));

            if (it < ex.size())return (ex[it].second) * 10;
        }

        else if (temp[0] == temp[1] || temp[0] == temp[2])
        {
            auto it = std::distance(ex.begin(), std::find_if(ex.begin(), ex.end(), [&](const auto& pair) { return pair.first == temp[0]; }));

            if (it < ex.size())return ex[it].second;
        }
        else if (temp[1] == temp[2] || temp[0] == temp[2])
        {
            auto it = std::distance(ex.begin(), std::find_if(ex.begin(), ex.end(), [&](const auto& pair) { return pair.first == temp[2]; }));

            if (it < ex.size())return ex[it].second;
        }
        return 0;
    }
}
