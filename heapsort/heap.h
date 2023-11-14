#pragma once
#include <vector>

template<typename T>
class heap {
	std::vector<T> data = { -1 };
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
	/// <param name="array">������</param>
	/// <param name="n">������ �������</param>
	void makeHeap(T array[], size_t n);
	/// <summary>
	/// ������� ���� �� �������
	/// </summary>
	/// <param name="vec">������</param>
	void makeHeap(std::vector<T> vec);
	/// <summary>
	/// ��������� �������� � ����
	/// </summary>
	/// <returns>��������������� ������</returns>
	std::vector<T> heapSort();
};
