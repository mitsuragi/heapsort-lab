#pragma once
#include <vector>

using namespace std;

template<typename T>
class heap {
	vector<T> data = { -1 };
	size_t size{};
	/// <summary>
	/// ���� �������� ���������� ��������� ��������
	/// </summary>
	/// <param name="i">������ ��������� ��������</param>
	/// <returns>������ ������������� ��������</returns>
	size_t parent(size_t i) { return i >> 1; };
	/// <summary>
	/// ���� ����� �������� ������� ���������� ������������� ��������
	/// </summary>
	/// <param name="i">������ ������������� ��������</param>
	/// <returns></returns>
	size_t leftChild(size_t i) { return i << 1; };
	/// <summary>
	/// ���� ������ �������� ������� ���������� ������������� ��������
	/// </summary>
	/// <param name="i"></param>
	/// <returns>������ ������������� ��������</returns>
	size_t rightChild(size_t i) { return (i << 1) + 1; };
public:
	/// <summary>
	/// �������� �� ������� ����
	/// </summary>
	/// <returns>true ���� �����, false, ���� ���</returns>
	bool isEmpty() const;
	/// <summary>
	/// 
	/// </summary>
	/// <returns>���������� ������ ����</returns>
	size_t getSize() const;
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
