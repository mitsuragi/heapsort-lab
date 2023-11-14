#include "Tests.h"
#include "ForFile.h"
#include "heap.h"
#include <vector>
#include <algorithm>
#include <string>
#include <assert.h>

using namespace std;

bool Test::runTestOne() {
	std::string filename = "test1";
	heap<double> Heap;
	std::vector<double> vec = uploadFromFile(filename);
	std::vector<double> sortedVec = vec;
	Heap.makeHeap(vec);
	std::sort(sortedVec.begin(), sortedVec.end(), std::greater<>());
	assert(sortedVec == Heap.heapSort());
	return true;
}

bool Test::runTestTwo() {
	std::string filename = "test1";
	std::vector<double> vec = uploadFromFile(filename);
	std::vector<double> vec2 = { -44.9, -2.3, -15.6, 1, -32.1, 23.4, -1.2,-13.2,
									47.2, -2.6, 21.5, -34.5, -20.9, 33.7, 47.1 };
	assert(vec == vec2);
	return true;
}

bool Test::runTestThree() {
	std::string filename = "test3";
	std::vector<double> vec = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	saveArray(vec, filename);
	std::vector<double> vec2 = uploadFromFile(filename);
	std::remove(filename.c_str());
	assert(vec == vec2);
	return true;
}

void Test::runTests() {
	Test test;

	if (test.runTestOne() && test.runTestTwo() && test.runTestThree())
	{
		cout << "\nВсе модульные тесты пройдены!\n";
	}
	else
	{
		cout << "\nМодульные тесты не пройдены.\n" << std::endl;
	}
}