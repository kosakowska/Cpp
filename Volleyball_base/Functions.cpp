//by Małgorzata Kosakowska

#include "Player.h"
#include "Functions.h"
#include "Team.h"
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <ostream>
#include <fstream>
#include <algorithm>
#include <assert.h>
#include <iterator> 
#include <ostream>
#include <stdio.h>
#include <filesystem>
#include <Windows.h>


using std::cout, std::cin, std::endl, std::setw, std::getline, std::ws, std::to_string, std::string, std::vector, std::ifstream, std::ostream, std::fstream, std::sort, std::left, std::right, std::erase, std::ostream_iterator, std::ofstream, std::istream;
using base = vector <Player>;
using VD = vector<string>;
using VDi = vector<int>;
using list = vector<Team>;
namespace fs = std::filesystem;


/// Operator << overloading to output information about player
ostream& operator <<(ostream& o, const Player& a)
{
	const vector <string> Volley_position_Names{ "Player","Outside","Opposite", "Setter","Middle","Libero","Coach", "Statistician", "Physiatrist" };

	o << left << setw(10) << a.Get_name() << " ";
	o << left << setw(10) << a.Get_surname() << " ";
	o << left << setw(5) << a.Get_age() << " ";
	o << left << setw(9) << a.Get_height() << " ";
	o << left << setw(10) << Volley_position_Names[static_cast <size_t> (a.pos)] << " "; //static_cast <size_t> (a.pos) zwraca numer pozycji wybranej z listy i wybiera z wektora stringów Volley_position_Names

	return o;

}

/// Operator << overloading to output list of players with their information
ostream& operator <<(ostream& o, const base& list)
{
	//o<<copy(a.begin(), a.end(), ostream_iterator<Volleyball>(cout, "\n"));
	for (int i = 0; i < int(list.size()); ++i)
	{
		o << list[i] << endl;

	}
	return o;
}

/// Operator << overloading to output information about team
ostream& operator <<(ostream& o, const Team& a)
{
	o << left << setw(10) << "Team name:" << endl;
	o << left << setw(10) << a.Get_name() << endl << endl;
	o << left << setw(11) << "Name" << left << setw(11) << "Surname" << left << setw(6) << "Age" << left << setw(10) << left << "Height" << left << setw(10) << "Position" << endl;

	o << left << setw(10) << a.Get_list() << endl << endl;
	return o;
}

/// Operator >> overloading to input position of a player as string
istream& operator>>(istream& s, Player::Volley_position& position)
{
	string name;
	s >> name;


	if (name == "Outside")
		position = Player::Volley_position::Outside;
	else if (name == "Opposite")
		position = Player::Volley_position::Opposite;
	else if (name == "Setter")
		position = Player::Volley_position::Setter;
	else if (name == "Middle")
		position = Player::Volley_position::Middle;
	else if (name == "Libero")
		position = Player::Volley_position::Libero;
	else if (name == "Coach")
		position = Player::Volley_position::Coach;
	else if (name == "Statistician")
		position = Player::Volley_position::Statistician;
	else if (name == "Physiatrist")
		position = Player::Volley_position::Physiatrist;
	else
		position = Player::Volley_position::Player; //default jesli wpiszemy zle nazwe

	return s;
}

/// Function that interprates a string name of position as type of enum list
/// Input:
/// name - string representing a position
/// Output:
/// position - position as a type Volley_position (enum list type)
Player::Volley_position Interprate(string name)
{
	Player::Volley_position position;

	if (name == "Outside")
		position = Player::Volley_position::Outside;
	else if (name == "Opposite")
		position = Player::Volley_position::Opposite;
	else if (name == "Setter")
		position = Player::Volley_position::Setter;
	else if (name == "Middle")
		position = Player::Volley_position::Middle;
	else if (name == "Libero")
		position = Player::Volley_position::Libero;
	else if (name == "Coach")
		position = Player::Volley_position::Coach;
	else if (name == "Statistician")
		position = Player::Volley_position::Statistician;
	else if (name == "Physiatrist")
		position = Player::Volley_position::Physiatrist;
	else
		position = Player::Volley_position::Player; //default jesli wpiszemy zle nazwe


	return position;
}

/// Function that shows list of players
/// Input:
/// list - vector of players in base
void Print(base list)
{
	cout << left << setw(11) << "Name" << left << setw(11) << "Surname" << left << setw(6) << "Age" << left << setw(10) << left << "Height" << left << setw(10) << "Position" << endl;

	cout << list;
}

/// Function that saves list of players to a file
/// Input:
/// file - name of file to be saved to
/// list - vector of players in base
void Save(string file, base list)
{
	ofstream outFile(file);
	copy(list.begin(), list.end(), ostream_iterator<Player>(outFile, "\n"));
	outFile.close();
}

