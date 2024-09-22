#include <iostream>
#include <math.h>
using namespace std;


int main() {
    float S, p, A, B, C;
    cout << "Введите три стороны треугольника: ";
    cin >> A >> B >> C;
    if ((A <= B + C) && (B <= A + C) && (C <= A + B)) {
        p = (A + B + C) / 2;
        S = pow((p * (p - A)*(p - B)*(p - C)),0.5);
        cout << "Площадь треугольника равна: " << S << endl;
    }
    else {
        cout << "Треугольника с данными сторонами не существует" << endl;
    }
}