//Lottery Ticket

#include <iostream>
#include<vector>
using namespace std;

std::string bingo(std::vector<std::pair<std::string, int>> ticket, int win)
{
    int mini_win = 0, temp = 0;
    for (int i = 0; i < ticket.size(); i++)
    {
        for (int j = 0; j < ticket[i].first.length(); j++)
        {
            if ((ticket[i].first)[j] == ticket[i].second)  temp++;
        }
        if (temp > 0)mini_win++;
        temp = 0;
    }
    if (mini_win >= win) return "Winner!";
    else return "Loser!";
}
