#pragma once
#include<iostream>
#include<string>
#include<vector>
using namespace std;
#include"account.h"
#include"keypad.h"
#include"screen.h"
class ATM {
public:
	int cash;
	accountdatabase a;
	ATMlist historylist;
	screen screen;
	keypad keypad;
	ATM();
	void start();
};
bool checkisenough(int cash, int want);
