#pragma once
#include<iostream>
#include<string>
#include<vector>
#include <fstream>
#include <sstream>
#include"history.h"
using namespace std;
class account {
public:
	int money;
	int ID;
	int pin;
	string name;
	void addmoney(int add);
	void minusmoney(int minus);
};
class Database_port {
public:
	vector<account>accountlist;
	bool check_id(int id, int& k);
	bool check_money(int id, int yuer);
	bool check(int id, int pin, int& k);
	void getmessage();
	void addmessage(int k,int money,int type,int i);
	void modifyValueInLine(const string& filename, int lineToModify, int newValue);
	void writeFile(const string& filename, const vector<string>& lines);
	void readFile(const string& filename, vector<string>& lines);
};