/// Function that reads a list of players from file
/// Input:
/// file - name of file to be read from
/// list - vector of players in base
/// Output:
/// 1 if the file was not found, couldn't be opened or its extension wasn't .txt
int Read(string file, base& list) {
	int position = file.find_last_of("."); //store the position of last '.' in the file name
	string result = file.substr(position + 1);//store the characters after the '.' from the file_name string

	ifstream myfile;
	string word;
	VD a; //do przechowywania rekordów jednej osoby
	int i = 0;

	myfile.open(file);
	if (myfile.is_open() && result == "txt") {
		while (!myfile.eof())
		{
			myfile >> word;
			a.push_back(word);
			i++;

			if (i == 5)
			{

				list.push_back(Player(a[0], a[1], stoi(a[2]), stoi(a[3]), Interprate(a[4])));
				a.clear();
				i = 0;
			}
		}
	}
	else
	{
		cout << "Couldn't open file or it's the wrong format.\n";
		return 1;
	}
}

/// Function that adds a player to the base
/// Input:
/// person - a player with its information
/// list - vector of players in base
void Add_to_base(Player person, base& list)
{
	list.push_back(person);
}

/// Function that finds a player by name and displays them
/// Input:
/// list - vector of players in base
/// Output:
/// 1 if 0 pressed (used as a quit button)
int Find_by_name(base& list)
{
	cout << "Type in the name: ";
	string look{};
	cin >> look;
	cin.ignore(100, '\n');
	if (look == "0") return 1;
	int control{};
	for (int i = 0; i < int(list.size()); ++i)
	{
		if (list[i].Get_name() == look)
		{
			cout << "Found a person: ";
			cout << list[i];
			cout << endl;
			control++;
		}

	}
	if (control == 0)
	{
		cout << "Person not in the base. \n";
	}
	cout << endl;
}

/// Function that finds a player by surname and displays them
/// Input:
/// list - vector of players in base
/// Output:
/// 1 if 0 pressed (used as a quit button)
int Find_by_surname(base& list)
{
	cout << "Type in the surname: ";
	string look{};
	cin >> look;
	cin.ignore(100, '\n');
	if (look == "0") return 1;
	int control{};
	for (int i = 0; i < int(list.size()); ++i)
	{
		if (list[i].Get_surname() == look)
		{
			control++;
			cout << "Found a person: ";
			cout << list[i];
			cout << endl;
		}
	}
	if (control == 0)
	{
		cout << "Person not in the base. \n";
	}
	cout << endl;
}

/// Function that finds a player by age and displays them
/// Input:
/// list - vector of players in base
/// Output:
/// 1 if 0 pressed (used as a quit button)
int Find_by_age(base& list)
{
	cout << "Type in the age: ";
	int look{}, control{};
	cin >> look;
	Secure_cin();
	if (look == 0) return 1;
	for (int i = 0; i < int(list.size()); ++i)
	{
		if (int(list[i].Get_age()) == look)
		{
			control++;
			cout << "Found a person: ";
			cout << list[i];
			cout << endl;
		}
	}
	if (control == 0)
	{
		cout << "Person not in the base. \n";
	}
	cout << endl;
}

/// Function that finds a player by position and displays them
/// Input:
/// list - vector of players in base
/// Output:
/// 1 if 0 pressed (used as a quit button)
int Find_by_position(base& list)
{
	cout << "Type in the number of position:\n0. Go to main menu. \n1. Outside Hitter\n2. Opposite Hitter\n3. Setter\n4. Middle\n5. Libero\n6. Coach\n7. Statistician\n8. Physiatrist\nYour choice: ";
	int look{}, control{};
	cin >> look;
	Secure_cin();
	if (look == 0) return 1;
	for (int i = 0; i < int(list.size()); ++i)
	{
		if (int(list[i].Get_position()) == look)
		{
			control++;
			cout << "Found a person: ";
			cout << list[i];
			cout << endl;
		}
	}
	if (control == 0)
	{
		cout << "Person not in the base. \n";

	}
	cout << endl;
}

/// Function that gives a choice to user of how to find a person
/// Input:
/// list - vector of players in base
void Find(base& list)
{
	cout << "How do you want to find a person?\n0. Go to main menu.\n1.By name\n2.By surname\n3.By age\n4.By position\nYour choice: ";
	int choice{};
	cin >> choice;
	Clear();
	Secure_cin();
	
	switch (choice)
	{
	case 0:
		break;
	case 1:
		Find_by_name(list);
		break;
	case 2:
		Find_by_surname(list);
		break;
	case 3:
		Find_by_age(list);
		break;
	case 4:
		Find_by_position(list);
		break;
	default:
		cout << "Wrong number!\n\n";
		break;
	}



}

