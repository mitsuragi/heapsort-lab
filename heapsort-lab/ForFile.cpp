#include "ForFile.h" // Подключение пользовательских заголовочных файлов
#include "Input.h"

using namespace filesystem; // Использование пространства имен для работы с файловой системой

vector<double> uploadFromFile(string fileName)
{
    string currentPath = filesystem::current_path().string() + "\\"; // Получение текущего пути
    string filePath = "";

    filePath = currentPath + fileName + ".txt"; // Формирование пути к файлу

    if (!ifstream(filePath)) // Проверка существования файла
    {
        cout << "Файл не существует." << endl;
    }

    error_code error_code;
    if (!filesystem::is_regular_file(filePath, error_code)) // Проверка файла на наличие недопустимых значений
    {
        cout << "Файл содержит недопустимые значения." << endl;
    }

    double element = 0;
    int n = 0;
    int count = 0;
    ifstream file(filePath); // Открытие файла для чтения
    file >> n; // Чтение размера массива из файла
    if (n < 0) {
        n = 0;
        cout << endl << "Файл не соответствует из-за количества элементов" << endl << endl;
    }

    vector<double> nullArray(1); // Создание массива с одним элементом, заполненным нулем
    for (int i = 0; i < 1; i++) {
        nullArray[i] = 0;
    }

    vector<double> loadedArray(n); // Создание массива для загруженных данных из файла
    for (int i = 0; i < n; i++) {
        if (file >> element) { // Загрузка данных из файла в массив
            loadedArray[i] = element;
            count++;
        }
    }
    if (count == n) {
        file.close(); // Закрытие файла после успешной загрузки данных
        return loadedArray;
    }
    else {
        cout << endl << "Файл не соответствует из-за элементов массива" << endl << endl;
        return nullArray; // Возврат массива с нулевым значением из-за ошибки загрузки данных
    }
}

void saveArray(vector<double>& Array, string fileName) {
    string currentPath = filesystem::current_path().string() + "\\"; // Получение текущего пути
    string filePath = "";

    filePath = currentPath + fileName + ".txt"; // Формирование пути к файлу
    ofstream file(filePath, ofstream::trunc); // Открытие файла для записи с очисткой содержимого
    size_t n = Array.size();
    file << n << endl; // Запись размера массива в файл
    for (int i = 0; i < n; i++) {
        file << Array[i] << ' '; // Запись элементов массива в файл
    }
    file.close(); // Закрытие файла после запис
}
bool getFilePath(string fileName) {     //путь файла для сохранения
    string currentPath = filesystem::current_path().string() + "\\"; // Получение текущего пути
    string filePath = "";

    filePath = currentPath + fileName + ".txt"; // Формирование пути к файлу
    bool ifFilePathCorrect = false;
    do {
        if (ifstream(filePath)) { // Проверка существования файла
            cout << "Файл уже существует. Вы хотите перезаписать его?" << endl << "0 - Нет" << endl << "1 - Да" << endl;
            cout << "Ваш выбор: ";
            if (!getBool()) { // Получение булевого значения от пользователя
                continue;
            }
            cout << endl;
        }
        ofstream file(filePath); // Открытие файла для записи
        error_code ec;
        if (!is_regular_file(filePath, ec)) { // Проверка адреса файла на наличие недопустимых значений
            cout << "Адрес содержит недопустимые значения. Повторно ввести." << endl;
            continue;
        }
        if (!file) { // Проверка возможности записи в файл
            cout << "Запись запрещена. Повторно ввести." << endl;
            file.close();
            continue;
        }
        file.close();
        ifFilePathCorrect = true;
    } while (!ifFilePathCorrect);
    return true;
}

vector<double> getRandomArray(int size) {
    vector<double> object(size); // Создание вектора заданного размера

    double element = 0;
    for (int i = 0; i < size; i++) {
        element = rand() % 1000 - 500; // Генерация случайного числа
        object[i] = 1.0 + (double)element / 10; // Присвоение случайного значения элементу вектора
    }
    return object; // Возврат сгенерированного вектора
}