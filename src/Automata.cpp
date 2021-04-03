#include "Automata.h"
#include <iostream>
using namespace std;

Automata::Automata()
{
	menu = new string[5];
	prices = new int[5];
	cash = 0;
	menu[0] = "tea";
	menu[1] = "coffee";
	menu[2] = "water";
	menu[3] = "pepsi";
	menu[4] = "fanta";
	prices[0] = 10;
	prices[1] = 20;
	prices[2] = 30;
	prices[3] = 40;
	prices[4] = 50;
	Current_State = OFF;
}
void Automata::on()
{
	Current_State = WAIT;
	cash = 0;
}
void Automata::off()
{
	Current_State = OFF;
}
void Automata::coin(int Money)
{
	if (getState() == ACCEPT || getState() == WAIT)
	{
		if (getState() == WAIT)
			Current_State = ACCEPT;
		cash += Money;
	}
}
const string* Automata::etMenu()
{
	return menu;
}
States Automata::getState()
{
	return Current_State;
}
void Automata::choice(int _choice)
{
	if (getState() == ACCEPT)
	{
		Current_State = CHECK;
		if (check(_choice - 1) && (_choice < 6) && (_choice > 0))
		{
			cash -= prices[_choice - 1];
			cook();
		}
		else
			cancel();
	}
}
bool Automata::check(int _choice)
{
	if (getState() == CHECK)
	{
		if (cash - prices[_choice] >= 0)
			return true;
		else
			return false;
	}
}
int Automata::cancel()
{
	if (getState() == ACCEPT || getState() == CHECK)
	{
		Current_State = WAIT;
		int temp = cash;
		cash = 0;
		return temp;
	}
	else
		return 0;
}
void Automata::cook()
{
	if (getState() == CHECK)
	{
		Current_State = COOK;
		if (cash == 0)
			finish();
	}
}
int Automata::finish()
{
	if (getState() == COOK)
	{
		Current_State = WAIT;
		int temp = cash;
		cash = 0;
		return temp;
	}
}
Automata::~Automata()
{
	delete[] menu;
	delete[] prices;
}