/// Function that deletes a player by name
/// Input:
/// list - vector of players in base
/// Output:
/// 1 if 0 pressed (used as a quit button)
int Delete_by_name(base& list)
{
	cout << "Type in the name: ";
	string look{};
	VDi a{};
	cin >> look;
	cin.ignore(100, '\n');
	if (look == "0") return 1;
	int control{};
	for (int i = 0; i < int(list.size()); ++i)
	{
		if (list[i].Get_name() == look)
		{
			a.push_back(i);
			control++;
		}
	}
	for (int i = int(a.size() - 1); i >= 0; i--)
	{

		list.erase(list.begin() + a[i]);
		control++;

	}


	if (control == 0)
	{
		cout << "Person not in the base. \n";
	}
	cout << endl;
}

/// Function that deletes a player by surname
/// Input:
/// list - vector of players in base
/// Output:
/// 1 if 0 pressed (used as a quit button)
int Delete_by_surname(base& list)
{
	cout << "Type in the surname: ";
	string look{};
	VDi a{};
	cin >> look;
	cin.ignore(100, '\n');
	if (look == "0") return 1;
	int control{};
	for (int i = 0; i < int(list.size()); ++i)
	{
		if (list[i].Get_surname() == look)
		{
			a.push_back(i);
			control++;
		}
	}
	for (int i = int(a.size() - 1); i >= 0; i--)
	{

		list.erase(list.begin() + a[i]);
		control++;

	}
	if (control == 0)
	{
		cout << "Person not in the base. \n";
	}
	cout << endl;
}

/// Function that deletes a player by age
/// Input:
/// list - vector of players in base
/// Output:
/// 1 if 0 pressed (used as a quit button)
int Delete_by_age(base& list)
{
	cout << "Type in the age: ";
	int look{};
	VDi a{};
	cin >> look;
	Secure_cin();
	if (look == 0) return 1;
	int control{};
	for (int i = 0; i < int(list.size()); ++i)
	{
		if (int(list[i].Get_age()) == look)
		{
			a.push_back(i);
			control++;
		}
	}
	for (int i = int(a.size() - 1); i >= 0; i--)
	{

		list.erase(list.begin() + a[i]);
		control++;

	}

	if (control == 0)
	{
		cout << "Person not in the base. \n";
	}
	cout << endl;
}

/// Function that deletes a player by position
/// Input:
/// list - vector of players in base
/// Output:
/// 1 if 0 pressed (used as a quit button)
int Delete_by_position(base& list)
{
	cout << "Type in the number of position:\n0. Go to main menu. \n1. Outside Hitter\n2. Opposite Hitter\n3. Setter\n4. Middle\n5. Libero\n6. Coach\n7. Statistician\n8. Physiatrist\nYour choice: ";
	int look{}, control{};
	VDi a{};
	cin >> look;
	Secure_cin();
	if (look == 0) return 1;
	for (int i = 0; i < int(list.size()); ++i)
	{
		if (int(list[i].Get_position()) == look)
		{
			a.push_back(i);

			control++;
		}
	}
	for (int i = int(a.size() - 1); i >= 0; i--)
	{

		list.erase(list.begin() + a[i]);
		control++;

	}
	if (control == 0)
	{
		cout << "Person not in the base. \n";

	}
	cout << endl;
}


/// Function that gives a choice to user of how to delete a person
/// Input:
/// list - vector of players in base
void Delete(base& list)
{
	cout << "How do you want to delete a person?\n0. Go to main menu.\n1.By name\n2.By surname\n3.By age\n4.By position\nYour choice: ";
	int choice{};
	cin >> choice;
	Clear();
	Secure_cin();
	
	switch (choice)
	{
	case 0:
		break;
	case 1:
		Delete_by_name(list);
		break;
	case 2:
		Delete_by_surname(list);
		break;
	case 3:
		Delete_by_age(list);
		break;
	case 4:
		Delete_by_position(list);
		break;
	default:
		cout << "Wrong number!\n\n";
		break;
	}



}

/// Function that deletes everone from the list of players
/// Input:
/// list - vector of players in base
void Delete_everyone(base& list)
{
	char n{};
	cout << "\nThis function will delete everyone from your team.";
	cout << "\nDo you want to continue? \nY-yes\nN-no\nYour choice: ";
	cin >> n;
	switch (n)
	{
	case 0:
		break;
	case 'Y':
		list.clear();
		break;
	case 'N':
		break;
	default:
		cout << "\nWrong expression, try again" << endl << endl;
		break;

	}

}

