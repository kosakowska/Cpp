// Volleyball_base.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//
/*
1. Struct with name, surname, pesel (age from pesel), position + (add pesel)
2. Adding personal data +
3. Searching for a person +
4. Printing data (operator overloading) +
5. Save to file
6. Reading from file
7. Sorting by name, age (with the same names, surnames and ages) +
8. Printing only one position
9. Deleting personal data + 



Case:
1. Add
2. Show
3. Find by
	a. name
	b. surname
	c. age
	d. position
4. Delete
	a. name
	b. surname
	c. age
	d. position
5. Sort by
	a. name
	b. surname
	c. age
6. Print only one
7. Save
*/


#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <ostream>
#include <fstream>
#include <algorithm>
#include <assert.h>
#include <iterator>  

using std::cout, std::cin, std::endl, std::setw, std::string, std::vector, std::ostream, std::fstream,std::sort,std::left, std::erase,std::ostream_iterator;

struct Volleyball 
{
	string name{};
	string surname{};
	int age{}; //try applying pesel number and then age

	enum class Volley_position {Player,Outside_Hitter, Opposite_Hitter, Setter, Middle, Libero}; //Przypisuje kolejne liczby od 0
	Volley_position pos{ Volley_position::Player }; //Inicjalizuje pos na Player

	Volleyball(string n = "", string s = "", int a = 1, Volley_position p= Volley_position::Player)
	{
		name = n;
		surname = s;
		age = a;
		pos = p;
		assert(a > 0);
	}
};

using base = vector <Volleyball>;

//Operator overloading
ostream& operator <<(ostream& o, const Volleyball& a)
{
	const vector <string> Volley_position_Names{ "Player","Outside Hitter","Opposite Hitter", "Setter","Middle","Libero" };
	o << left << setw(10) << a.name << " ";
	o << left << setw(10) << a.surname << " ";
	o << left << setw(4) << a.age << " ";
	o << left << setw(10) << Volley_position_Names[static_cast <size_t> (a.pos)] << " "; //static_cast <size_t> (a.pos) zwraca numer pozycji wybranej z listy i wybiera z wektora stringów Volley_position_Names
	return o;

}


//Printing
auto Print_base(base list)
{
	if (list.size() == 0)
		cout << "The base is empty.\n";
	else {
		for (int i = 0; i < list.size(); ++i)
		{
			cout << list[i];
			cout << endl;
		}
		cout << endl;
	}
}

//Print more universal
auto Print(base list)
{
	copy(list.begin(), list.end(), ostream_iterator<Volleyball>(cout, "\n"));
}

//Adding
auto Add_to_base(Volleyball person, base & list)
{
	list.push_back(person);
}

