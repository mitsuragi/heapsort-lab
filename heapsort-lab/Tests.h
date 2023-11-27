#pragma once 

#include <iostream>

class Test {
public:
	/// <summary>
	/// Тест сортировки
	/// </summary>
	/// <returns>True если все прошло успешно, abort(), если возникла ошибка</returns>
	bool runTestSort();

	/// <summary>
	/// Тест выгрузки данных из файла
	/// </summary>
	/// <returns>True если все прошло успешно, abort(), если возникла ошибка</returns>
	bool runTestUpload();

	/// <summary>
	/// Тест сохранения данных в файл
	/// </summary>
	/// <returns>True если все прошло успешно, abort(), если возникла ошибка</returns>
	bool runTestSave();

	/// <summary>
	/// Запуск всех модульных тестов
	/// </summary>
	void runAllTests();
};