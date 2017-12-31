#ifndef Konta_H
#define Konta_H
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <fstream>

class Konta
{
public:
	std::vector<Konta> dane;
	std::string login, haslo, adres, telefon;
	Konta();
	Konta(std::string login1, std::string haslo1, std::string adres1, std::string telefon1);
	int iloscKont();
	void wczytKont(std::string s);
	void zapisKont(Konta& daneKonta, std::string nazwaPliku);
	void noweKonto(std::string nazwaPliku);
	int zaloguj();
};
#endif // !Konta_H