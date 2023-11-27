#pragma once 

#include <iostream>

class Test {
public:
	/// <summary>
	/// ���� ����������
	/// </summary>
	/// <returns>True ���� ��� ������ �������, abort(), ���� �������� ������</returns>
	bool runTestSort();

	/// <summary>
	/// ���� �������� ������ �� �����
	/// </summary>
	/// <returns>True ���� ��� ������ �������, abort(), ���� �������� ������</returns>
	bool runTestUpload();

	/// <summary>
	/// ���� ���������� ������ � ����
	/// </summary>
	/// <returns>True ���� ��� ������ �������, abort(), ���� �������� ������</returns>
	bool runTestSave();

	/// <summary>
	/// ������ ���� ��������� ������
	/// </summary>
	void runAllTests();
};