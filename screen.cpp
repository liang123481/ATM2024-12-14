#pragma once
#include"screen.h"
void screen::printmenu() {
	cout << "                                                 1.Withdraw" << endl <<endl<< "                                                 2.Deposit       " << endl <<endl<< "                                                 3.Transfer       " << endl <<endl<< "                                                 4.check account information       "<<endl<<endl<<"                                                 5.exit      "<<endl<<endl;
}
void screen::print(string s) {
	cout << s << endl;
}
void screen::print(string name, int id, int money) {
	cout << "                                                 Name:" << name << endl << "                                                 ID:" << id << endl << "                                                 cash:" << money << endl;
}
void screen::print(int a,int b,int c,int d) {
	if (d == 0) {
		cout << "                                                 type:" << b << endl << "                                                 operid:" << c << endl << "                                                 money:" << a << endl;
	}
	else {
		cout << "                                                 type:" << b << endl<<c << "                                                 operid tran to id:" << d << endl << "                                                 money:" << a << endl;
	}
}
void screen::screen_clear() {
	Sleep(3000);
	system("cls");
}
void screen::clear_afterexit() {
	system("cls");
}
void screen::print(int cash) {
	cout << "                                                 cash:" << cash << endl;
}
