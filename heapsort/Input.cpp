#include "Input.h"

#include <iostream>
#include <fstream>

using namespace std;

template<typename T>
T getInput()
{
	T userInput = 0;
	cin >> userInput;

	while (cin.fail()) {
		cout << "Некорректный ввод. Попробуйте снова." << endl;
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cin >> userInput;
	}
	cin.ignore(INT_MAX, '\n');
	return userInput;
}

int getInt()
{
	return getInput<int>();
}

bool getBool()
{
	return getInput<bool>();
}

int getPositiveInt()
{
	int userInput = 0;

	do {
		userInput = getInt();
		if (userInput <= 0) {
			cout << "Ошибка. Введите положительное число." << endl;
		}
	} while (userInput <= 0);
	return userInput;
}