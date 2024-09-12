#include <iostream>
#include <cmath>
const int N = 100;
const int M = 100;
namespace fnc
{
    bool have_35(int x) //
    {
        x = abs(x);
        bool flag = 0;
        while (x > 0)
        {
            if ((x % 10 == 5) or (x % 10 == 3))
            {
                flag = 1;
                break;
            }
            x /= 10;

        }
        return flag;
    }

    void print(int matrix[N][M], int n, int m) //
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                std::cout << matrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    int task_check(int matrix[N][M], int n) //
    {
        int counter = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (((i == j) or ((i+j)==n)) and (matrix[i][j] > 0) and (have_35(matrix[i][j])))
                {
                    counter++;
                }
            }
        }
        return counter;
    }

    int summ_kv_stolb(int matrix[N][M], int n, int x)
    {
        int result = 0;
        for (int i = 0; i < n; i++)
        {
            result += pow(matrix[i][x], 2);
        }
        return result;
    }

    int stolb_min_num(int matrix[N][M], int n, int j)
    {
        int stolb_min_num = INT_MAX;
        int stolb_min = 0;

        for (int i = 0; i < n; i++)
        {
            if (matrix[i][j] < stolb_min_num)
                stolb_min_num = matrix[i][j];
        }
        return stolb_min_num;
    }

    void input(int matrix[N][M], int& n, int& m) //
    {
        std::cin >> n >> m;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                std::cin >> matrix[i][j];
            }
        }

    }

    int error_check(int n, int m) //
    {
        if (n != m)
        {
            std::cout << "Matrix is not square task completment is impossible." << std::endl;
            return -1;
        }
    }

    void fin_fun(int matrix[N][M], int n)
    {
        for (int j = 0; j < n; j++)
        {
            int mini = stolb_min_num(matrix, n, j);
            int summ_kv = summ_kv_stolb(matrix, n, j);
            for (int i = 0; i < n; i++)
            {
                if (matrix[i][j] == mini)
                {
                    matrix[i][j] = summ_kv;

                }
            }
        }
    }
}
