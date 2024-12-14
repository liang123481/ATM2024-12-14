#pragma once
#include<iostream>
#include<string>
#include<vector>
using namespace std;
class history {
public:
	int money;
	int type;
	int toID;
};
class history_ATM :public history {
public:
	history_ATM(int money, int type, int toid, int firstid);
	int firstID;
};
class ATMlist {
public:
	vector<history_ATM>list;
};
class accounthistory {
	vector<history>list;
};
