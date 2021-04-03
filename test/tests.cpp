#include <gtest/gtest.h>
#include "Automata.h"

TEST(task, test1)
{
	Automata machine = Automata();
	machine.on();
	machine.choice(1);
	int result = machine.getState();
	EXPECT_EQ(1, result);
}

TEST(task, test2) 
{
	Automata machine = Automata();
	States result = machine.getState();
	EXPECT_EQ(OFF, result);
}

TEST(task, test3) 
{
	Automata machine = Automata();
	machine.on();
	States result = machine.getState();
	EXPECT_EQ(WAIT, result);
}