#include <iostream>
using namespace std;

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
}
