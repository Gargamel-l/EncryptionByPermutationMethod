#include <iostream>
#include <vector>
#include <locale>
#include <string>

using namespace std;

int main() {
    locale loc("ru_RU.UTF-8");
    locale::global(loc);
    setlocale(LC_ALL, "RUS");
    system("chcp 1251");

    int rows, cols;
    wstring text;


    wcout << L"Введите текст для шифрования: ";
    getline(wcin, text);

    wcout << L"Введите количество строк для матрицы: ";
    wcin >> rows;
    wcout << L"Введите количество столбцов для матрицы: ";
    wcin >> cols;

    wcin.ignore();

    // Убираем пробелы из введенного текста
    wstring filteredText = L"";
    for (wchar_t c : text) {
        if (c != L' ') {
            filteredText += c;
        }
    }


    // Проверяем, что количество ячеек в матрице не меньше количества букв в тексте
    if (rows * cols < filteredText.length()) {
        wcout << L"Ошибка: количество ячеек в матрице меньше количества букв в тексте";
        return 1;
    }

    // Создаем матрицу для шифрования
    vector<vector<wchar_t>> matrix(rows, vector<wchar_t>(cols, ' '));
    int index = 0;

    // Заполняем матрицу буквами из отфильтрованного текста
    for (int col = 0; col < cols; col++) {
        for (int row = 0; row < rows; row++) {
            if (index < filteredText.length()) {
                matrix[row][col] = filteredText[index];
                index++;
            }
        }
    }

    // Выводим зашифрованный текст по строкам
    wcout << L"Зашифрованный текст: ";
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            wcout << matrix[row][col];
        }
    }

    return 0;
}