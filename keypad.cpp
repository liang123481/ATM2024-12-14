#pragma once
#include"keypad.h"
void keypad::input_accandpin(int& id, int& pin,screen& screen) {
	int i = 0;
	screen.print("input ID:");
	cin >> id;
	screen.print("input pin:");
	cin >> pin;
}
int keypad::input_want() {
	int type = 0;
	cin >> type;
	return type;
}
int keypad::input_money() {
	int money;
	cin >> money;
	return money;
}
void keypad:: input_ID(int& ID) {
	cin >> ID;
}
