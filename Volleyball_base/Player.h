//by Małgorzata Kosakowska
#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <assert.h>


using std::string, std::vector, std::vector;

/// This class contains a player information

class Player
{
private:
	string name{};
	string surname{};
	int age{};
	int height{};

public:
	enum class Volley_position { Player, Outside, Opposite, Setter, Middle, Libero, Coach, Statistician, Physiatrist };
	Volley_position pos{ Volley_position::Player }; //Player as default


	Player(string n = "", string s = "", int a = 1, int h = 1, Volley_position p = Volley_position::Player)
	{
		name = n;
		surname = s;
		age = a;
		height = h;
		pos = p;
		assert(a > 0);
		assert(h > 0);
	}
	using base = vector <Player>;

	string Get_name() const;
	string Get_surname() const;
	int Get_age() const;
	int Get_height() const;
	Volley_position Get_position() const;

	void Set_name(string);
	void Set_surname(string);
	void Set_age(int);
	void Set_height(int);
	void Set_position(Volley_position);

};



