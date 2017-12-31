#ifndef Pizza_H
#define Pizza_H
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

class Pizza
{
public:
	std::vector<Pizza> pizza;
	Pizza();
	std::string nazwa, opis;
	double cena;
	Pizza(std::string _x, double _y, std::string _z);
	void wczytajMenu(std::string menu);
	void wyswietlMenu();
	void dodajPizze();
	int ilePizz();
	void zapisPizz(Pizza& dane, std::string s);
};
//////////////TAJNE//////////////////
class Skladnik
{
public:
	Skladnik();
	std::string nazwa;
	double cena;
	std::vector <Skladnik> skladnik;
	Skladnik(std::string _nazwa, double _cena);
	void wczytajSkladniki(std::string s);
	void zbudujPizze(std::string s);
	int ileSkladniki();
};
#endif

