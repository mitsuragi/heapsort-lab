#pragma once 

#include <iostream>

class Test {
public:
	/// <summary>
	/// Тест сортировки
	/// </summary>
	/// <returns>True если все прошло успешно, abort(), если возникла ошибка</returns>
	bool runTestOne();
	/// <summary>
	/// Тест выгрузки данных из файла
	/// </summary>
	/// <returns>True если все прошло успешно, abort(), если возникла ошибка</returns>
	bool runTestTwo();
	/// <summary>
	/// Тест сохранения данных в файл
	/// </summary>
	/// <returns>True если все прошло успешно, abort(), если возникла ошибка</returns>
	bool runTestThree();

	void runTests();
};