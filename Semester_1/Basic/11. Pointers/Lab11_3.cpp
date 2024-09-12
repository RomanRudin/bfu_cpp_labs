
#include <iostream>

int sum_num(int x)
{
    int result = 0;
    while (x > 0)
    {
        result += x % 10;
        x /= 10;
    }
    return result;
}

int minimalus(int **mat,int stroke,int stolb)
{
    int mini = INT_MAX;
    int result = 0;
    for (int i = 0; i < stroke; i++)
    {
        for (int j = 0; j < stolb; j++)
        {
            if (mat[i][j] < mini)
            {
                mini = mat[i][j];
                result = j;
            }
        }
    }
    return result;
}

int main()
{
    int stroke, stolb;
    std::cin >> stroke >> stolb;

    int **mat = new int *[stroke];

    for (int i = 0; i < stroke; i++)
    {
        mat[i] = new int[stolb];
    }

    for (int i = 0; i < stroke; i++)
    {
        for (int j = 0; j < stolb; j++)
        {
            std::cin >> mat[i][j];
        }
    }

    int min_stolb = minimalus(mat, stroke, stolb);
    
    for (int i = 0; i < stroke; i++)
    {
        for (int j = 0; j < stolb; j++)
        {
            if ((j == min_stolb) and (mat[i][j] < 0))
            {
                mat[i][j] = 0;
            }
        }
    }

    std::cout << std::endl;

    for (int i = 0; i < stroke; i++)
    {
        
        for (int j = 0; j < stolb; j++)
        {
            std::cout << mat[i][j] << " ";
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < stroke; i++)
    {
        delete[] mat[i];
    }

    delete[] mat;

}

