#include "ForFile.h" // ����������� ���������������� ������������ ������
#include "Input.h"

using namespace filesystem; // ������������� ������������ ���� ��� ������ � �������� ��������

vector<double> uploadFromFile(string fileName)
{
    string currentPath = filesystem::current_path().string() + "\\"; // ��������� �������� ����
    string filePath = "";

    filePath = currentPath + fileName + ".txt"; // ������������ ���� � �����

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
    int n = 0;
    int count = 0;
    ifstream file(filePath); // �������� ����� ��� ������
    file >> n; // ������ ������� ������� �� �����
    if (n < 0) {
        n = 0;
        cout << endl << "���� �� ������������� ��-�� ���������� ���������" << endl << endl;
    }

    vector<double> nullArray(1); // �������� ������� � ����� ���������, ����������� �����
    for (int i = 0; i < 1; i++) {
        nullArray[i] = 0;
    }

    vector<double> loadedArray(n); // �������� ������� ��� ����������� ������ �� �����
    for (int i = 0; i < n; i++) {
        if (file >> element) { // �������� ������ �� ����� � ������
            loadedArray[i] = element;
            count++;
        }
    }
    if (count == n) {
        file.close(); // �������� ����� ����� �������� �������� ������
        return loadedArray;
    }
    else {
        cout << endl << "���� �� ������������� ��-�� ��������� �������" << endl << endl;
        return nullArray; // ������� ������� � ������� ��������� ��-�� ������ �������� ������
    }
}

void saveArray(vector<double>& Array, string fileName) {
    string currentPath = filesystem::current_path().string() + "\\"; // ��������� �������� ����
    string filePath = "";

    filePath = currentPath + fileName + ".txt"; // ������������ ���� � �����
    ofstream file(filePath, ofstream::trunc); // �������� ����� ��� ������ � �������� �����������
    size_t n = Array.size();
    file << n << endl; // ������ ������� ������� � ����
    for (int i = 0; i < n; i++) {
        file << Array[i] << ' '; // ������ ��������� ������� � ����
    }
    file.close(); // �������� ����� ����� �����
}
bool getFilePath(string fileName) {     //���� ����� ��� ����������
    string currentPath = filesystem::current_path().string() + "\\"; // ��������� �������� ����
    string filePath = "";

    filePath = currentPath + fileName + ".txt"; // ������������ ���� � �����
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
            continue;
        }
        if (!file) { // �������� ����������� ������ � ����
            cout << "������ ���������. �������� ������." << endl;
            file.close();
            continue;
        }
        file.close();
        ifFilePathCorrect = true;
    } while (!ifFilePathCorrect);
    return true;
}

vector<double> getRandomArray(int size) {
    vector<double> object(size); // �������� ������� ��������� �������

    double element = 0;
    for (int i = 0; i < size; i++) {
        element = rand() % 1000 - 500; // ��������� ���������� �����
        object[i] = 1.0 + (double)element / 10; // ���������� ���������� �������� �������� �������
    }
    return object; // ������� ���������������� �������
}