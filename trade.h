#pragma once
#include<iostream>
#include<string>
#include<vector>
using namespace std;
#include"account.h"
#include"keypad.h"
#include"screen.h"
bool checkisenough(int cash, int want);
class trade {
};
class Administrator :public trade {
public:
	void operation(screen& screen, keypad& keypad, ATMlist& historylist, int type, int& cash);
};
class Withdraw_money :public trade {
public:
	void operation(screen& screen, keypad& keypad, ATMlist& historylist, int type, int& cash,int i, Database_port&a,int id,int & money);
};
class Deposit :public trade {
public:
	void operation(screen& screen, keypad& keypad, ATMlist& historylist, int type, int& cash, int i, Database_port& a, int id, int& money);
};
class Transfer :public trade {
public:
	void operation(screen& screen, keypad& keypad, ATMlist& historylist, int type, int& cash, int i, Database_port& a, int id, int& money);
};
class checkinfo :public trade {
public:
	void operation(screen& screen, keypad& keypad, ATMlist& historylist, int type, int& cash, int i, Database_port& a, int id, int& money);
};
