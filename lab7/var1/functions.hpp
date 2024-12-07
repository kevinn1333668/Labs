
#pragma once

int const ROWS = 100, COLS = 100;

namespace IO {

void read(int matrix[ROWS][COLS], int N);
bool is_cols_equal(int matrix[ROWS][COLS], int N);
bool is_oneElement_prime(int matrix[ROWS][COLS], int N);
void sort_matrix(int matrix[ROWS][COLS], int N);
void write(int matrix[ROWS][COLS], int N);
}