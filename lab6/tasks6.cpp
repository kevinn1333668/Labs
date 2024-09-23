#include <iostream>
#include <ctime>
using namespace std;


// ФУНКЦИИ ДЛЯ ЗАДАНИЙ

int FirstDigit(int number) // ВОЗВРАЩАЕТ ПЕРВУЮ ЦИФРУ ЧИСЛА
{
    int x;
    while(number != 0) {
        x = number % 10;
        number /= 10;
    }
    return x;
}

void sort2(int arr[], int arrMulti[], int const SIZE) // СОРТИРОВКА МАССИВОВ ПУЗЫРЬКОМ ДЛЯ 2 ЗАДАНИЯ!!!
{
    for (int i = 0 ; i < (SIZE - 1) ; i++)
    {
        for (int j = 0; j < SIZE - 1 - i ; j++)
        {
            if (arrMulti[j] > arrMulti[j + 1])  // сортировка по произведению цифр чисел
            {
                swap(arr[j], arr[j + 1]);
                swap(arrMulti[j], arrMulti[j + 1]);
            }
            else if ((arrMulti[j] == arrMulti[j + 1])) 
            {
                if ((FirstDigit(arr[j]) % 10) > (FirstDigit(arr[j + 1]) % 10)) // сортировка по первой цифре числа
                {
                    swap(arr[j], arr[j + 1]);
                }
                else if ((FirstDigit(arr[j]) % 10) == (FirstDigit(arr[j + 1]) % 10))
                {
                    if (arr[j] > arr[j + 1]) // сортировка по самим числам
                    {
                        swap(arr[j], arr[j + 1]);
                    }
                }
            }
        }
    }
}




int MultiDigit(int number) // ПРОИЗВЕДЕНИЕ ЦИФР ЧИСЛА
{
    int mult = 1;
    while (number != 0) 
    {
        mult *= number % 10;
        number /= 10;
    }
    return mult;
}

void massive(int arr[], int const SIZE) // ИНИЦИЛИЗАТОР МАССИВА
{
    for (int i = 0 ; i < SIZE ; i++)
    {
        arr[i] = rand()%1000;
    }
}
int del(int x) // ПРОВЕРКА НА ПРОСТОЕ ЧИСЛО
{
    bool flag = true;
    for (int divison = 2 ; divison <= x - 1 ; divison++)
    {
        if (x % divison == 0)
        {
            flag = false;
        }
    }
    return flag;
}

    void write(int arr[], int const SIZE) // ВЫВОД МАССИВА
{
    for (int i = 0 ; i < SIZE ; i++)
    {
        cout << arr[i] << endl;
    }
}

void sort(int arr[], int const SIZE) // СОРТИРОВКА МАССИВА ПУЗЫРЬКОМ
{
    int temp;
    for (int i = 0 ; i < (SIZE - 1) ; i++)
    {
        for (int j = 0; j < SIZE - 1 - i ; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

}
// ОСНОВНОЙ КОД

/*
Задание 1
*/

int main()
{
    srand(time(NULL));
    int const SIZE = 10; // ВВОД РАЗМЕРА МАССИВА
    int nums[SIZE];
    bool flag = false;
    for (int i = 0 ; i < SIZE ; i++)
    {
        nums[i] = rand()%10000;
        if (del(nums[i]))
        {
            flag = true;
        }
    }
    if (flag)
    {
        sort(nums, SIZE);
    }
    cout << "Вывод задания №1: " << endl;
    write(nums, SIZE);

// Задание 2

    int numbers[SIZE], mult[SIZE];
    massive(numbers, SIZE);
    for (int i = 0; i < SIZE ; i++)
    {
        mult[i] = MultiDigit(numbers[i]);
    }
    sort2(numbers, mult, SIZE);
    cout << "Вывод задания №2: " << endl;
    write(numbers, SIZE);
}

