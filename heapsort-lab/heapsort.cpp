#include "Enum.h"
#include "Interface.h"
#include "Input.h"
#include "ForFIle.h"
#include "heap.h"
#include "Tests.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");

	showInfo();

	Test test;
	test.runTests();

	int choice = 0;
	int secondChoice = 0;
	int size = 0;

	vector<double> Array;
	string fileName = "";

	do {
		showMenu();
		cout << "Ваш выбор: ";
		choice = getInt();

		switch (choice) {
		case MENU_ITEM::ADD:
			showSecondMenu();
			cout << "Ваш выбор: ";
			secondChoice = getInt();

			switch (secondChoice) {
			case SECOND_MENU_ITEM::FILe:
				Array.clear();
				cout << "\nВведите название файла:" << endl;
				getline(cin, fileName);
				Array = uploadFromFile(fileName);
				cout << "Данные успешно загружены" << endl;
				break;

			case SECOND_MENU_ITEM::RANDOM:
				Array.clear();
				cout << "Введите количество элементов массива: " << endl;
				size = getPositiveInt();
				Array = getRandomArray(size);
				cout << "Массив успешно заполнен" << endl;
				break;

			case SECOND_MENU_ITEM::BACK:
				break;

			default:
				cout << "Неправильный ввод. Попробуйте снова." << endl;
				break;
			}
			break;

		case MENU_ITEM::SORT:
			if (!Array.empty()) {
				cout << "Начальный массив:" << endl;
				for (int i = 0; i < Array.size(); i++) {
					cout << Array[i] << " ";
				}

				heap<double> Heap;
				Heap.makeHeap(Array);
				Array = Heap.heapSort();

				cout << "\nОтсортированный масиив:" << endl;
				for (int i = 0; i < Array.size(); i++) {
					cout << Array[i] << " ";
				}
				cout << endl;
			}
			else {
				cout << "Нет данных" << endl << endl;
			}
			break;

		case MENU_ITEM::SAVE:
			if (!Array.empty()) {
				cout << "\nВведите название файла:" << endl;
				getline(cin, fileName);
				getFilePath(fileName);

				saveArray(Array, fileName);
				cout << "Начальная матрица сохранена" << endl;
			}
			else {
				cout << "Нет данных" << endl << endl;
			}
			break;

		case MENU_ITEM::QUIT:
			cout << "\nЗавершение работы программы.\n";
			break;

		default:
			cout << "Неправильный ввод. Попробуйте снова." << endl;
			break;
		}

	} while (choice != MENU_ITEM::QUIT);

	return EXIT_SUCCESS;
}