/// Function that sorts players by name and displays the list
/// Input:
/// list - vector of players in base
void Sort_by_name(base& list)
{
	sort(list.begin(), list.end(), [](const Player person1, const Player person2) {
		if (person1.Get_name() != person2.Get_name())
			return person1.Get_name() < person2.Get_name();
		else if (person1.Get_surname() != person2.Get_surname())
			return person1.Get_surname() < person2.Get_surname();
		else if (person1.Get_age() != person2.Get_age())
			return person1.Get_age() < person2.Get_age();
		else
			return person1.Get_height() < person2.Get_height();
		});
	cout << "Base sorted by name:\n";
	Print(list);
	cout << endl;
}

/// Function that sorts players by surname and displays the list
/// Input:
/// list - vector of players in base
void Sort_by_surname(base& list)
{
	sort(list.begin(), list.end(), [](const Player person1, const Player person2) {
		if (person1.Get_surname() != person2.Get_surname())
			return person1.Get_surname() < person2.Get_surname();
		else if (person1.Get_name() != person2.Get_name())
			return person1.Get_name() < person2.Get_name();
		else if (person1.Get_age() != person2.Get_age())
			return person1.Get_age() < person2.Get_age();
		else
			return person1.Get_height() < person2.Get_height();
		});
	cout << "Base sorted by surname:\n";
	Print(list);
	cout << endl;
}

/// Function that sorts players by age and displays the list
/// Input:
/// list - vector of players in base
void Sort_by_age(base& list)
{
	sort(list.begin(), list.end(), [](const Player person1, const Player person2) {
		if (person1.Get_age() != person2.Get_age())
			return person1.Get_age() < person2.Get_age();
		else if (person1.Get_name() != person2.Get_name())
			return person1.Get_name() < person2.Get_name();
		else if (person1.Get_surname() != person2.Get_surname())
			return person1.Get_surname() < person2.Get_surname();
		else
			return person1.Get_height() < person2.Get_height();
		});
	cout << "Base sorted by age:\n";
	Print(list);
	cout << endl;
}

/// Function that sorts players by height and displays the list
/// Input:
/// list - vector of players in base
void Sort_by_height(base& list)
{
	sort(list.begin(), list.end(), [](const Player person1, const Player person2) {
		if (person1.Get_height() != person2.Get_height())
			return person1.Get_height() < person2.Get_height();
		else if (person1.Get_age() != person2.Get_age())
			return person1.Get_age() < person2.Get_age();
		else if (person1.Get_name() != person2.Get_name())
			return person1.Get_name() < person2.Get_name();
		else
			return person1.Get_surname() < person2.Get_surname();

		});
	cout << "Base sorted by height:\n";
	Print(list);
	cout << endl;
}

/// Function that gives a choice to user of how to sort the list
/// Input:
/// list - vector of players in base
void Sort(base& list)
{
	cout << "How you want to sort the base?\n0. Go to main menu.\n1.By name\n2.By surname\n3.By age\n4.By height\n\nYour choice: ";
	int choice{};
	cin >> choice;
	Clear();
	Secure_cin();

	switch (choice)
	{
	case 0:
		break;
	case 1:
		Sort_by_name(list);
		break;
	case 2:
		Sort_by_surname(list);
		break;
	case 3:
		Sort_by_age(list);
		break;
	case 4:
		Sort_by_height(list);
		break;
	default:
		cout << "Wrong number. Try again.\n\n";
		break;
	}

}

/// Function that finds a player by name and surname 
/// Input:
/// list - vector of players in base
/// Output:
/// -1 if 0 pressed (used as a quit button) or person not found in the base
/// con - index of a player found in the base
int Find_to_Edit(base& list)
{
	cout << "Type in the name: ";
	string look{}, look2{};
	cin>>look;
	cin.ignore(100, '\n');
	if (look == "0") return -1;
	cout << "\nType in the surname: ";
	cin >> look2;
	cin.ignore(100, '\n');
	if (look2 == "0") return -1;
	Clear();
	int control{}, con{};
	for (int i = 0; i < int(list.size()); ++i)
	{
		if ((list[i].Get_name() == look) && (list[i].Get_surname() == look2))
		{
			cout << "Found a person: ";
			cout << list[i];
			cout << endl;
			control++;
			con = i;
		}

	}

	if (control == 0)
	{
		cout << "Person not in the base. \n";
		return -1;
	}
	cout << endl;
	return con;

}

