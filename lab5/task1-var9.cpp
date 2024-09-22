#include <iostream>
using namespace std;

/*
Задание 1
*/

int main()
{
    int count, multi = 1, number, mx, mxi;
    cout << "Введите кол-во элементоа последовательности: ";
    cin >> count;
    const int SIZE = count;
    for (int i = 1; i < (SIZE + 1); i++)
    {
        cout << i << ". Введите следующее число: ";
        cin >> number;
        if ((number % 10) == 2)
        {
            multi *= number;
            if (number > mx)
            {
                mx = number;
                mxi = i - 1;
            }
        }    
    }
    cout << "Произведение целых чисел последовательности, оканчивающихся на 2: " << multi << endl;
    cout << "Максимальное из данных чисел и его индекс в последователбности: " << mx << " - " << mxi << endl;    

/*
Задание 2
*/

    int N, nums[10]{}, num, mx2 = 0, mxi2 = -1;
    const int SIZE2 = 10;
    cout << "Введите любое целое число N < 10^9: ";
    cin >> N;
    while (N != 0)
    {
        num = N % 10;
        nums[num] += 1;
        N /= 10;
    }
    for (int i = 0; i < SIZE2 ; i++)
    {
        if (nums[i] > mx2)
        {
            mx2 = nums[i];
            mxi2 = i;
        }
    }
    cout << "Наиболее часто встречающсаяся цифра: " << mxi2 << endl;
}

/*
Нужно ли каждый раз пересобирать файл после его изменения?
Проблема с компиляторами
*/