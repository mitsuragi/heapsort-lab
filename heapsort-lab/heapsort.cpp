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
		cout << "��� �����: ";
		choice = getInt();

		switch (choice) {
		case MENU_ITEM::ADD:
			showSecondMenu();
			cout << "��� �����: ";
			secondChoice = getInt();

			switch (secondChoice) {
			case SECOND_MENU_ITEM::FILe:
				Array.clear();
				cout << "\n������� �������� �����:" << endl;
				getline(cin, fileName);
				Array = uploadFromFile(fileName);
				cout << "������ ������� ���������" << endl;
				break;

			case SECOND_MENU_ITEM::RANDOM:
				Array.clear();
				cout << "������� ���������� ��������� �������: " << endl;
				size = getPositiveInt();
				Array = getRandomArray(size);
				cout << "������ ������� ��������" << endl;
				break;

			case SECOND_MENU_ITEM::BACK:
				break;

			default:
				cout << "������������ ����. ���������� �����." << endl;
				break;
			}
			break;

		case MENU_ITEM::SORT:
			if (!Array.empty()) {
				cout << "��������� ������:" << endl;
				for (int i = 0; i < Array.size(); i++) {
					cout << Array[i] << " ";
				}

				heap<double> Heap;
				Heap.makeHeap(Array);
				Array = Heap.heapSort();

				cout << "\n��������������� ������:" << endl;
				for (int i = 0; i < Array.size(); i++) {
					cout << Array[i] << " ";
				}
				cout << endl;
			}
			else {
				cout << "��� ������" << endl << endl;
			}
			break;

		case MENU_ITEM::SAVE:
			if (!Array.empty()) {
				cout << "\n������� �������� �����:" << endl;
				getline(cin, fileName);
				getFilePath(fileName);

				saveArray(Array, fileName);
				cout << "��������� ������� ���������" << endl;
			}
			else {
				cout << "��� ������" << endl << endl;
			}
			break;

		case MENU_ITEM::QUIT:
			cout << "\n���������� ������ ���������.\n";
			break;

		default:
			cout << "������������ ����. ���������� �����." << endl;
			break;
		}

	} while (choice != MENU_ITEM::QUIT);

	return EXIT_SUCCESS;
}