/// Function that gives choice to user of what to edit in player data (name,surname,age,height,position)
/// Input:
/// list - vector of players in base
void Edit(base& list)
{
	int a{}, choice{}, num{}; //a do przechowywania indeksu znaleznionej odoby, a choice do wyboru co zmienic
	string text{}; //do name albo surname
	a = Find_to_Edit(list);
	if (a != -1)
	{
		cout << "What do you want to edit here:\n0. Go to main menu.\n1. Name.\n2. Surname.\n3. Age.\n4. Height.\n5. Position.\n\nYour choice: ";
		cin >> choice;
		Secure_cin();

		switch (choice)
		{
		case 0:
			break;
		case 1:
			cout << "Type the new name: ";
			cin >> text;
			cin.ignore(100, '\n');
			if (text == "0") break;
			cout << endl;
			list[a].Set_name(text);
			Clear();
			break;
		case 2:
			cout << "Type the new surname: ";
			cin >> text;
			cin.ignore(100, '\n');
			if (text == "0") break;
			cout << endl;
			list[a].Set_surname(text);
			Clear();
			break;
		case 3:
			cout << "Type the new age: ";
			cin >> num;
			Secure_cin();
			if (num == 0) break;
			assert(num >= 0);
			cout << endl;
			list[a].Set_age(num);
			Clear();
			break;
		case 4:
			cout << "Type the new height: ";
			cin >> num;
			Secure_cin();
			if (num == 0) break;
			assert(num >= 0);
			cout << endl;
			list[a].Set_height(num);
			Clear();
			break;
		case 5:
			cout << "Type the new position: \nOutside\nOpposite\nSetter\nMiddle\nLibero\nCoach\nStatistician\nPhysiatrist  \nYour choice: ";
			cin >> text;
			cin.ignore(100, '\n');
			if (text == "0")break;
			list[a].pos = Interprate(text);
			cout << endl;
			Clear();
			break;


		default:
			cout << "Wrong number.\nTry again.\n";
			break;

		}
	}





}

/// Function that creates a list of players with only one particular position
/// Input:
/// list - vector of players in base
/// pos - number of position (like in enum list)
/// Output:
/// base - list of players with only one position (pos)
base Pos_check(base list, int pos)
{
	base lista{};
	for (int i = 0; i < int(list.size()); ++i)
	{
		if (int(list[i].Get_position()) == pos)
		{
			lista.push_back(list[i]);
		}
	}
	return lista;
}

/// Function that chooses players randomly from given list
/// Input:
/// list - vector of players in base
/// num - number of players (based on position) needed during match
void Random(base list, int num)
{
	if (int(list.size()) >= num)
	{

		for (int i = 0; i < num; ++i)
		{
			int a = rand() % list.size();
			cout << list[a] << endl;
			list.erase(list.begin() + a);
		}
	}

}

/// Function that generates a team from random players
/// Input:
/// list - vector of players in base
void Rand_Team(base list)
{
	base lista{}, c{};
	int a1{}, a2{}, a3{}, a4{}, a5{}, a6{}, a7{}, a8{};
	cout << endl;
	cout << left << setw(11) << "Name" << left << setw(11) << "Surname" << left << setw(6) << "Age" << left << setw(10) << left << "Height" << left << setw(10) << "Position" << endl;

	//Outside
	c = Pos_check(list, 1);
	Random(c, 4);
	//Opposite
	c = Pos_check(list, 2);
	Random(c, 3);
	//Setter
	c = Pos_check(list, 3);
	Random(c, 2);
	//Middle
	c = Pos_check(list, 4);
	Random(c, 4);
	//Libero
	c = Pos_check(list, 5);
	Random(c, 2);
	//Coach
	c = Pos_check(list, 6);
	Random(c, 1);
	//Statistician
	c = Pos_check(list, 7);
	Random(c, 2);
	//Physiatrist
	c = Pos_check(list, 8);
	Random(c, 2);


}

/// Function checks if there are enought players in the list
/// Input:
/// list - vector of players in base
/// pos - vector (of int) with numbers of positions 
/// il - vector (of int) with number of players needed on team
/// Output:
/// 1 if there are enough players in base to generate team
/// 2 if there are not enough players in base to generate team
int Check_pos(base list, VDi pos, VDi il)
{
	int il2{}, il3{};
	for (int i = 0; i < int(pos.size()); ++i)
	{
		for (int j = 0; j < int(list.size()); ++j)
		{
			if (int(list[j].Get_position()) == pos[i])
				il2++;
		}
		if (il2 >= il[i])
			il3++;
	}
	if (il3 == 8)
		return 1;
	else
		return 2;
}

