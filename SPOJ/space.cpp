//by Małgorzata Kosakowska
//Delete spaces and make capital letters

#include <iostream>
#include <string>

using std::string,std::cin,std::cout,std::endl;

int main()
{
	string text;
	
		while(getline(cin, text))
		{
			for (int i = 0; i < text.size(); i++)
			{
				if (text[i] == ' ') {
					text.erase(i, 1);
					text[i] = toupper(text[i]);
					i--;

				}
			}
			cout << text << endl;
		}
		cin.ignore();
		cin.get();
}
