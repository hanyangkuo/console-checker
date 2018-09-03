#include <conio.h>
#include <iostream>
#include <Windows.h>
#include <string>

#define LEFT 75
#define RIGHT 77
using namespace std;

unsigned int color_y = 0 | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE;
unsigned int color_n = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;

// show the question and allow user to use arrow key to choose yes or no and return the bool
bool check(const string &qes) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_n);
	cout << qes;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_y);
	cout << "Yes";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_n);
	cout << "/No";
	bool flag = true;

	while (1) {
		if (_kbhit()) {
			int key_fist = _getch();
			if (key_fist == 224) {
				int key_second = _getch();
				if (key_second == LEFT) {
					cout << "\r" << qes;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_y);
					cout << "Yes";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_n);
					cout << "/No";
					flag = 1;
				}
				else if (key_second == RIGHT) {
					cout << "\r" << qes;
					cout << "Yes/";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_y);
					cout << "No";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_n);
					flag = 0;
				}
			}
			else if (key_fist == 13) {
				cout << endl;
				return (flag);
			}
			Sleep(33);
		}
	}
}
