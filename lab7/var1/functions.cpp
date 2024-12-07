#include <iostream>
#include <algorithm>
#include <cmath>

#include <functions.hpp>

using namespace std;


namespace IO
{

void read(int matrix[ROWS][COLS], int N)
{
    for(int i = 0 ; i < N ; i++)
    {
        for (int j = 0 ; j < N ; j++)
        {
            cin >> matrix[i][j];
        }
    }
}


bool is_cols_equal(int matrix[ROWS][COLS], int N)
{
    bool identical;
    for (int col1 = 0; col1 < N - 1; ++col1) 
    {
        for (int col2 = col1 + 1; col2 < N; ++col2) 
        {
            identical = true;
            for (int row = 0; row < N; ++row)  
            {
                int a = matrix[row][col1], b = matrix[row][col2];
                if (matrix[row][col1] != matrix[row][col2]) 
                {
                    identical = false;
                }
            }
            if (identical)
                return identical;            
        }
    }
    return identical;
}

bool is_prime(int number) {
    if (number < 2) return false;
    for (int i = 2; i <= std::sqrt(number); ++i) 
    {
        if (number % i == 0) return false;
    }
    return true;
}
bool is_oneElement_prime(int matrix[ROWS][COLS], int N)
{
    for (int r = 0 ; r < N ; r++)
    {
        for (int c = 0 ; c < N ; c++)
        {
            if (is_prime(abs(matrix[r][c])))
            {
                return true;
            }
        }
    }
    return false;
}

int sumAbsRow(int matrix[ROWS], int N)
{
    int sum = 0;
    for (int i = 0 ; i < N ; i++)
    {
        sum += abs(matrix[i]); 
    }
    return sum;
}


void sort_matrix(int matrix[ROWS][COLS], int N)
{
    int i, j;
    for (i = 1; i < N; i++)
    {
        int key = sumAbsRow(matrix[i], N);
        for (j = i - 1; j >= 0 && sumAbsRow(matrix[j], N) > key; j--)
        {
            for (int k = 0; k < N; k++)
            {
                matrix[j+1][k] = matrix[j][k];
            }
        }
        for (int k = 0; k < N; k++)
            {
                matrix[j+1][k] = matrix[j][k];
            }
    }
}

void write(int matrix[ROWS][COLS], int N)
{
    cout << "Вывод: " << endl;
    for (int i = 0 ; i < N ; i++)
    {
        for (int j = 0 ; j < N ; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
}

