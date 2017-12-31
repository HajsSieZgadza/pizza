#include "Menu.h"
#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

int main()
{
	string a = "dane.txt", b = "pizza.txt", d = "Skladniki.txt", r = "rachunek.txt";
	Admin adm;
	Uzytkownik uzt;
	Pizza pizz;
	Konta kon;
	Skladnik skl;
	skl.wczytajSkladniki(d);
	Menu *wsk;
	wsk = &uzt;


	kon.wczytKont(a);
	pizz.wczytajMenu(b);


	char wybor;

	cout << "~~MENU~~\n1.) Nowe Konto.\n2.) Zaloguj.\n3.) Wyjdz" << endl;

	cin >> wybor;

	switch (wybor)
	{
	case '1':
	{
		kon.noweKonto(a);
		kon.zapisKont(kon, a);
		cout << "Uruchom program ponownie!" << endl;
		Sleep(2000);
		exit(0);
	}
	break;
	case '2':
	{
		switch (kon.zaloguj())
		{
		case 0:
		{
			exit(0);
		}
		break;
		case 1:
		{
			wsk = &uzt;
		}
		break;
		case 2:
		{
			wsk = &adm;
		}
		break;
		}
	}
	break;
	default:
	{
		exit(0);
	}
	break;
	}
	wsk->menu(&kon, &pizz, &skl, b);


	system("pause");
	return 0;
}