/// Function that gives user a choice to generate a team  
/// Input:
/// list - vector of players in base
void Rand_switch(base list)
{
	char n{};
	VDi pos = { 1,2,3,4,5,6,7,8 };
	VDi il = { 4,3,2,4,2,1,2,2 };
	int i{};
	i = Check_pos(list, pos, il);
	cout << "\nTo perform this function you need to have at least 4 Outside, 3 Opposite, 2 Setters, 4 Middle, 2 Libero, 1 Coach, 2 Statisticians and 2 Physiatrist in the base. ";
	cout << "\nDo you want to continue? \nY-yes\nN-no\nYour choice: ";
	cin >> n;
	if (i == 1)
	{
		switch (n)
		{
		case 0:
			break;
		case 'Y':
			Rand_Team(list);
			break;
		case 'N':
			break;
		default:
			cout << "\nWrong expression, try again" << endl << endl;
			break;
		}
	}
	else
	{
		cout << "\nNot enough players. Add more and try again.\n\n";
	}
}

/// Function that displays files with extension .txt in current catalog 
/// Output:
/// 1 if there are no files .txt in current catalog
int Files()
{
	int con = 0;
	for (const auto& entry : fs::directory_iterator(fs::current_path())) {
		if (entry.path().extension().string() == ".txt") {
			const auto filenameStr = entry.path().filename().string();

			cout << filenameStr << endl;
			con++;
		}
	}
	if (con == 0)
	{
		cout << "\nThere are no files you can load in current catalog. Create one and try again.\n\n";
		return 1;
	}

}

/// Function that adds one person to the team
/// Input:
/// list - vector of players in base
/// a - index of person in base
/// list1 - temporary list of players to be added to
void Add_to_team(base list, int a, base& list1)
{
	list1.push_back(list[a]);

}

/// Function that adds a team to the team base
/// Input:
/// a - team with its information
/// table - vector of teams in base
void Add_a_team(Team a, list& table)
{
	table.push_back(a);

}

/// Function that displays teams
/// Input:
/// table - vector of teams in base
void Show_a_team(list table)
{

	if (table.size() == 0) cout << "\nList is empty.\n";
	else
	{
		copy(table.begin(), table.end(), ostream_iterator<Team>(cout, "\n"));
		cout << endl;
	}
}

/// Function that gives user a choice of how to add players to the team
/// Input:
/// list - vector of players in base
/// list1 - temporary vector of players in base
/// Output:
/// list1 - new vector of players in base
base Choose_to_add(base& list, base& list1)
{
	int choice{}, e{};
	choice = 1;
	while (choice != 2)
	{

		switch (choice)
		{
		case 0:
			break;
		case 1:
			cout << "\nNow you can choose your players.\n";

			cout << "People you can choose from:\n";
			Print(list);

			e = Find_to_Edit(list);
			Clear();
			if (e != -1) {

				Add_to_team(list, e, list1);
				break;
			}

			else
				break;
		case 2:
			break;
		default:
			cout << "Wrong number.\n";
			break;
		}
		cout << "\n1. Add another person.\n2. Quit.\n\nYour choice: ";
		cin >> choice;
		Secure_cin();
	}
	return list1;
}

/// Function that returns name of teams in th base
/// Input:
/// table - vector of teams in base
void Only_team_names(list table)
{
	for (int i = 0; i < int(table.size()); ++i)
	{
		cout << table[i].Get_name();
		cout << endl;
	}
}

/// Function that checks if the team exist by name
/// Input:
/// name - name of team
/// table - vector of teams in base
int Check_if_team_ex(string name, list table)
{
	int con{};
	for (int i = 0; i < int(table.size()); ++i)
	{
		if (name == table[i].Get_name())
			con++;
	}
	if (con != 0)
		return 1;
}

/// Function that returns list of players in team by name of the team
/// Input:
/// name - name of team
/// table - vector of teams in base
/// Output:
/// team_list - list of players in team
base Ret_list_by_name(string name, list lista)
{
	base team_list{};
	for (int i = 0; i < int(lista.size()); ++i)
	{
		if (name == lista[i].Get_name())
			team_list = lista[i].Get_list();
	}
	return team_list;
}

/// Function that overwrites a team list with given list of players
/// Input:
/// name - name of team
/// table - vector of teams in base
/// list - vector of players in base
void Overwrite(string name, list& table, base list)
{
	for (int i = 0; i < int(table.size()); ++i)
	{
		if (name == table[i].Get_name())
			table[i].Set_list(list);
	}
}

/// Function that saves base of teams into a file
/// Input:
/// file - name of file to be saved to
/// table - vector of teams in base
void Save_Teams(string file, list table)
{

	fs::path path{ fs::current_path() };
	std::u8string path_string{ path.u8string() };

	path += "\\Teams\\"; //Adding an extra catalog to path 
	path += file;
	ofstream outFile(path);


	copy(table.begin(), table.end(), ostream_iterator<Team>(outFile, "\n"));
	outFile.close();
}

