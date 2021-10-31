// Comp_int.cpp by Małgorzata Kosakowska
//

#include <iostream>
#include <cmath>
using std::cout, std::cin, std::endl;


double kap_rocz() {
	double V0, V, r, n;
	cout << "Podaj wartosc poczatkowa kapitalu:";
	cin >> V0; //kapitał początkowy
	if (V0 <= 0)
	{
		cout << "Kwota jest nieprawidlowa";
		return 0;
	}
	else
	{
		cout << "\nPodaj ile wynosi RRSO. \nTip: Jesli wynosi 5%, to podaj wartosc 0.05\n";
		cin >> r;
		cout << "Na ile lat zostawiasz pieniadze w banku?\n";
		cin >> n;
		V = V0 * (pow(1 + r, n));
		cout << "Kapital koncowy wyniesie:" << V << endl;
		return 0;
	}
}

double kap_podo() {
	double V0, V, r, n, m;
	cout << "Podaj wartosc poczatkowa kapitalu:";
	cin >> V0; //kapitał początkowy
	
	if (V0 <= 0)
	{
		cout << "Kwota jest nieprawidlowa";
		return 0;
	}
	else
	{
		cout << "\nPodaj ile wynosi RRSO. \nTip: Jesli wynosi 5%, to podaj wartosc 0.05\n";
		cin >> r;
		cout << "Na ile lat zostawiasz pieniadze w banku?\n";
		cin >> n;
		cout << "Podaj liczbe kapitalizacji w roku\n";
		cin >> m;
		V = V0 * (pow(1 + (r / m), n * m));
		cout << "Kapital koncowy wyniesie:" << V << endl;
		return 0;
	}
}


int main() {

	int a;
	cout << "Podaj jaki rodzaj kapitalizacji cie interesuje:\n1. Kapitalizacja roczna.\n2. Kapitalizacja podokresowa.\n\n";
	cin >> a;

	switch (a)
	{
	case 1:
		kap_rocz();
		break;
	case 2:
		kap_podo();
		break;
	}
	return 0;

}

