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
                if ((FirstDigit(arr[j])) > (FirstDigit(arr[j + 1]))) // сортировка по первой цифре числа
                {
                    swap(arr[j], arr[j + 1]);
                }
                else if ((FirstDigit(arr[j])) == (FirstDigit(arr[j + 1])))
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
    void writeD(int arr[], int const SIZE) // ВЫВОД ДИНАМИЧЕСКОГО МАССИВА
{
    for (int i = 0 ; i < SIZE ; i++)
    {
        cout << *(arr + i) << ' ';
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
    /*int SIZE; // ВВОД РАЗМЕРА МАССИВА
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
    int arr[ROW][COL], chet = 0, min_chet = __INT_MAX__, index, cnt = 0;
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
    }*/
    // 4 Задание
    int const SIZE4 = 20001;
    int arr4[SIZE4], n, temp1, temp2;
    cout << "Введите n <= 10000: ";
    cin >> n;   
    massive(arr4, n);
    for (int i = 0 ; i < n; i++)
    {
        if (MultiDigit(arr4[i]) == 180)
        {
            n--;
            for (int j = i ; j < n ; j++)
            {
                arr4[j] = arr4[j + 1];
            }
            i--;

        }
        else if ((FirstDigit(arr4[i]) == 1) && ((arr4[i] % 10) == 1))
        {
            temp1 = arr4[i + 1];
            arr4[i + 1] = arr4[i];
            n++;
            for (int j = i + 1 ; j < n ; j++)
            {
                temp2 = arr4[j + 1]; // 1 2 2 3 4 5 6  temp1 = ? temp2 = ?
                arr4[j + 1] = temp1;
                temp1 = temp2;
            }
            i++;
        }
    }
    write(arr4, n);
}   

