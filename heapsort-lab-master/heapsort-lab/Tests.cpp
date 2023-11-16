#include "Tests.h"
#include "ForFile.h"
#include "heap.h"
#include <vector>
#include <algorithm>
#include <string>
#include <assert.h>

using namespace std;

bool Test::runTestSort() {
	string fileName = "test1";
	heap<double> heap;
	vector<double> vec = uploadFromFile(fileName);
	vector<double> sortedVector = vec;
	heap.makeHeap(vec);
	sort(sortedVector.begin(), sortedVector.end(), greater<>());
	assert(sortedVector == heap.heapSort());
	return true;
}

bool Test::runTestUpload() {
	string fileName = "test1";
	vector<double> vec = uploadFromFile(fileName);
	vector<double> resultVector = { -44.9, -2.3, -15.6, 1, -32.1, 23.4, -1.2,-13.2,
									47.2, -2.6, 21.5, -34.5, -20.9, 33.7, 47.1 };
	assert(vec == resultVector);
	return true;
}

bool Test::runTestSave() {
	string fileName = "test3";
	vector<double> vec = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	saveArray(vec, fileName);
	vector<double> resultVector = uploadFromFile(fileName);
	remove(fileName.c_str());
	assert(vec == resultVector);
	return true;
}

void Test::runTests() {
	Test test;

	if (test.runTestSort() && test.runTestUpload() && test.runTestSave())
	{
		cout << "\nВсе модульные тесты пройдены!\n";
	}
	else
	{
		cout << "\nМодульные тесты не пройдены.\n" << endl;
	}
}