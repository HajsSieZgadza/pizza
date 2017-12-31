#ifndef Menu_H
#define Menu_H
#include <iostream>

#include "Konta.h"
#include "Pizza.h"


class Menu
{
public:
	virtual void menu(Konta *x, Pizza *y, Skladnik *z, std::string s) = 0;
};


class Uzytkownik : public Menu
{
public:
	virtual void menu(Konta *x, Pizza *y, Skladnik *z, std::string s);

};


class Admin : public Menu
{
public:
	virtual void menu(Konta *x, Pizza *y, Skladnik *z, std::string s);
};


#endif // !Menu_H
