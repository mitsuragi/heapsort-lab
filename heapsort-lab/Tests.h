#pragma once 

#include <iostream>

class Test {
public:
	/// <summary>
	/// ���� ����������
	/// </summary>
	/// <returns>True ���� ��� ������ �������, abort(), ���� �������� ������</returns>
	bool runTestOne();
	/// <summary>
	/// ���� �������� ������ �� �����
	/// </summary>
	/// <returns>True ���� ��� ������ �������, abort(), ���� �������� ������</returns>
	bool runTestTwo();
	/// <summary>
	/// ���� ���������� ������ � ����
	/// </summary>
	/// <returns>True ���� ��� ������ �������, abort(), ���� �������� ������</returns>
	bool runTestThree();

	void runTests();
};