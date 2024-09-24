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
        arr[i] = i + 1;
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
        cout << arr[i] << ' ';
    }
    cout << endl;
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
    int SIZE; // ВВОД РАЗМЕРА МАССИВА
    cout << "Введите n <= 10000: ";
    cin >> SIZE;
    int *nums = new int[SIZE];
    bool flag = false;
    for (int i = 0 ; i < SIZE; i++)
    {
        nums[i] = i + 1;
        if (del(nums[i]))
        {
            flag = true;
        }
    }
    if (flag)
    {
        sort(nums, SIZE);
    }
    write(nums, SIZE);

// Задание 2

    int SIZE2;
    cout << "Введите n <= 1000: ";
    cin >> SIZE2;
    int *numbers = new int[SIZE2], *mult = new int[SIZE2];
    massive(numbers, SIZE2);
    for (int i = 0; i < SIZE2 ; i++)
    {
        mult[i] = MultiDigit(numbers[i]);
    }
    sort2(numbers, mult, SIZE2);
    write(numbers, SIZE2);

// Задание 3 
    int ROW, COL; // Ввод строк и столбцоы в массив
    cout << "Введите кол-во строк и столбцов матрицы: ";
    cin >> ROW >> COL;
    int arr[ROW][COL], chet = 0, min_chet = 99999, index, cnt = 0;
    {
        for (int i = 0; i < ROW ; i++) // заполнение массива
        {
            chet = 0;
            for (int j = 0; j < COL ; j++)
            {
                cnt++ ;
                arr[i][j] = cnt;
                if (arr[i][j] % 2 == 0)
                {
                    chet += 1;
                }        
            }
            if (chet < min_chet)
            {
                min_chet = chet;
                index = i;
            }
        }
        for (int j = 0 ; j < COL ; j++)
        {
            arr[index][j] = arr[index][j] * arr[index][j];
        }
        
    }
    for (int i = 0; i < ROW ; i++) // заполнение массива
    {
        for (int j = 0; j < COL ; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

