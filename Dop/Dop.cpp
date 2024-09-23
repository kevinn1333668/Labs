#include <iostream>
using namespace std;

// Задача 1 Грузоперевозка

float coefficient(float Q,float P,float A)

{   
    float K;
    if (Q > A)
    {
        K = A / P;
        return K;
    }
    else 
    {
        K = Q / P;
        return K;
    }
}
int solution(int number) 
{
    int sum = 0;
    while (number) 
    {
        sum += number % 10;
        number /= 10;
    }
    return sum;
}
int main()
{
    float  profit1, profit2, Q1, P1, Q2, P2, A, price = 0;
    cout << "Введите Q1, P1, Q2, P2, A через пробел: ";
    cin >> Q1 >> P1 >> Q2 >> P2 >> A;
    while (A > 0)
    {
        profit1 = coefficient(Q1, P1, A);
        profit2 = coefficient(Q2, P2, A);
        if (profit1 > profit2)
        {
            price += P1;
            A -= Q1;
        }
        else
        {
            price += P2;
            A -= Q2;
        }
    } 
    cout << "Минимальная цена: " << price << endl;


// Задача 2 Счатливые билетики



    int cnt = 0;
    for (int i = 0 ; i < 1000 ; i++)
    {
        for (int j = 0 ; j < 1000 ; j++)
        {
            if (solution(i) == solution(j))
            {
                cnt += 1;
            }
        }
    }
    cout << cnt << endl;
}
