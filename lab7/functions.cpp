#include "functions.hpp"
#include <iostream>
#include <algorithm>
using namespace std;

namespace MyNamespace {

bool EightInNumber(int number) // ПРОВЕРКА НА ЦИФРУ 8 В ЧИСЛЕ 
{
    bool flag = false;
    int digit = 0;
    while (number != 0)
    {
        digit = number % 10;
        if (digit == 8)
        {
            flag = true;
        }
        number /= 10;
    }
    return flag;
}

bool EightInRow(int *arr, int SIZE)
{
    bool flag = false;
    for (int i = 0 ; i < SIZE ; i++)
    {
        if (EightInNumber(arr[i]))
        {
            flag = true;
        }
    }
    return flag;
}

void SortArray(int *arr, int SIZE) // СОРТИРОВКА МАССИВА ПУЗЫРЬКОМ
{
    bool flag = true;
    int temp, i = 0;
    while (flag && (i < SIZE))
    {
        flag = false;
        for (int j = 0 ; j < SIZE - 1 - i ; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j + 1];
                arr[j + 1] = arr[j]; 
                arr[j] = temp;
                flag = true;
            }
        }
        i++;
    }
}

bool MaxMin(int **arr, int SIZE) // СУММА МИНИМУМА И МАКСИМУМА
{
    bool flag = false;
    int mn = __INT_MAX__, mx = -2147483646;
    for (int i = 0; i < SIZE ; i++)
    {
        for (int j = 0; j < SIZE ; j++)
        {
            mx = max(arr[i][j], mx);
            mn = min(arr[i][j], mn);
        }
    }
    if ((mn + mx) == 0)
    {
        flag = true;
    }
    return flag;
}

void readArray(int **arr, int SIZE) // ВВОД МАССИВА
{
    int n;
    for (int i = 0 ; i < SIZE ; i++)
    {
        for (int j = 0 ; j < SIZE ; j++)
        {
            cout << "i = " << i << " " << "j = " << j << " : ";
            cin >> n;
            arr[i][j] = n;
        }
    }  
}

void writeArray(int **arr, int SIZE) // ВЫВОД МАССИВА
{
    for (int i = 0 ; i < SIZE ; i++)
    {
        for (int j = 0 ; j < SIZE ; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}



}
