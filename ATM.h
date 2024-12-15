#pragma once
#include<iostream>
#include<string>
#include<vector>
using namespace std;
#include"account.h"
#include"keypad.h"
#include"screen.h"
#include"trade.h"
class ATM {
public:
	int cash;
	ATMlist historylist;
	screen screen;
	keypad keypad;
	ATM();
	void start(Database_port& a);
};
