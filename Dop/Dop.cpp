#include <iostream>
using namespace std;

int main()
{
    int Q1, Q2, P1, P2, A, gruz1, gruz2, remains, price, travels2, min_price = __INT_MAX__;
    cin >> Q1 >> P1 >> Q2 >> P2 >> A;
    for (int travels1 = 0; travels1 <= ((A + Q1 - 1) / Q1) ; travels1++) // ЦИКЛ ПО ПОЕЗДКАМ ОТ 0 ДО (ГРУЗ / ВМЕСТИМОСТЬ ГРУЗОВИКА_1 {ОКРУГЛЕНИЕ ВВЕРХ})
    {
        gruz1 = travels1 * Q1; // ПЕРВЫЙ ГРУЗ = ПОЕЗДКИ_1 * ТОННЫ
        remains = A - gruz1; // ОСТАТОК = ВСЕГО ТОН - ПЕРВЫЙ ГРУЗ
        travels2 = 0;
        if (remains > 0) // ЕСЛИ ЕСТЬ ЧТО ВЕЗТИ
        {
            travels2 = ((remains + Q2 - 1) / Q2); // ПОЕЗДКИ_2 = (ГРУЗ / ВМЕСТИМОСТЬ ГРУЗОВИКА_2 {ОКРУГЛЕНИЕ ВВЕРХ})
        }
        price = travels1 * P1 + travels2 * P2; // ИТОГОВАЯ СТОИМОСТЬ
        min_price = min(min_price, price); // МИНИМАЛЬНАЯ СТОИМОСТЬ
    }
    cout << min_price << endl;
    


// Задание 3
    int const SIZE = 20100;
    int n, temp1, temp2;
    cout << "Введите n <= 10000: ";
    cin >> n;
    int arr[SIZE];
    for (int i = 0; i < n ; i++)
    {
        arr[i] = i + 1;
    }
    for (int i = 0 ; i < n; i++)
    {
        int num_global = arr[i]; 
        bool flag = true;
        if (num_global > 9)
            while (num_global != 0) // ПРОВЕРКА НА РАЗЛИЧНОСТЬ ЦИФР ЧИСЛА
            {
                int digit_global = num_global % 10, num_local = num_global / 10; 
                while (num_local != 0)
                {
                    int digit_local = num_local % 10; 
                    if (digit_global == digit_local)
                    {
                        flag = false;
                    }
                    num_local /= 10;    
                }
                num_global /= 10;   

            }
        else 
        {
            flag = false;
        }

        int palindrom = 0, number = arr[i];
        bool flag_palindrom = false;



        while ((!flag) && (number != 0)) // ПРОВЕРКА НА ПАЛИНДРОМ
        {
            palindrom = palindrom * 10 + number % 10;
            number /= 10;
        }
        if (palindrom == arr[i])
        {
            flag_palindrom = true;
        }



        if (flag) //  УДАЛЕНИЕ ЧИСЕЛ БЕЗ ОДИНАКОВЫХ ЦИФР
        {
            n--;
            for (int j = i ; j < n ; j++)
            {
                arr[j] = arr[j + 1];
            }
            i--;

        }





        else if (flag_palindrom) // ДУБЛИРОВАНИЕ ПАЛИНДРОМОВ
        {
            temp1 = arr[i + 1];
            arr[i + 1] = arr[i];
            n++;
            for (int j = i + 1 ; j < n ; j++)
            {
                temp2 = arr[j + 1];
                arr[j + 1] = temp1;
                temp1 = temp2;
            }
            i++;
        }
    }
    for (int i = 0; i < n ; i++) // ВЫВОД
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
}