#include <iostream>
using namespace std;
/*
Переменная - именованная область в оперативной памяти для хранения информации в различных типах данных.
*/
int main()
{
    int int_num1 = 10, int_num2 = 5;
    float float_num1 = 16.46948128, float_num2 = 9.2342142;
    char char_letter1 = 'z', char_letter2 = 'f';
    bool bool_type1 = true, bool_type2 = false;
    cout << "\t\t\t\t\t\t\t Лабораторная работа 'Типы данных'\n" << endl;

    cout << "1. Целочисленный тип данных \n" << endl;
    
    cout << "Знаковые целые числа: \n" << endl;
    cout << "• int | размерность - 4 байта | от -2.147.483.648 до 2.147.483.648 - 1" << endl;
    cout << "• short | размерность - 2 байта | от -32.768 до 32.767" << endl;
    cout << "• long | размерность - 4 байта | от -2.147.483.648 до 2.147.483.648 - 1" << endl;
    cout << "• long long | размерность - 8 байт | от -2^63 до 2^63 - 1\n" << endl;
    
    cout << "Беззнаковые целые числа: \n" << endl;
    cout << "• int | размерность - 4 байта | от 0 до 4.294.967.295 - 1" << endl;
    cout << "• short | размерность - 2 байта | от 0 до 65.535" << endl;
    cout << "• long | размерность - 4 байта | от 0 до 4.294.967.295 - 1\n" << endl;


    cout << "2. Вещественный тип данных: \n" << endl;
    cout << "• float | размерность - 4 байта | от 3,4*10^(-38) до 3,4*10^(38) - 1" << endl;
    cout << "• double | размерность - 8 байта | от 1,7*10^(-308) до 1,7*10^(-308) - 1" << endl;
    cout << "• long double | размерность - 10 байта | от 3,4*10^(-4932) до 1,1*10^(4932) - 1\n" << endl;
    
    cout << "3. Символьный тип данных: \n" << endl;
    cout << "• char | размерность - 1 байта | от -128 до 127\n" << endl;

    cout << "4. Логический тип данных: \n" << endl;
    cout << "• bool | размерность - 1 байта | true или false\n\n" << endl;
    
    
    cout << "\t\t\t\t\t\t\tАрифметиские операции с разными типами данных\n\n";


    cout << "1. Целые числа: \n" << endl;
    cout << "Сумма: num1 + num2 = " << int_num1 + int_num2 << endl;
    cout << "Разность: num1 - num2 = " << int_num1 - int_num2 << endl;
    cout << "Произведение: num1 * num2 = " << int_num1 * int_num2 << endl;
    cout << "Деление: num1 / num2 = " << int_num1 / int_num2 << "\n" << endl;

    cout << "2. Вещественные числа: \n" << endl;
    cout << "Сумма: num1 + num2 = " << float_num1 + float_num2 << endl;
    cout << "Разность: num1 - num2 = " << float_num1 - float_num2 << endl;
    cout << "Произведение: num1 * num2 = " << float_num1 * float_num2 << endl;
    cout << "Деление: num1 / num2 = " << float_num1 / float_num2 << "\n" << endl;

    cout << "3. Символы: \n" << endl;
    cout << "Сумма: 'f' + 'z' = " << char_letter1 + char_letter2 << endl;
    cout << "Разность: 'f' - 'z' = " << char_letter1 - char_letter2 << endl;
    cout << "Произведение: 'f' * 'z'= " << char_letter1 * char_letter2 << endl;
    cout << "Деление: 'f' / 'z' = " << char_letter1 / char_letter2 << "\n" << endl;

    cout << "4. Логические: \n" << endl;
    cout << "Сумма: true + false = " << bool_type1 + bool_type2 << endl;
    cout << "Разность: true - false = " << bool_type1 - bool_type2 << endl;
    cout << "Произведение: true * false = " << bool_type1 * bool_type2 << "\n" << endl;
}