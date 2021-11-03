// Base.cpp by Małgorzata Kosakowska

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
#include <fstream>

using std::cout, std::cin, std::endl, std::vector, std::string, std::setw,std::ofstream, std::ostream, std::find,std::remove_if;

struct person
{
    string name{};
    string surname{};
    int age{};
};

using TAB = vector<person>;

//Adding personal data
auto Add(person a, TAB& tabela)
{
    tabela.push_back(a);
}

//Operator overloading
ostream& operator<<(ostream& o, const person &tabela)
{
    return o << setw(12) << tabela.name << setw(12) << tabela.surname << setw(12) << tabela.age << endl;
}

//Showing the base
auto Show(TAB tabela)
{
    if (tabela.size() == 0)
    
        cout << "\nThe base is empty.\n\n";
    
    else
    
        cout << setw(12) << "Name:" << " " << setw(12) << "Surname:" << " " << setw(12) << "Age:" << endl;
        for (int i = 0; i < tabela.size(); ++i)
            cout << tabela[i];
            //cout << setw(10) << tabela[i].name << " " << setw(10) << tabela[i].age << endl;
        
    
    return 0;
}


//Finding a person by name or surname
auto Find(string a, TAB tabela)
{
    for (int i = 0; i < tabela.size(); ++i)
    {
        if ((tabela[i].name == a) || (tabela[i].surname == a))
        {
            cout << "Found a person: " << endl;
            cout << tabela[i];
            //cout << setw(10) << tabela[i].name << " " << setw(10) << tabela[i].age << endl;
        }
        else
        {
            cout<< "\nPerson not found.\n\n";
            break;
        }
    }   

}


//Deleting personal data
auto Erase(string a, TAB &tabela)
{
    for (int i = 0; i < tabela.size(); ++i)
    {
        if ((tabela[i].name == a) || (tabela[i].surname == a))
        {
            
            tabela.erase(tabela.begin()+i);
        }

    }
}

//Saving to file
void Save(TAB tabela) {
    ofstream outFile("Base.txt");
    outFile << setw(12) << "Name:" << " " << setw(12) << "Surname:" << " " << setw(12) << "Age:" << endl;
    for (int i = 0; i < tabela.size(); i++)
    {
        outFile << tabela[i];
    }
    outFile.close();
}


int main()
{
    string s;
    int choice{};
    person a{};
    TAB list{};

 


    for (;;)
    {   
        cout << "What do you want to do?\n1.Add a person.\n2.Show the base.\n3.Find a person.\n4.Delete a record from base.\n5.Save to file.\n6.Quit the program.\n\nYour choice:";
        cin >> choice;
        switch (choice)
        {

        case 1:
            cout << "\nType in the name:";
            cin >> a.name;
            cout << "\nType in the surname:";
            cin >> a.surname;
            cout << "\nType in the age:";
            cin >> a.age;
            Add(a, list);
            cout << endl;
            break;
        case 2:
            Show(list);
            cout << endl;
            break;

        case 3:
            cout << "\nType in the name or surname you're looking for:";
            cin >> s;
            cout << endl;
            Find(s, list);
            break;
        case 4:
            cout << "\nType in the name or surname you want to delete:";
            cin >> s;
            cout << endl;
            Erase(s, list);
            break;
        case 5:
            Save(list);
            cout << "\nData saved to file." << endl;
            break;
        case 6:
            return 0;
        default:
            cout << "\nWrong number, try again" << endl<<endl;
            break;
        }
    }
}
