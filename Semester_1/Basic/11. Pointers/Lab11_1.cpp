
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

bool have_14(int* mas, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (sum_num(mas[i]) == 14)
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    int size;
    std::cin >> size;
    int* mas = new int[size];


    for (int i = 0; i < size; i++)
    {
        int x;
        std::cin >> x;
        mas[i] = x;
    }

    if (have_14(mas, size) == 1)
    {
        for (int x = 0; x < size - 1; x++)
            for (int y = x + 1; y < size; y++)
                if (mas[x] > mas[y])
                {
                    int tmp = mas[x];
                    mas[x] = mas[y];
                    mas[y] = tmp;
                }
    }

    std::cout << " " << std::endl;

    for (int i = 0; i < size; i++)
    {
        std::cout << mas[i] << " ";
    }

    delete[] mas;
}
