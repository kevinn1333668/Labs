#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

namespace MyNamespace 
{

// Функция чтения данных

void readArray(int **arr, int size);

// Функция обработки данных

bool EightInNumber(int number);     // ПРОВЕРКА НА ЦИФРУ 8 В ЧИСЛЕ
void SortArray(int *arr,int SIZE);  // СОРТИРОВКА МАССИВА
bool MaxMin(int **arr, int SIZE);   // ПРОВЕРКА НА РАВНОСТЬ МАКСИМАЛЬНОГО И МИНИМАЛЬНОГО ЗНЧЕНИЯ НУЛЮ
bool EightInRow(int *arr, int SIZE);    // ПРОВЕРКА НА ЦИФРУ 8 В СТРОКЕ МАТРИЦЫ

// Функция записи данных

void writeArray(int **arr, int size);

}
#endif