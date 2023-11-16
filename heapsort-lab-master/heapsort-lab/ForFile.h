#pragma once // ��������� ������������� ��� ����������� ������������ ��������� ������������� �����

#include <fstream> // ��������� ������������� ����� ��� ������ � �������
#include <string> // ��������� ������������� ����� ��� ������ �� ��������
#include <vector> // ��������� ������������� ����� ��� ������ � ���������
#include <memory> // ��������� ������������� ����� ��� ������ � ������ �����������
#include <iostream> // ��������� ������������� ����� ��� ������ � �������� �����-������
#include <filesystem> // ��������� ������������� ����� ��� ������ � �������� ��������

using namespace std; // ������������� ������������ ������������ ����

/// <summary>
/// ������� ���������� ������ �� �����
/// </summary>
/// <param name="fileName">��� �����</param>
/// <returns>��������� ������</returns>
vector<double> uploadFromFile(string fileName); // ���������� ������� ��� �������� ������ �� �����

/// <summary>
/// ������� ��� ���������� ������� � ����
/// </summary>
/// <param name="array">������ ������</param>
/// <param name="fileName">��� �����</param>
void saveArray(vector<double>& array, string fileName); // ���������� ������� ��� ���������� ������� � ����

/// <summary>
/// ������� ��������� ������� ���� �����
/// </summary>
/// <param name="fileName">��� �����</param>
/// <returns>��������� ������ ���� �����</returns>
bool getFilePath(string fileName); // ���������� ������� ��� ��������� ���� �����

/// <summary>
/// ������� ��� �=��������� ������, ���������� �� ��������� ��������
/// </summary>
/// <param name="size">������ �������</param>
/// <returns>�������� ������ ��������� ��������</returns>
vector<double> getRandomArray(int size); // ���������� ������� ��� �������� ���������� �������