#pragma once
#include"trade.h"
bool checkisenough(int cash, int want) {
	if (cash >= want) {
		return true;
	}
	else {
		return false;
	}
}
void Administrator::operation(screen& screen, keypad& keypad, ATMlist& historylist, int type, int& cash) {
	while (type != 4) {
		screen.print("                              1.add cash   2.check history   3.check cash   4.exit");
		type = keypad.input_want();
		if (type == 1) {
			screen.print("                                                 input number?");
			int money = keypad.input_money();
			cash += money;
			screen.print("                                                 add successfully");
		}
		else if (type == 2) {
			for (auto it : historylist.list) {
				screen.print(it.money, it.type, it.firstID, it.toID);
			}
		}
		else if (type == 3) {
			screen.print(cash);
		}
		else {
			continue;
		}
		screen.screen_clear();
	}
}
void Deposit::operation(screen& screen, keypad& keypad, ATMlist& historylist, int type, int& cash,int i, Database_port&a,int id,int & money) {
	screen.print("                       How much money you want to deposit,or input -1 to return main menu.");
	 money = keypad.input_money();
	if (money == -1) {
		screen.clear_afterexit();
	}
	cash += money;
	a.accountlist[i].addmoney(money);
	a.modifyValueInLine("accountlist.txt", i, a.accountlist[i].money);
	history_ATM historytemp(money, type, 0, id);
	historylist.list.push_back(historytemp);
	screen.print("                          Deposit money successfully,thank you!");
}
void Withdraw_money::operation(screen& screen, keypad& keypad, ATMlist& historylist, int type, int& cash, int i, Database_port& a, int id, int& money) {
	bool temp = false;
	while (!temp) {
		screen.print("                     get how much money ?or input -1 to return main menu.");
		money = keypad.input_money();
		if (money == -1) {
			screen.clear_afterexit();
			break;
		}
		temp = a.check_money(id, money);
		if (!temp) {
			screen.print("               The account does not have sufficient balance,please re-enter it");
			screen.screen_clear();
		}
		else {
			temp = checkisenough(cash, money);
			if (!temp) {
				screen.print("                The ATM balance is insufficient,please re-enter it");
				screen.screen_clear();
			}
			else {
				cash -= money;
				a.accountlist[i].minusmoney(money);
				history_ATM historytemp(money, type, 0, id);
				historylist.list.push_back(historytemp);
				a.modifyValueInLine("accountlist.txt", i, a.accountlist[i].money);
				screen.print("                        The withdrawal of money was successful,thank you!");
			}
		}
	}
}
void Transfer::operation(screen& screen, keypad& keypad, ATMlist& historylist, int type, int& cash, int i, Database_port& a, int id, int& money) {
	bool temp = false;
	while (!temp) {
		int wantid;
		int j;
		screen.print("                           Which ID you want to transfer money to? or input -1 to return main menu.");
		keypad.input_ID(wantid);
		if (wantid == -1) {
			screen.clear_afterexit();
			break;
		}
		temp = a.check_id(wantid, j);
		if (!temp) {
			screen.print("                                If you don't have this ID, please re-enter it");
			screen.screen_clear();
			continue;
		}
		else {
			screen.print("                               How much money you want to transfer?");
			money = keypad.input_money();
			temp = a.check_money(id, money);
			if (!temp) {
				screen.print("                            The account does not have sufficient balance,please re-enter it");
				continue;
			}
			else {
				history_ATM historytemp(money, type, wantid, id);
				historylist.list.push_back(historytemp);
				a.accountlist[i].minusmoney(money);
				a.accountlist[j].addmoney(money);
				a.modifyValueInLine("accountlist.txt", i, a.accountlist[i].money);
				a.modifyValueInLine("accountlist.txt", j, a.accountlist[j].money);
				screen.print("                                            The transfer was successful, thank you!");
			}
		}
	}
}
void checkinfo::operation(screen& screen, keypad& keypad, ATMlist& historylist, int type, int& cash, int i, Database_port& a, int id, int& money) {
						string name;
					money = a.accountlist[i].money;
					name = a.accountlist[i].name;
					screen.print("                                         Your account-related information is:");
					screen.print(name, id, money);
}
