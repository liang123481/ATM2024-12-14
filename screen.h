#pragma once
#include<iostream>
#include<string>
#include<vector>
#include <cstdlib> 
#include <windows.h>
using namespace std;
class screen {
public:
	void printmenu();
	void print(string s);
	void print(int cash);
	void print(string name, int id, int money);
	void screen_clear();
	void clear_afterexit();
	void print(int a, int b, int c, int d);
};
