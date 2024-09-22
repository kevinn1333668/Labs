#include <iostream>
using namespace std;

int main()
{
    int A, B, C;
    cout << "Введите три числа (A,B,C): ";
    cin >> A >> B >> C;
    if ((A > B) && (B > C))
    {
        cout << A - B - C << endl;
    }
    else if ((B > A) && (B % C == 0))
    {
        cout << B / C + B - A << endl;
    }
    else 
    {
        cout << A + B + C << endl;
    } 

    int N;
    cout << "Введите число обозначающее ошибку (от 0 до 3): ";
 
    if (cin >> N)
    {
        switch (N)
        {
            case 0:
                cout << "0 - всё хорошо!" << endl;
                break;
            case 1:
                cout << "1 - ошибка чтения файла" << endl;
                break;
            case 2:
                cout << "2 - ошибка записи файла" << endl;
                break;
            case 3:
                cout << "3 - не все поля определены" << endl;
                break;
            default:
                cout << "Неверный код ошибки!" << endl;
                break;


        }
    }
    else 
    {
        cout << "Неверный код ошибки!" << endl;
    }


    int x;
    cout << "Введите -1 или 1: ";
    cin >> x;
    if (x > 0)
    {
        cout << "Positive number" << endl;
    }
    else
    {
        cout << "Negative number" << endl;
    }
}