/// Function that adds a person to a team (name, surname ...)
/// Input:
/// list - vector of players in base
/// b - team and its information
/// Output:
/// list - modified vector of players in base
base Add(base& list, Team& b)
{
	string name{}, k{};
	int choice{}, g{};
	Player a{};
	choice = 1;

	while (choice != 2)
	{



		switch (choice)
		{
		case 0:
			break;
		case 1:
			cout << "\nType in the name:";
			cin >> k;
			cin.ignore(100, '\n');

			if (k == "0") break;
			a.Set_name(k);
			cout << "\nType in the surname:";
			cin >> k;
			cin.ignore(100, '\n');
			if (k == "0") break;
			a.Set_surname(k);
			cout << "\nType in the age:";
			cin >> g;
			Secure_cin();
			if (g == 0) break;
			assert(g >= 0);
			a.Set_age(g);
			cout << "\nType in the height:";
			cin >> g;
			Secure_cin();
			if (g == 0) break;
			assert(g >= 0);
			a.Set_height(g);
			cout << "\nType in the position:\nOutside\nOpposite\nSetter\nMiddle\nLibero\nCoach\nStatistician\nPhysiatrist\nYour choice: ";
			cin >> k;
			cin.ignore(100, '\n');
			if (k == "0") break;
			a.Set_position(Interprate(k));
			Add_to_base(a, list);
			Clear();
			break;
		case 2:
			break;
		default:
			cout << "Wrong number.\n";
			break;
		}
		cout << "\n1. Add another person.\n2. Quit.\n\nYour choice: ";
		cin >> choice;
		Clear();
		Secure_cin();

	}



	cout << endl;
	return list;
}

/// Function that gives user a choice of how to add a person to the team (load or add new)
/// Input:
/// table - vector of teams in base
/// list - vector of players in base
/// list1 - temporary vector of players
/// list2 - temporary vector of players
/// Output:
/// 1 if 0 pressed (used as a quit button)
int Add_by_case(list& table, base& list, base& list1, base& list2)
{
	int choice{}, g;
	string k{}, name{};
	Player a{};
	Team b{};
	base c{}, d{}, e{};
	cout << "To add a new team, we need to know its name.\nType in the name.\nTeam: ";
	getline(cin>>ws,name);
	if (name == "0") return 1;

	b.Set_name(name);
	while (choice != 3)
	{
		cout << "\n1. Load a file and add a person to the team.\n2. Add a new person.\n3. Go to main menu.\n\nYour choice: ";
		cin >> choice;
		Clear();
		Secure_cin();
		
		switch (choice)
		{
		case 0:
			break;
		case 1:
			g = Load(list);
			if (g == 1) break;
			c = Choose_to_add(list, list1);
			list.clear(); 
			Clear();

			break;
		case 2:
			d = Add(list2, b);
			Clear();
			break;
		case 3:
			break;
		default:
			cout << "Wrong number.\n";
			break;
		}
	}

	for (int i = 0; i < int(c.size()); ++i)
	{
		e.push_back(c[i]);
	}
	for (int j = 0; j < int(d.size()); ++j)
	{
		e.push_back(d[j]);
	}


	b.Set_list(e);
	Add_a_team(b, table);
}


/// Function that loads players to the base
/// Input:
/// list - vector of players in base
/// Output:
/// 1 if there are no files .txt in current catalog or couldn't open the file
int Load(base& list)
{
	string name{};
	int a{}, b{};
	cout << "Files in current catalog, you can choose from: \n";

	b = Files();
	if (b != 1) {
		cout << "Type in the name of the file with its extention: \n";
		cin >> name;
		cin.ignore(100, '\n');
		Clear();
		a = Read(name, list);
		if (a == 1)
			return 1;
		else
			cout << "\nRead from file." << endl;
	}
	else
		return 1;
}

/// Function that ensures that cin works properly
void Secure_cin()
{
	while (cin.fail())
	{
		cout << "\nInvalid argument. Try again!\n\n";
		cin.clear();
		cin.ignore();
	}
}

/// Function that clears the command window
void Clear()
{
	system("cls");
}



