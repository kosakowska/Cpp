// Base.cpp by Małgorzata Kosakowska


#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <fstream>

using std::cout, std::cin, std::endl, std::vector, std::find, std::erase, std::ostream, std::ofstream,std::string,std::setw;

struct person
{
    string name{};
    string surname{};
    int age{};
};

//Operator overloading
ostream &operator<< (ostream &o, const person a)
{

    return o << setw(12) << a.name << " " << setw(12) << a.surname << " " << setw(12) << a.age << endl;

}

using TAB = vector<person>;

//Adding a person to the base
auto Add(person a, TAB &table)
{
    table.push_back(a);
}


//Showing the base
auto Show(TAB table)
{
    if (table.size() == 0)
    {
        cout << "\nThe base is empty.\n\n";
    }
    else
    {
        cout << setw(12) << "Name:" << " " << setw(12) << "Surname:" << " " << setw(12) << "Age:" << endl;
        for (int i = 0; i < table.size(); ++i)
        {
            cout << table[i];
        }
    }

}


//Finding a person in the base
auto Find(string a, TAB table)
{
    for (int i = 0; i < table.size(); ++i)
    {
        if ((table[i].name == a) || (table[i].surname == a))
        {
            cout << "Found a person: " << endl<<endl;
            cout << table[i];

        }
        /*else
        {
            cout << "Person not found" << endl<<endl;
            break;
        }*/
    }
}


//Deleting a person from the base
auto Erase(string a, TAB &table)
{
    for (int i = 0; i < table.size(); ++i)
    {
        if ((table[i].name == a) || (table[i].surname == a))
        {
            table.erase(table.begin() + i);
            cout << "A person got deleted.\n\n";
        }
    }
}


//Saving to file
auto Save(TAB table)
{
    ofstream outFile("Table.txt");
    outFile << setw(12) << "Name:" << " " << setw(12) << "Surname:" << " " << setw(12) << "Age:" << endl;
    for (int i = 0; i < table.size(); ++i)
    {
        outFile << table[i];
    }
    outFile.close();
}


int main()
{
    int choice{}; //for switch
    string n{}; //name or surname
    person a{}; //personal data
    TAB base{}; //data base

    for (;;)
    {
        cout << "\nWhat do you want to do?\n1. Add a person to the base.\n2. Show the table.\n3. Find a person.\n4. Delete a personal data.\n5. Save to file.\n6. Quit the program.\n";
        cout << "\nYour choice: ";
        cin >> choice;
        cout << endl;
        
        switch (choice)
        {
        case 1:
            cout << "\nType the name: ";
            cin >> a.name;
            cout << "\nType the surname: ";
            cin >> a.surname;
            cout << "\nType the age: ";
            cin >> a.age;
            Add(a, base);
            break;
            
        case 2:
            Show(base);
            break;

        case 3:
            cout << "\nType the name or surname you're looking for: ";
            cin >> n;
            Find(n, base);
            break;

        case 4:
            cout << "\nType the name or surname you want to erase: ";
            cin >> n;
            Erase(n, base);
            break;

        case 5:
            Save(base);
            cout << "\nSaved a file.\n";
            break;

        case 6:
            cout << "Closing the program...\n";
            return 0;

        default:
            cout << "\nWrong number, please try again.\n";
            break;

        }

    }

}

