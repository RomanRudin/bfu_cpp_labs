// Дана целочисленная матрица {Aij}i=1...n;j=1..n , n<=100. 
// Если все диагональные элементы матрицы положительны и содержат цифры 3 или 5, 
// заменить минимальные элементы столбцов на суммы квадратов элементов соответствующих столбцов. 


#include <iostream>
#include <cmath>
#include "Header.h"


int main()
{
    int mat[N][M];
    int n, m;
    int stolb_min_pos;

    fnc::input(mat, n, m);

    fnc::error_check(n, m);


    if (fnc::task_check(mat, n) == n)
    {
        fnc::fin_fun(mat, n);
    }

    std::cout << " " << std::endl;

    fnc::print(mat, n, m);

}

