//by Małgorzata Kosakowska
#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Player.h"


using std::string, std::vector, std::vector;
using base = vector <Player>;


/// This class contains a team information

class Team
{
	string name{};
	base list{};

public:
	Team(string n = "", base l = { Player() })
	{
		name = n;
		list = l;
	}

	string Get_name() const;
	base Get_list() const;

	void Set_name(string);
	void Set_list(base);



};




