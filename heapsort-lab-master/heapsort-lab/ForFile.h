#pragma once // Директива препроцессора для обеспечения однократного включения заголовочного файла

#include <fstream> // Включение заголовочного файла для работы с файлами
#include <string> // Включение заголовочного файла для работы со строками
#include <vector> // Включение заголовочного файла для работы с векторами
#include <memory> // Включение заголовочного файла для работы с умными указателями
#include <iostream> // Включение заголовочного файла для работы с потоками ввода-вывода
#include <filesystem> // Включение заголовочного файла для работы с файловой системой

using namespace std; // Использование стандартного пространства имен

/// <summary>
/// Функция считывания данных из файла
/// </summary>
/// <param name="fileName">Имя файла</param>
/// <returns>Считанный вектор</returns>
vector<double> uploadFromFile(string fileName); // Объявление функции для загрузки данных из файла

/// <summary>
/// Функция для сохранения массива в файл
/// </summary>
/// <param name="array">Массив данных</param>
/// <param name="fileName">Имя файла</param>
void saveArray(vector<double>& array, string fileName); // Объявление функции для сохранения массива в файл

/// <summary>
/// Функция получения полного пути файла
/// </summary>
/// <param name="fileName">Имя файла</param>
/// <returns>Возращает полный путь файла</returns>
bool getFilePath(string fileName); // Объявление функции для получения пути файла

/// <summary>
/// Функция для м=получения массив, состоящего из случайных значений
/// </summary>
/// <param name="size">Размер массива</param>
/// <returns>Возращет массив случайных значений</returns>
vector<double> getRandomArray(int size); // Объявление функции для создания случайного массива