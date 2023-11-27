#include "Heap.h"

template heap<int>;
template heap<float>;
template heap<double>;

template<typename T>
T heap<T>::getMax() const {
	if (!isEmpty()) return data[1]; // так как это реализация maxHeap, 								 
	else return 0;					// то соответственно самый большой элемент будет самым первым
}

template<typename T>
void heap<T>::shiftUp(size_t i) {
	if (i > size) { // Если индекс больше размера кучи, то происходит возврат, так как обратиться по этому индексу невозможно
		return;
	}

	if (i == 1) { // Если индекс равен 1, то значит, что это самый большой элемент и он стоит на своем месте
		return;
	}

	if (data[i] > data[parrentElement(i)]) {			// Если элемент по индексу больше родительского элемента
		swap(data[parrentElement(i)], data[i]); // то они меняются местами, иначе происходит возврат, ведь элемент стоит на своем месте
	} 
	else {
		return;
	}

	shiftUp(parrentElement(i)); // Функция вызывается снова, для продолжения "просеивания"
}

template<typename T>
void heap<T>::insert(T value) {
	data.push_back(0); // Добавляем значение, чтобы потом на это место поставить элемент
	data[++size] = value; // Подставляем элемент на последнюю позицию, и сразу увеличиваем размер кучи на 1
	shiftUp(size); // Ставим на нужное место элемент с индексом size, то есть только что добавленный
	return;
}

template<typename T>
void heap<T>::shiftDown(size_t i) {
	if (i > size) { // Если индекс больше размера кучи, то происходит возврат, так как обратиться по этому индексу невозможно
		return;
	}

	size_t swapId = i; 

	if (leftSubElement(i) <= size && data[i] < data[leftSubElement(i)]) { // Проверяем, существует ли левый дочерний элемент у i-го элемента
		swapId = leftSubElement(i);							// и если он есть, то проверяем, меньше ли он родительского
	}											// если все верно, то сохраняем индекс дочернего элемента в swapId

	if (rightSubElement(i) <= size && data[swapId] < data[rightSubElement(i)]) { // Проверяем, существует ли правый дочерний элемент у i-го элемента
		swapId = rightSubElement(i);								 // и если он есть, то проверяем, меньше ли он родительского
	}												 // если все верно, то сохраняем индекс дочернего элемента в swapId

	if (swapId != i) {					  // Если swapId, не равен изначальному индексу
		swap(data[i], data[swapId]); // то меняем местами начальный элемент с элементом по индексу swapId
		shiftDown(swapId);				  // и продолжаем "просеивать" этот элемент дальше
	}

	return;
}

template<typename T>
T heap<T>::popMax() {
	T maxNum = data[1]; // Записываем самое большое значение, чтобы вернуть его потом
	
	swap(data[1], data[size--]); // Меняем местами самое большое и самое маленькое значения и уменьшаем размер на 1
	data.pop_back(); // Удаляем последнее значение из массива
	shiftDown(1); // "Просеиваем" кучу, чтобы ее восстановить
	
	return maxNum;
}

template<typename T>
void heap<T>::makeHeap(vector<T> vec) {
	for (int i = 0; i < vec.size(); i++) {
		insert(vec[i]); // Вствавляем все значения из вектора в кучу
	}
}

template<typename T>
vector<T> heap<T>::heapSort() {
	if (isEmpty()) return vector<T>(); // Проверяем кучу на пустоту

	vector<T> sorted;
	size_t size_ = size;				// Создаем переменную для хранения размера
	for (int i = 0; i < size_; i++) {	// так как обычный размер будет уменьшаться и мы не пройдем всю кучу
		sorted.push_back(popMax()); // Добавляем максимальный элемент в массив
	}

	return sorted; // Возвращаем отсортированный массив
}