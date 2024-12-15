#pragma once
#include"ATM.h"
ATM::ATM() {
	cash = 200;
}
void ATM::start(Database_port& a) {
	a.getmessage();//与数据库建立连接
	while (1) {
		int id = 0;
		int pin = 0;
		int i = 0;
		keypad.input_accandpin(id, pin,screen);
		if (id == 1145141919 && pin == 1919810) {//管理员操作
			int type = 0;
			Administrator temp;
			temp.operation(screen, keypad, historylist, type, cash);
		}
		bool temp = a.check(id, pin, i);
		if (temp) {
			screen.clear_afterexit();
			int type = 1;
			int money = 0;
			while (type != 5) {
				screen.printmenu();
				screen.print("                                                 Which mode of operation do you need?");
				type = keypad.input_want();
				switch (type) {
				case 1:
				{
					Withdraw_money temp;
					temp.operation(screen, keypad, historylist, type, cash, i, a, id, money);
					break;
				}
				case 2:
				{
					Deposit temp;
					temp.operation(screen, keypad, historylist, type, cash, i, a, id, money);
					break;
				}
				case 3:
				{
					Transfer temp;
					temp.operation(screen, keypad, historylist, type, cash, i, a, id, money);
					break;
				}
				case 4:
				{
					checkinfo temp;
					temp.operation(screen, keypad, historylist, type, cash, i, a, id, money);
					break;
				}
				case 5:
				{
					screen.print("                                                 End of operation,Thank you!");
					break;
				}
				default:
					break;
				}
				screen.screen_clear();
			}
		}
		else {
			screen.print("                                  Your account or password is incorrect, please re-enter it");
			screen.screen_clear();
		}
	}
}


