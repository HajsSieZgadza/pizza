#include "Pizza.h"
using namespace std;
#include <Windows.h>
Pizza::Pizza() {};
Pizza::Pizza(string _x, double _y, string _z)
{
	nazwa = _x;
	cena = _y;
	opis = _z;
}

void Pizza::wczytajMenu(string menu)
{
	ifstream plik(menu);
	string linie;
	while (getline(plik, linie))
	{
		stringstream wczyt(linie);
		double cena;
		string nazwa, opis;
		wczyt >> nazwa;
		wczyt.ignore();
		wczyt >> cena;
		wczyt.ignore();
		wczyt >> opis;
		pizza.push_back(Pizza(nazwa, cena, opis));
	}
	plik.close();
}

void Pizza::dodajPizze()
{
	string newNazwa, newOpis;
	double newCena;
	cout << "Podaj nazwe nowej pizzy : ";
	cin >> newNazwa;
	cout << "\nPodaj cene nowej pizzy : ";
	cin >> newCena;
	cout << "\nPodaj opis nowej pizzy : ";
	cin >> newOpis;
	pizza.push_back(Pizza(newNazwa, newCena, newOpis));
}


void Pizza::wyswietlMenu()
{
	ofstream zapis("rachunek.txt");
	for (int i = 0; i < ilePizz(); i++)
	{
		cout << pizza[i].nazwa << " " << pizza[i].cena << " " << pizza[i].opis << endl;
	}
	string wybor;
	char wybor2;
	double suma = 0;
	for (;;)
	{
		cout << "Podaj nazwe zamawianej pizzy : ";
		cin >> wybor;
		for (int j = 0; j < ilePizz(); j++)
		{
			if (wybor == pizza[j].nazwa)
			{
				zapis << pizza[j].nazwa << endl;
				suma = suma + pizza[j].cena;
				break;
			}
		}
		cout << "Czy chcesz zamownic cos jeszcze? t/n" << endl;
		cin >> wybor2;
		switch (wybor2)
		{
		case 't':
		{

		}
		break;
		case 'n':
		{
			cout << "Do jedzenia, uheueheuheueh!" << endl;
			Sleep(2000);
			zapis << suma << "zl";
			exit(0);
		}
		break;
		default:
			break;
		}

	}
}

int Pizza::ilePizz()
{
	return pizza.size();
}

void Pizza::zapisPizz(Pizza& dane, std::string s)
{
	ofstream zapis(s);
	for (int i = 0; i<ilePizz(); i++)
	{
		zapis << pizza[i].nazwa << " " << pizza[i].cena << " " << pizza[i].opis << endl;
	}
	zapis.close();
}
/////////////////TAJNE//////////////////
Skladnik::Skladnik() {};

Skladnik::Skladnik(string _nazwa, double _cena)
{
	nazwa = _nazwa;
	cena = _cena;
}

void Skladnik::wczytajSkladniki(string s)
{
	ifstream plik(s);
	string linie;
	while (getline(plik, linie))
	{
		stringstream wczyt(linie);
		double cena;
		string nazwa;
		wczyt >> nazwa;
		wczyt.ignore();
		wczyt >> cena;
		skladnik.push_back(Skladnik(nazwa, cena));
	}
	plik.close();
}

void Skladnik::zbudujPizze(string s)
{
	{
		ofstream zapis("rachunek.txt");
		for (int i = 0; i < ileSkladniki(); i++)
		{
			cout << skladnik[i].nazwa << " " << skladnik[i].cena << endl;
		}
		string wybor;
		char wybor2;
		double suma = 0;
		for (;;)
		{
			cout << "Podaj nazwe zamawianego skladnika : ";
			cin >> wybor;
			for (int j = 0; j < ileSkladniki(); j++)
			{
				if (wybor == skladnik[j].nazwa)
				{
					zapis << skladnik[j].nazwa << endl;
					suma = suma + skladnik[j].cena;
					break;
				}
			}
			cout << "Czy chcesz dodac cos jeszcze? t/n" << endl;
			cin >> wybor2;
			switch (wybor2)
			{
			case 't':
			{

			}
			break;
			case 'n':
			{
				cout << "Do jedzenia, uheueheuheueh!" << endl;
				Sleep(2000);
				zapis << suma << "zl";
				exit(0);
			}
			break;
			default:
				break;
			}

		}
	}
}

int Skladnik::ileSkladniki()
{
	return skladnik.size();
}