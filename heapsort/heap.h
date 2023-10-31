#pragma once
#include <vector>

template<typename T>
class heap {
	std::vector<T> data = { -1 };
	size_t size{};
	size_t p(size_t i) { return i >> 1; };
	size_t l(size_t i) { return i << 1; };
	size_t r(size_t i) { return (i << 1) + 1; };
public:
	bool isEmpty() const { return size == 0; };
	size_t getSize() const { return size; };
	T getMax() const;
	void insert(T value);
	void shiftUp(size_t i);
	T extractMax();
	void shiftDown(size_t i);
	void heapify();
	void makeHeap(T array[], size_t n);
	void makeHeap(std::vector<T> vec);
	std::vector<T> heapSort();
};
