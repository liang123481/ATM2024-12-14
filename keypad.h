#pragma once
#include<iostream>
#include<string>
#include<vector>
#include"screen.h"
using namespace std;
class keypad {
public:
	void input_accandpin(int& id, int& pin,screen &screen);
	int input_want();
	int input_money();
	void input_ID(int& ID);
};
