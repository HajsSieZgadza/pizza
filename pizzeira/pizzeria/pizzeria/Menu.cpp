#include "Menu.h"
using namespace std;

void Uzytkownik::menu(Konta *x, Pizza *y, Skladnik *z, string s)
{
	char wybor;
	cout << "1.) Wybierz pizze z menu.\n2.) Stworz pizze\n3.) Wyjdz\n ";
	cin >> wybor;
	switch (wybor)
	{
	case '1':
	{
		y->wyswietlMenu();

	}
	break;
	case '2':
	{
		z->zbudujPizze(s);
	}
	break;
	case '3':
	{
		exit(0);
	}
	break;
	default:
		break;
	}
}

void Admin::menu(Konta *x, Pizza *y, Skladnik *z, string s)
{
	char wybor;
	cout << "1.) Dodaj pizze.\n2.) Wyjdz\n ";
	cin >> wybor;
	switch (wybor)
	{
	case '1':
	{
		y->dodajPizze();
		y->zapisPizz(*y, s);
	}
	break;
	case '2':
	{
		exit(0);
	}
	break;
	default:
		break;
	}
}