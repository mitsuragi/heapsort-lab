#pragma once
#include <vector>

using namespace std;

template<typename T>
class heap {
	vector<T> data = { -1 };
	size_t size{};
	/// <summary>
	/// Ищет родителя выбранного дочернего элемента
	/// </summary>
	/// <param name="i">индекс дочернего элемента</param>
	/// <returns>индекс родительского элемента</returns>
	size_t parent(size_t i) { return i >> 1; };
	/// <summary>
	/// Ищет левый дочерний элемент выбранного родительского элемента
	/// </summary>
	/// <param name="i">индекс родительского элемента</param>
	/// <returns></returns>
	size_t leftChild(size_t i) { return i << 1; };
	/// <summary>
	/// Ищет правый дочерний элемент выбранного родительского элемента
	/// </summary>
	/// <param name="i"></param>
	/// <returns>индекс родительского элемента</returns>
	size_t rightChild(size_t i) { return (i << 1) + 1; };
public:
	/// <summary>
	/// Проверка на пустоту кучи
	/// </summary>
	/// <returns>true если пуста, false, если нет</returns>
	bool isEmpty() const;
	/// <summary>
	/// 
	/// </summary>
	/// <returns>Возвращает размер кучи</returns>
	size_t getSize() const;
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
