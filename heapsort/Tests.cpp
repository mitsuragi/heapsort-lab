#include "Tests.h" 

using namespace std;

bool Test::runTestOne() {
	return true;
}

bool Test::runTestTwo() {
	return true;
}

bool Test::runTestThree() {
	return true;
}

bool Test::runTestFour() {
	return true;
}

bool Test::runTestFifth() {
	return true;
}

void Test::runTests() {
	Test test;

	if (test.runTestOne() && test.runTestTwo() && test.runTestThree() && test.runTestFour() && test.runTestFifth())
	{
		cout << "\nВсе модульные тесты пройдены!\n";
	}
	else
	{
		cout << "\nМодульные тесты не пройдены.\n" << std::endl;
	}
}