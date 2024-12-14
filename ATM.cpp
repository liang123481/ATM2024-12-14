#pragma once
//需要加上一个需求就是如果不想进行这个操作了，可以直接退出。
#include"ATM.h"
bool checkisenough(int cash, int want) {
	if (cash >= want) {
		return true;
	}
	else {
		return false;
	}
}
ATM::ATM() {
	cash = 200;
}
void ATM::start() {
	a.getmessage();
	while (1) {
		int id = 0;
		int pin = 0;
		int i = 0;
		keypad.input_accandpin(id, pin,screen);
		if (id == 1145141919 && pin == 1919810) {//管理员操作
			int type = 0;
			while (type != 4) {
				screen.print("which oper choose:1.add cash   2.check history   3.check cash   4.exit");
				type = keypad.input_want();
				if (type == 1) {
					int money = keypad.input_money();
					cash += money;
					screen.print("add successfully");
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
		bool temp = a.check(id, pin, i);
		if (temp) {
			int type = 1;
			int money = 0;
			while (type != 5) {
				screen.printmenu();
				screen.print("Which mode of operation do you need?");
				type = keypad.input_want();
				switch (type) {
				case 1:
				{
					screen.print("How much money you want to deposit,or input -1 to return main menu.");
					money = keypad.input_money();
					if (money == -1) {
						screen.clear_afterexit();
						continue;
					}
					cash += money;
					a.accountlist[i].addmoney(money);
					a.modifyValueInLine("accountlist.txt", i, a.accountlist[i].money);
					history_ATM historytemp(money, type, 0, id);
					historylist.list.push_back(historytemp);
					screen.print("Deposit money successfully,thank you!");
					break;
				}
				case 2:
				{
					bool temp = false;
					bool jmp = false;
					while (!temp) {
						screen.print("get how much money ?or input -1 to return main menu.");
						money = keypad.input_money();
						if (money == -1) {
							jmp = true;
						}
						temp = a.check_money(id, money);
						if (!temp) {
							screen.print("The account does not have sufficient balance,please re-enter it");
							screen.screen_clear();
						}
						else {
							temp = checkisenough(cash, money);
							if (!temp) {
								screen.print("The ATM balance is insufficient,please re-enter it");
								screen.screen_clear();
							}
							else {
								cash -= money;
								a.accountlist[i].minusmoney(money);
								history_ATM historytemp(money, type, 0, id);
								historylist.list.push_back(historytemp);
								a.modifyValueInLine("accountlist.txt", i, a.accountlist[i].money);
								screen.print("The withdrawal of money was successful,thank you!");
							}
						}
						if (jmp) {
							screen.clear_afterexit();
							break;
						}
					}
					break;
				}
				case 3:
				{
					bool temp = false;
					while (!temp) {
						int wantid;
						int j;
						screen.print("Which ID you want to transfer money to? or input -1 to return main menu.");
						keypad.input_ID(wantid);
						if (wantid == -1) {
							screen.clear_afterexit();
							break;
						}
						temp = a.check_id(wantid, j);
						if (!temp) {
							screen.print("If you don't have this ID, please re-enter it");
							screen.screen_clear();
							continue;
						}
						else {
							screen.print("How much money you want to transfer?");
							money = keypad.input_money();
							temp = a.check_money(id, money);
							if (!temp) {
								screen.print("The account does not have sufficient balance,please re-enter it");
								continue;
							}
							else {
								history_ATM historytemp(money, type, wantid, id);
								historylist.list.push_back(historytemp);
								a.accountlist[i].minusmoney(money);
								a.accountlist[j].addmoney(money);
								a.modifyValueInLine("accountlist.txt", i, a.accountlist[i].money);
								a.modifyValueInLine("accountlist.txt", j, a.accountlist[j].money);
								screen.print("The transfer was successful, thank you!");
							}
						}
					}
					break;
				}
				case 4:
				{
					string name;
					money = a.accountlist[i].money;
					name = a.accountlist[i].name;
					screen.print("Your account-related information is:");
					screen.print(name, id, money);
					break;
				}
				case 5:
				{
					screen.print("End of operation,Thank you!");
					break;
				}
				default:
					break;
				}
				screen.screen_clear();
			}
		}
		else {
			screen.print("Your account or password is incorrect, please re-enter it");
			screen.screen_clear();
		}
	}
}


