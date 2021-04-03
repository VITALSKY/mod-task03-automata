#include <iostream>
#include "Automata.h"
#include<string>

using namespace std;

int main()
{
	Automata machine = Automata();

	machine.on();
	machine.coin(25);
	machine.coin(5);
	machine.coin(20);
	machine.choice(4);
	machine.off();

	return 0;
}