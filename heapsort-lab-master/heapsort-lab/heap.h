#pragma once
#include <vector>

using namespace std;

template<typename T>
class heap {
	vector<T> data = { -1 };
	size_t size{};
	size_t p(size_t i) { return i >> 1; }; // ���� �������� ���������� ��������� ��������
	size_t l(size_t i) { return i << 1; }; // ���� ����� �������� ������� ���������� ������������� ��������
	size_t r(size_t i) { return (i << 1) + 1; }; // ���� ������ �������� ������� ���������� ������������� ��������
public:
	bool isEmpty() const { return size == 0; }; // �������� �� ������� ����
	size_t getSize() const { return size; }; // ���������� ������ ����
	/// <summary>
	/// ���������� ����� ������� ������� � ����
	/// </summary>
	/// <returns></returns>
	T getMax() const;

	/// <summary>
	/// ��������� ������� � ����
	/// </summary>
	/// <param name="value">��������, ������� ����� ��������� � ����</param>
	void insert(T value);
	/// <summary>
	/// "����������" ���� ����� �����, � ������ ������� �� ��������������� ��� �����
	/// </summary>
	/// <param name="i">������ ��������, ������� ����� �������� �� ���� �����</param>
	void shiftUp(size_t i);
	/// <summary>
	/// ���������� ����� ������� �������� � ������� ��� �� ����
	/// </summary>
	/// <returns></returns>
	T popMax();
	/// <summary>
	/// "����������" ���� ������ ����, � ������ ������� �� ��������������� ��� �����
	/// </summary>
	/// <param name="i">������ ��������, ������� ����� �������� �� ���� �����</param>
	void shiftDown(size_t i);
	/// <summary>
	/// ������� ���� �� �������
	/// </summary>
	/// <param name="vector">������</param>
	void makeHeap(vector<T> vector);
	/// <summary>
	/// ��������� �������� � ����
	/// </summary>
	/// <returns>��������������� ������</returns>
	vector<T> heapSort();
};
