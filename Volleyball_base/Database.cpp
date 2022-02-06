//by Małgorzata Kosakowska
#include <iostream>
#include <vector>
#include "Player.h"
#include "Functions.h"
#include "Team.h"

using base = vector <Player>;

int main()
{
	std::cout << "Welcome to the Volleyball base editor!\n\nBelow you have a few options to choose from.\n";
	std::cout << "\nTo use function 3 you need to have at least one team added to base. To add press 1.\n";

	int a{};
	list table{};
	base list{};
	for (;;)
	{
		a = Full_program(table, list);
		if (a == 0)
			return 0;

	}

	return 0;
}

