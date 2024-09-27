#include <iostream>
#include "functions.hpp"
using namespace std;

int main()
{
    int SIZE;
    cout << "Введите N - порядок матрицы (N <= 100): ";
    cin >> SIZE;
    int **arr = new int* [SIZE];
    for (int i = 0; i < SIZE ; i++)
    {
        arr[i] = new int[SIZE];
    }
    MyNamespace::readArray(arr, SIZE);
    if (MyNamespace::MaxMinSum(arr, SIZE))
    {
        for (int i = 0; i < SIZE ; i++)
        {
            if (MyNamespace::EightInRow(arr[i], SIZE))
            {
                MyNamespace::SortArray(arr[i], SIZE);
            }
        }
    }
    MyNamespace::writeArray(arr, SIZE);
    delete[] arr;
}