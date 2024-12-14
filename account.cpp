#pragma once
#include"account.h"
using namespace std;
void account::addmoney(int add) {
	money += add;
}
void account::minusmoney(int minus) {
	money -= minus;
}
bool accountdatabase::check_id(int id, int& k) {
	//查找list有没有这个人
	int i = 0, j = accountlist.size() - 1;
	while (i <= j) {
		int mid = (i + j) / 2;
		if (accountlist[mid].ID < id) {
			i = mid + 1;
		}
		else if (accountlist[mid].ID > id) {
			j = mid - 1;
		}
		else {
			k = mid;
			return true;
		}
	}
	return false;
}
bool accountdatabase::check_money(int id, int yuer) {
	int i = 0, j = accountlist.size() - 1;
	while (i <= j) {
		int mid = (i + j) / 2;
		if (accountlist[mid].ID < id) {
			i = mid + 1;
		}
		else if (accountlist[mid].ID > id) {
			j = mid - 1;
		}
		else {
			if (accountlist[mid].money >= yuer) {
				return true;
			}
			return false;
		}
	}
	return false;
	//查找有没有这个id和钱数
}
bool accountdatabase::check(int id, int pin, int& k) {
	int i = 0, j = accountlist.size() - 1;
	while (i <= j) {
		int mid = (i + j) / 2;
		if (accountlist[mid].ID < id) {
			i = mid + 1;
		}
		else if (accountlist[mid].ID > id) {
			j = mid - 1;
		}
		else {
			if (accountlist[mid].pin == pin) {
				k = mid;
				return true;
			}
			return false;
		}
	}
	return false;
	//检测账号密码是否正确
}
void accountdatabase::getmessage() {
	ifstream file("accountlist.txt"); // 指定文件名
	if (!file.is_open()) {
		cerr << "error" << endl;
		return;
	}

	string line;
	while (getline(file, line)) {
		stringstream ss(line);
		account acc; // 创建一个新的 account 对象

		// 读取数据
		if (ss >> acc.name >> acc.ID >> acc.pin >> acc.money) {
			// 假设 list 的数据在这一行的最后，使用剩余数据构造 accounthistory 对象
			string historyData;
			getline(ss, historyData); // 读取剩余的历史数据

			// 使用 historyData 初始化 acc.list
			//acc.list = accounthistory(historyData); // 根据需要修改构造函数

			accountlist.push_back(acc); // 将新的 account 追加到列表中
		}
		else {
			cerr << "读取文件时出错，可能是数据格式不正确：" << line << endl;
		}
	}

	file.close();
}
void accountdatabase::addmessage(int k, int money, int type,int i) {
	if (type == 1) {
		modifyValueInLine("accountlist.txt", k, accountlist[k].money);
	}
	else if (type == 2) {
		modifyValueInLine("accountlist.txt", k, accountlist[k].money);
	}
	else {
		modifyValueInLine("accountlist.txt", k, accountlist[k].money);
		modifyValueInLine("accountlist.txt", i, accountlist[i].money);
	}
}
void accountdatabase::modifyValueInLine(const string& filename, int lineToModify, int newValue)
{
	vector<string> lines;
	readFile(filename, lines);

	// 修改指定行的最后一个数字
	if (lineToModify >= 0 && lineToModify < lines.size()) {
		istringstream ss(lines[lineToModify]);
		string word;
		vector<string> words;

		// 将行分割成单词
		while (ss >> word) {
			words.push_back(word);
		}

		// 修改指定的单词（最后一个单词）
		if (!words.empty()) {
			words.back() = to_string(newValue);
		}

		// 重新组合成一行
		ostringstream modifiedLine;
		for (size_t i = 0; i < words.size(); ++i) {
			modifiedLine << words[i];
			if (i < words.size() - 1) {
				modifiedLine << " "; // 添加空格
			}
		}

		lines[lineToModify] = modifiedLine.str(); // 更新行

		// 将修改后的内容写回文件
		writeFile(filename, lines);
	}
	else {
		cerr << "行号超出范围" << endl;
	}
}
void accountdatabase::writeFile(const string& filename, const vector<string>& lines)
{
	ofstream outputFile(filename);
	if (!outputFile) {
		cerr << "无法打开文件: " << filename << endl;
		return;
	}
	for (const string& line : lines) {
		outputFile << line << endl;
	}
	outputFile.close();
}
void accountdatabase::readFile(const string& filename, vector<string>& lines) {
	ifstream inputFile(filename);
	if (!inputFile) {
		cerr << "无法打开文件: " << filename << endl;
		return;
	}
	string line;
	while (getline(inputFile, line)) {
		lines.push_back(line);
	}
	inputFile.close();
}
