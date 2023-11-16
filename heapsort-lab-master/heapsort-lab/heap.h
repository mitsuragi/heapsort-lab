#pragma once
#include <vector>

using namespace std;

template<typename T>
class heap {
	vector<T> data = { -1 };
	size_t size{};
	size_t p(size_t i) { return i >> 1; }; // Ищет родителя выбранного дочернего элемента
	size_t l(size_t i) { return i << 1; }; // Ищет левый дочерний элемент выбранного родительского элемента
	size_t r(size_t i) { return (i << 1) + 1; }; // Ищет правый дочерний элемент выбранного родительского элемента
public:
	bool isEmpty() const { return size == 0; }; // Проверка на пустоту кучи
	size_t getSize() const { return size; }; // Возвращает размер кучи
	/// <summary>
	/// Возвращает самый большой элемент в куче
	/// </summary>
	/// <returns></returns>
	T getMax() const;

	/// <summary>
	/// Добавляет элемент в кучу
	/// </summary>
	/// <param name="value">Значение, которое нужно поместить в кучу</param>
	void insert(T value);
	/// <summary>
	/// "Просеивает" кучу снизу вверх, и ставит элемент на соответствующее ему место
	/// </summary>
	/// <param name="i">Индекс элемента, который нужно вставить на свое место</param>
	void shiftUp(size_t i);
	/// <summary>
	/// Возвращает самое большое значение и удаляет его из кучи
	/// </summary>
	/// <returns></returns>
	T popMax();
	/// <summary>
	/// "Просеивает" кучу сверху вниз, и ставит элемент на соответствующее ему место
	/// </summary>
	/// <param name="i">Индекс элемента, который нужно вставить на свое место</param>
	void shiftDown(size_t i);
	/// <summary>
	/// Создает кучу из вектора
	/// </summary>
	/// <param name="vector">Вектор</param>
	void makeHeap(vector<T> vector);
	/// <summary>
	/// Сортирует элементы в куче
	/// </summary>
	/// <returns>Отсортированный массив</returns>
	vector<T> heapSort();
};
