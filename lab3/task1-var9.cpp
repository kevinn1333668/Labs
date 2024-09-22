#include <iostream>
using namespace std;

int main()
{
    int n, i, size;
    cout << "Введите число от 0 до 10^9: ";
    cin >> n;
    cout << "Введите введите интересующий бит: ";
    cin >> i;
    if (n & (1 << i)) 
    {
        cout << "Искомый бит: 1" << endl;
    }
    else 
    {
        cout << "Искомый бит: 0" << endl;
    }
} 