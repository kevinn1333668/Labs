#include <iostream>

#include "functions.hpp"

using namespace IO;
using namespace std;



int main()
{

    int matrix[ROWS][COLS];
    int N;
    cout << "Введите разменость матрицы: " << endl;
    cin >> N;
    read(matrix, N);
    if (is_cols_equal(matrix, N) && is_oneElement_prime(matrix, N))
    {
        sort_matrix(matrix, N);
    }

    write(matrix, N);


}