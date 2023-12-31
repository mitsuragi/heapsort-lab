#include "heap.h"

template heap<int>;
template heap<float>;
template heap<double>;

template<typename T>
bool heap<T>::isEmpty() const {
	return size == 0;
}

template<typename T>
size_t heap<T>::getSize() const {
	return size;
}

template<typename T>
T heap<T>::getMax() const {
	if (!isEmpty()) {
		return data[1];				// ��� ��� ��� ���������� maxHeap, 
	}								// �� �������������� ����� ������� ������� ����� ����� ������	 
	else {
		return 0;
	}
}

template<typename T>
void heap<T>::shiftUp(size_t i) {
	if (i > size) { // ���� ������ ������ ������� ����, �� ���������� �������, ��� ��� ���������� �� ����� ������� ����������
		return;
	}

	if (i == 1) { // ���� ������ ����� 1, �� ������, ��� ��� ����� ������� ������� � �� ����� �� ����� �����
		return;
	}

	if (data[i] > data[parent(i)]) {			// ���� ������� �� ������� ������ ������������� ��������
		swap(data[parent(i)], data[i]); // �� ��� �������� �������, ����� ���������� �������, ���� ������� ����� �� ����� �����
	} 
	else {
		return;
	}

	shiftUp(parent(i)); // ������� ���������� �����, ��� ����������� "�����������"
}

template<typename T>
void heap<T>::insert(T value) {
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

	if (leftChild(i) <= size && data[i] < data[leftChild(i)]) { // ���������, ���������� �� ����� �������� ������� � i-�� ��������
		swapId = leftChild(i);							// � ���� �� ����, �� ���������, ������ �� �� �������������
	}											// ���� ��� �����, �� ��������� ������ ��������� �������� � swapId

	if (rightChild(i) <= size && data[swapId] < data[rightChild(i)]) { // ���������, ���������� �� ������ �������� ������� � i-�� ��������
		swapId = rightChild(i);								 // � ���� �� ����, �� ���������, ������ �� �� �������������
	}												 // ���� ��� �����, �� ��������� ������ ��������� �������� � swapId

	if (swapId != i) {					  // ���� swapId, �� ����� ������������ �������
		swap(data[i], data[swapId]); // �� ������ ������� ��������� ������� � ��������� �� ������� swapId
		shiftDown(swapId);				  // � ���������� "����������" ���� ������� ������
	}

	return;
}

template<typename T>
T heap<T>::popMax() {
	T maxNum = data[1]; // ���������� ����� ������� ��������, ����� ������� ��� �����
	
	swap(data[1], data[size--]); // ������ ������� ����� ������� � ����� ��������� �������� � ��������� ������ �� 1
	data.pop_back(); // ������� ��������� �������� �� �������
	shiftDown(1); // "����������" ����, ����� �� ������������
	
	return maxNum;
}

template<typename T>
void heap<T>::makeHeap(vector<T> vec) {
	for (int i = 0; i < vec.size(); i++) {
		insert(vec[i]); // ���������� ��� �������� �� ������� � ����
	}
}

template<typename T>
vector<T> heap<T>::heapSort() {
	if (isEmpty()) return vector<T>(); // ��������� ���� �� �������

	vector<T> sorted;
	size_t size_ = size;				// ������� ���������� ��� �������� �������
	for (int i = 0; i < size_; i++) {	// ��� ��� ������� ������ ����� ����������� � �� �� ������� ��� ����
		sorted.push_back(popMax()); // ��������� ������������ ������� � ������
	}

	return sorted; // ���������� ��������������� ������
}