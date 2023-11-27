#include "ForFile.h" // ����������� ���������������� ������������ ������
#include "Input.h"

using namespace filesystem; // ������������� ������������ ���� ��� ������ � �������� ��������

vector<double> uploadFromFile(string fileName)
{
    string currentPath = filesystem::current_path().string() + "\\"; // ��������� �������� ����
    string filePath = currentPath + fileName + ".txt"; // ������������ ���� � �����

    if (!ifstream(filePath)) // �������� ������������� �����
    {
        cout << "���� �� ����������." << endl;
    }

    error_code error_code;

    if (!filesystem::is_regular_file(filePath, error_code)) // �������� ����� �� ������� ������������ ��������
    {
        cout << "���� �������� ������������ ��������." << endl;
    }

    double element = 0;
    int sizeArray = 0;
    int countElement = 0;

    ifstream file(filePath); // �������� ����� ��� ������
    file >> sizeArray; // ������ ������� ������� �� �����

    if (sizeArray < 0) {
        sizeArray = 0;
        cout << endl << "���� �� ������������� ��-�� ���������� ���������" << endl << endl;
    }

    vector<double> nullArray(1); // �������� ������� � ����� ���������, ����������� �����

    for (int i = 0; i < 1; i++) {
        nullArray[i] = 0;
    }

    vector<double> loadedArray(sizeArray); // �������� ������� ��� ����������� ������ �� �����

    for (int i = 0; i < sizeArray; i++) {
        if (file >> element) { // �������� ������ �� ����� � ������
            loadedArray[i] = element;
            countElement++;
        }
    }

    if (countElement == sizeArray) {
        file.close(); // �������� ����� ����� �������� �������� ������
        return loadedArray;
    }
    else {
        cout << endl << "���� �� ������������� ��-�� ��������� �������" << endl << endl;
        return nullArray; // ������� ������� � ������� ��������� ��-�� ������ �������� ������
    }
}

void saveArray(vector<double>& array, string fileName) {
    string currentPath = filesystem::current_path().string() + "\\"; // ��������� �������� ����
    string filePath = currentPath + fileName + ".txt"; // ������������ ���� � �����

    ofstream file(filePath, ofstream::trunc); // �������� ����� ��� ������ � �������� �����������

    size_t sizeArray = array.size();
    file << sizeArray << endl; // ������ ������� ������� � ����

    for (int i = 0; i < sizeArray; i++) {
        file << array[i] << ' '; // ������ ��������� ������� � ����
    }

    file.close(); // �������� ����� ����� �����
}

bool checkFilePath(string fileName) {     //���� ����� ��� ����������
    string currentPath = filesystem::current_path().string() + "\\"; // ��������� �������� ����
    string filePath = currentPath + fileName + ".txt"; // ������������ ���� � �����

    bool ifFilePathCorrect = false;

    do {
        if (ifstream(filePath)) { // �������� ������������� �����
            cout << "���� ��� ����������. �� ������ ������������ ���?" << endl << "0 - ���" << endl << "1 - ��" << endl;
            cout << "��� �����: ";

            if (!getBool()) { // ��������� �������� �������� �� ������������
                continue;
            }

            cout << endl;
        }

        ofstream file(filePath); // �������� ����� ��� ������
        error_code ec;

        if (!is_regular_file(filePath, ec)) { // �������� ������ ����� �� ������� ������������ ��������
            cout << "����� �������� ������������ ��������. �������� ������." << endl;
            return false;
        }

        if (!file) { // �������� ����������� ������ � ����
            cout << "������ ���������. �������� ������." << endl;
            file.close();
            return false;
        }

        file.close();
        ifFilePathCorrect = true;
    } while (!ifFilePathCorrect);

    return true;
}

vector<double> getRandomArray(int size) {
    vector<double> randomArray(size); // �������� ������� ��������� �������

    double element = 0;

    for (int i = 0; i < size; i++) {
        element = rand() % 1000 - 500; // ��������� ���������� �����
        randomArray[i] = (double)element / 10; // ���������� ���������� �������� �������� �������
    }

    return randomArray; // ������� ���������������� �������
}