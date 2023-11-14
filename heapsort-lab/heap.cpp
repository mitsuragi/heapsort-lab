#include "heap.h"

template heap<int>;
template heap<float>;
template heap<double>;

template<typename T>
T heap<T>::getMax() const {
	if (!isEmpty()) return data[1]; // ��� ��� ��� ���������� maxHeap, 								 
	else return 0;					// �� �������������� ����� ������� ������� ����� ����� ������
}

template<typename T>
void heap<T>::shiftUp(size_t i) {
	if (i > size) { // ���� ������ ������ ������� ����, �� ���������� �������, ��� ��� ���������� �� ����� ������� ����������
		return;
	}
	if (i == 1) { // ���� ������ ����� 1, �� ������, ��� ��� ����� ������� ������� � �� ����� �� ����� �����
		return;
	}
	if (data[i] > data[p(i)]) {			// ���� ������� �� ������� ������ ������������� ��������
		std::swap(data[p(i)], data[i]); // �� ��� �������� �������, ����� ���������� �������, ���� ������� ����� �� ����� �����
	} 
	else {
		return;
	}
	shiftUp(p(i)); // ������� ���������� �����, ��� ����������� "�����������"
}

template<typename T>
void heap<T>::insert(T value) {
	/*if (size + 1 >= data.size()) {
		data.push_back(0);
	}*/
	data.push_back(0); // ��������� ��������, ����� ����� �� ��� ����� ��������� �������
	data[++size] = value; // ����������� ������� �� ��������� �������, � ����� ����������� ������ ���� �� 1
	shiftUp(size); // ������ �� ������ ����� ������� � �������� size, �� ���� ������ ��� �����������
	return;
}

template<typename T>
void heap<T>::shiftDown(size_t i) {
	if (i > size) { // ���� ������ ������ ������� ����, �� ���������� �������, ��� ��� ���������� �� ����� ������� ����������
		return;
	}

	size_t swapId = i; 

	if (l(i) <= size && data[i] < data[l(i)]) { // ���������, ���������� �� ����� �������� ������� � i-�� ��������
		swapId = l(i);							// � ���� �� ����, �� ���������, ������ �� �� �������������
	}											// ���� ��� �����, �� ��������� ������ ��������� �������� � swapId

	if (r(i) <= size && data[swapId] < data[r(i)]) { // ���������, ���������� �� ������ �������� ������� � i-�� ��������
		swapId = r(i);								 // � ���� �� ����, �� ���������, ������ �� �� �������������
	}												 // ���� ��� �����, �� ��������� ������ ��������� �������� � swapId

	if (swapId != i) {					  // ���� swapId, �� ����� ������������ �������
		std::swap(data[i], data[swapId]); // �� ������ ������� ��������� ������� � ��������� �� ������� swapId
		shiftDown(swapId);				  // � ���������� "����������" ���� ������� ������
	}

	return;
}

template<typename T>
T heap<T>::popMax() {
	T maxNum = data[1]; // ���������� ����� ������� ��������, ����� ������� ��� �����
	std::swap(data[1], data[size--]); // ������ ������� ����� ������� � ����� ��������� �������� � ��������� ������ �� 1
	data.pop_back(); // ������� ��������� �������� �� �������
	shiftDown(1); // "����������" ����, ����� �� ������������
	return maxNum;
}

template<typename T>
void heap<T>::makeHeap(T array[], size_t n) {
	for (int i = 0; i < n; i++) {
		insert(array[i]); // ��������� ��� �������� �� ������� � ����
	}
}

template<typename T>
void heap<T>::makeHeap(std::vector<T> vec) {
	for (int i = 0; i < vec.size(); i++) {
		insert(vec[i]); // ���������� ��� �������� �� ������� � ����
	}
}

template<typename T>
std::vector<T> heap<T>::heapSort() {
	if (isEmpty()) return std::vector<T>(); // ��������� ���� �� �������

	std::vector<T> sorted;
	size_t size_ = size;				// ������� ���������� ��� �������� �������
	for (int i = 0; i < size_; i++) {	// ��� ��� ������� ������ ����� ����������� � �� �� ������� ��� ����
		sorted.push_back(popMax()); // ��������� ������������ ������� � ������
	}
	return sorted; // ���������� ��������������� ������
}