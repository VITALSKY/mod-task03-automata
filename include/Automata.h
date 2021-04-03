#include <string>

using namespace std;
enum States
{
	OFF,
	WAIT,
	ACCEPT,
	CHECK,
	COOK
};

class Automata
{
private:
	int cash;
	string* menu;
	int* prices;
	States Current_State;
	bool check(int _choice);
	void cook();

public:
	Automata();
	~Automata();
	void on();
	void off();
	void coin(int Money);
	const string* etMenu();
	States getState();
	void choice(int _choice);
	int cancel();
	int finish();
};