/// Function that works as a team editor menu
/// Input:
/// list - vector of players in base
/// Output:
/// list - modified vector of players in base
base Program(base& list)
{
	Player a{}, b{};
	int choice{};
	string k{}; //for names and surnames and files
	int g{}; //for age
	char n{};

	while (choice != 11) {
		cout << "What do you want to do?\nType in the number next to the function you want to start.\n1. Add a person to the base.\n2. Show data base.\n3. Find a person.\n4. Delete a person.\n5. Delete everyone from base.\n6. Sort data base.\n7. Save to file\n8. Read from file.\n9. Edit data.\n10. Generate a random team.\n11. Go back to main menu.\n";
		cout << "Your choice: ";
		cin >> choice;
		Secure_cin();
		Clear();
		switch (choice)
		{
		case 0:
			break;
		case 1:
			cout << "\nType in the name:";
			cin >> k;
			cin.ignore(100, '\n');
			if (k == "0") break;
			a.Set_name(k);
			cout << "\nType in the surname:";
			cin >> k;
			cin.ignore(100, '\n');
			if (k == "0") break;
			a.Set_surname(k);
			cout << "\nType in the age:";
			cin >> g;
			Secure_cin();
			if (g == 0) break;
			assert(g >= 0);
			a.Set_age(g);
			cout << "\nType in the height:";
			cin >> g;
			Secure_cin();
			if (g == 0) break;
			assert(g >= 0);
			a.Set_height(g);
			cout << "\nType in the position:\nOutside\nOpposite\nSetter\nMiddle\nLibero\nCoach\nStatistician\nPhysiatrist\nYour choice: ";
			cin >> k;
			cin.ignore(100, '\n');
			if (k == "0") break;
			Clear();
			a.Set_position(Interprate(k));

			Add_to_base(a, list);
			cout << endl;
			break;
		case 2:
			Print(list);
			cout << endl;
			break;

		case 3:
			cout << endl;
			if (list.size() > 0)
			{
				Find(list);
			}
			else
			{
				cout << "You must have at least one player to use this function.\n\n";
			}
			break;

		case 4:
			cout << endl;
			if (list.size() > 0)
			{
				Delete(list);
				
			}
			else
			{
				cout << "You must have at least one player to use this function.\n\n";
			}
			break;
		case 5:
			if (list.size() > 0)
			{
				Delete_everyone(list);
			}
			else
			{
				cout << "You must have at least one player to use this function.\n\n";
			}
			break;
		case 6:
			cout << endl;
			if (list.size() > 1)
			{
				Sort(list);
				
			}
			else
			{
				cout << "You must have at two players to use this function.\n\n";
			}
			break;
		case 7:
			cout << "Type in the name of the file with its extention, you want to create. Example: Base.txt : ";
			cin >> k;
			cin.ignore(100, '\n');
			if (k == "0") break;
			Save(k, list);
			cout << "\nData saved to file." << endl;
			break;
		case 8:
			Load(list);
			break;

		case 9:
			if (list.size() > 0)
			{
				cout << "\nTo edit you need to know the name and surname of a person put into the base!\nHere's the list of people in the base:\n";
				Print(list);
				Edit(list);
			}
			else
			{
				cout << "You must have at least one player to use this function.\n\n";
			}

			break;

		case 10:
			Rand_switch(list);
			break;
		case 11:
			return list;
		default:
			cout << "\nWrong number, try again" << endl << endl;
			break;
		}
	}
}

/// Main function in program, works as main menu
/// Input:
/// table - vector of teams in base
/// list - vector of players in base
/// Output:
/// 0 if the user wants to close the program
int Full_program(list& table, base& list)
{
	int choice{}, e{};
	Team a{};
	string name{};
	base list1{}, list2{};


	cout << "\nTo exit when exectuing a function you can press 0 and submit it with Enter.\n\n";
	cout << "1. Add a new team.\n2. Show teams.\n3. Edit the existing team.\n4. Save to file.\n5. Close.\n\nYour choice: ";
	cin >> choice;
	Clear();
	Secure_cin();


	switch (choice)
	{

	case 0:
		break;
	case 1:
		Add_by_case(table, list, list1, list2);
		break;
	case 2:
		Show_a_team(table);
		break;
	case 3:
		if (table.size() > 0) {
			cout << "Which team you want to edit?\n";
			Only_team_names(table);
			cout << "\nType in the name from the ones above:";
			getline(cin >> ws, name);
			if (name == "0") break;
			Clear();
			e = Check_if_team_ex(name, table);
			if (e == 1)
			{

				list1 = Ret_list_by_name(name, table);
				list1 = Program(list1);
				Overwrite(name, table, list1);
				break;
			}
			else {
				cout << "You need to type an existing name of a Team!\nTry again.\n\n";
				break;
			}
		}
		else
		{
			cout << "You must have at least one team to use this option! Add a team, and try again.\n\n";
			break;
		}

	case 4:
		cout << "Type in the name of the file with its extention, you want to create. Example: Base.txt : ";
		cin >> name;
		cin.ignore(100, '\n');
		if (name == "0") break;
		Save_Teams(name, table);
		cout << "\nData saved to file." << endl;
		break;
	case 5:
		return 0;

	default:
		cout << "\nWrong number, try again" << endl << endl;
		break;

	}



}
