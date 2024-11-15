#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

const double PI = acos(-1);


double intersection_area(double r1, double r2, double d) {

    if (d >= r1 + r2) {
        return 0.0;
    }

    if (d <= abs(r1 - r2)) {
        double r_min = min(r1, r2);
        return PI * r_min * r_min;
    }
    double alpha1 = 2 * acos((r1 * r1 - r2 * r2 + d * d) / (2 * r1 * d));
    double alpha2 = 2 * acos((r2 * r2 - r1 * r1 + d * d) / (2 * r2 * d));
    
    double area1 = 0.5 * r1 * r1 * (alpha1 - sin(alpha1));
    double area2 = 0.5 * r2 * r2 * (alpha2 - sin(alpha2));
    
    return area1 + area2;
}

int main() {
    int x1, y1, r1, x2, y2, r2;
    cout << "Введите координаты и радиус первого круга (x1, y1, r1): ";
    cin >> x1 >> y1 >> r1;
    cout << "Введите координаты и радиус второго круга (x2, y2, r2): ";
    cin >> x2 >> y2 >> r2;


    double d =  sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)); // d - расстояние между центрами окружности
    
    double area1 = PI * r1 * r1;
    double area2 = PI * r2 * r2;
    
    double intersection = intersection_area(r1, r2, d);
    
    double total_area = area1 + area2 - intersection;

    cout << fixed << setprecision(3);
    cout << "Суммарная площадь двух кругов: " << total_area << std::endl;

    return 0;
}