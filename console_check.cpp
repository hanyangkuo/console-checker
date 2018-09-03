#include <conio.h>
#include <iostream>

using namespace std;

bool check(const string &qes) {
	unsigned int color_y = 0 | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE;
	unsigned int color_n = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
	bool flag = true;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_n);
	cout << qes;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_y);
	cout << "Yes";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_n);
	cout << "/No";
	getchar();
	while (1) {
		if (GetKeyState(VK_LEFT)<0 && kbhit()) {
			flag = true;
			cout << "\r" << qes;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_y);
			cout << "Yes";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_n);
			cout << "/No";
		}
		else if (GetKeyState(VK_RIGHT)<0 && kbhit()) {
			flag = false;
			cout << "\r" << qes;
			cout << "Yes/";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_y);
			cout << "No";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_n);
		}
		else if (GetKeyState(VK_RETURN) < 0 && kbhit()) {
			return flag;
		}
		Sleep(33);
		//GetAsyncKeyState  / GetKeyState
	}

}