//Find by name
auto Find_by_name(base& list)
{
	cout << "Type in the name: ";
	string look{};
	cin >> look;
	int control{};
	for (int i = 0; i < list.size(); ++i)
	{
		if (list[i].name == look )
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
}

//Find by surname
auto Find_by_surname(base& list)
{
	cout << "Type in the surname: ";
	string look{};
	cin >> look;
	int control{};
	for (int i = 0; i < list.size(); ++i)
	{
		if (list[i].surname == look)
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
}

//Find by age
auto Find_by_age(base& list)
{
	cout << "Type in the age: ";
	int look{}, control{};
	cin >> look;
	for (int i = 0; i < list.size(); ++i)
	{
		if (int(list[i].age )== look)
		{
			control ++ ;
			cout << "Found a person: ";
			cout << list[i];
			cout << endl;
		}
	}
	if (control == 0)
	{
		cout << "Person not in the base. \n";
	}
}

//Find by position
auto Find_by_position(base& list)
{
	cout << "Type in the position: \n1. Outside Hitter\n2. Opposite Hitter\n3. Setter\n4. Middle\n5. Libero\nYour choice: ";
	int look{}, control{};
	cin >> look;
	for (int i = 0; i < list.size(); ++i)
	{
		if (int(list[i].pos) == look)
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
}


//Find with choice
auto Find( base& list)
{
	cout << "How do you want to find a person?\n1.By name\n2.By surname\n3.By age\n4.By position\nYour choice: ";
	int choice{};
	cin >> choice;
	switch (choice)
	{
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
	}


	
}


//Delete by name
auto Delete_by_name(base& list)
{
	cout << "Type in the name: ";
	string look{};
	cin >> look;
	int control{};
	for (int i = 0; i < list.size(); ++i)
	{
		if (list[i].name == look)
		{
			list.erase(list.begin() + i);
			control++;
		}

	}
	if (control == 0)
	{
		cout << "Person not in the base. \n";
	}
}

//Delete by surname
auto Delete_by_surname(base& list)
{
	cout << "Type in the surname: ";
	string look{};
	cin >> look;
	int control{};
	for (int i = 0; i < list.size(); ++i)
	{
		if (list[i].surname == look)
		{
			list.erase(list.begin() + i);
			control++;
		}

	}
	if (control == 0)
	{
		cout << "Person not in the base. \n";
	}
}

//Delete by age
auto Delete_by_age(base& list)
{
	cout << "Type in the age: ";
	int look{};
	cin >> look;
	int control{};
	for (int i = 0; i < list.size(); ++i)
	{
		if (int(list[i].age) == look)
		{
			list.erase(list.begin() + i);
			control++;
		}

	}
	if (control == 0)
	{
		cout << "Person not in the base. \n";
	}
}

//Delete by position
auto Delete_by_position(base& list)
{
	cout << "Type in the position: \n1. Outside Hitter\n2. Opposite Hitter\n3. Setter\n4. Middle\n5. Libero\nYour choice: ";
	int look{}, control{};
	cin >> look;
	for (int i = 0; i < list.size(); ++i)
	{
		if (int(list[i].pos) == look)
		{
			list.erase(list.begin() + i);
			control++;
		}
	}
	if (control == 0)
	{
		cout << "Person not in the base. \n";

	}
}


//Delete with choice
auto Delete(base& list)
{
	cout << "How do you want to delete a person?\n1.By name\n2.By surname\n3.By age\n4.By position\nYour choice: ";
	int choice{};
	cin >> choice;
	switch (choice)
	{
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
	}



}

//Zobaczyć jak działa namespace, bo chyba te 3 sorty i find można by tam dodać
//Sort by name
auto Sort_by_name(base& list)
{
	sort(list.begin(), list.end(), [](const Volleyball person1, const Volleyball person2) {
		if (person1.name != person2.name)
			return person1.name < person2.name;
		else if (person1.surname != person2.surname)
			return person1.surname < person2.surname;
		else
			return person1.age < person2.age;
		});
	cout << "Base sorted by name:\n";
	Print(list);
}

//Sort by surnames
auto Sort_by_surname(base& list)
{
	sort(list.begin(), list.end(), [](const Volleyball person1, const Volleyball person2) {
		if (person1.surname != person2.surname)
			return person1.surname < person2.surname;
		else if (person1.name != person2.name)
			return person1.name < person2.name;
		else
			return person1.age < person2.age;
		});
	cout << "Base sorted by surname:\n";
	Print(list);
}

//Sort by age
auto Sort_by_age(base& list)
{
	sort(list.begin(), list.end(), [](const Volleyball person1, const Volleyball person2) {
		if (person1.age != person2.age)
			return person1.age < person2.age;
		else if (person1.name != person2.name)
			return person1.name < person2.name;
		else
			return person1.surname < person2.surname;
		
		});
	cout << "Base sorted by age:\n";
	Print(list);
}


//Sort with choice
auto Sort(base& list)
{
	cout << "How you want to sort the base?\n1.By name\n2.By surname\n3.By age\n";
	int choice{};
	cin >> choice;
	switch (choice)
	{
	case 1:
		Sort_by_name(list);
		break;
	case 2:
		Sort_by_surname(list);
		break;
	case 3:
		Sort_by_age(list);
		break;
	}

}



int main()
{
	
	base table;
	Volleyball a,b;
	

	//Adding as a list
	base Team  {

	{ "Phil", "Curtis",	18,  Volleyball::Volley_position::Middle },
	{ "Kamil", "Cyganek", 15,  Volleyball::Volley_position::Opposite_Hitter },
	{ "Phil", "Kowalski", 23,  Volleyball::Volley_position::Libero},
	{ "Phil", "Aowalski", 21,  Volleyball::Volley_position::Outside_Hitter}
	};

	//Adding one after one
	a.name = "Aga";
	a.surname = "Nowak";
	a.age = 23;
	a.pos = Volleyball::Volley_position::Setter;

	Add_to_base(a, Team);

	//Adding with a constructor
	b = Volleyball("Kasia", "Szklarz", 19, Volleyball::Volley_position::Middle);
	Add_to_base(b, Team);
	cout << endl;


	//Sort(Team);
	
	//Find(Team);
	//Print_base(Team);
	//Delete_by_name(Team);
	//Print_base(Team);
	//Delete(Team);
	//Print_base(Team);
	//Print(Team);

	return 0;
}

