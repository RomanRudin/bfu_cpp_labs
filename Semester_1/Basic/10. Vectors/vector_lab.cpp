
#include <iostream>
#include <vector>


//За счет каких средств языка С++ получается изменять длину массива std::vector ?                  -во время работы программы vector запрашивает у "куч" ОС память (vector -> new -> malloc -> системный вызов -> vector)   


//Что такое capacity и чем оно отличается от size ? Что делает shrink_to_fit, resize, reserve ?    -size, кол-во элементов в массиве а capacity его "объём". 
//                                                                                                 -shrink_to_fit уменьшает выделенную память до минимально возможного размера, необходимого для хранения содержимого контейнерами.
//                                                                                                 -resize увеличивает/уменьшает размер вектора (так же добавляя/удаляя элементы)
//                                                                                                 -reserve подготавливает место для последующего заполнения


//В чем отличие функции at и[] ? И почему в С++ сделали именно так ?  -Оператор [] и метод .at в классе string C++ предоставляют доступ к символам строки по их индексу. 
// Оператор [] не выполняет проверку границ, поэтому его использование требует осторожности. 
// Метод .at, напротив, генерирует исключение std::out_of_range при выходе за границы строки, что делает код более безопасным. 


int main()
{                               //Что обозначают знаки < и > при создании std::vector?
    std::vector<int> vector;           //В треугольных скобках передаются значения шаблонных аргументов. В данном случае, в качестве значения шаблонного аргумента "Type" передаётся значение - тип "int".


    //Продемонстрируйте работу push_back, erase, insert, clear.

    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        std::cin >> x;
        vector.push_back(x);
    }

    std::cout << "Our vector :" << std::endl;

    for (int i = 0; i < vector.size(); i++)
    {
        std::cout << vector[i] << " ";
    }

    std::cout << " " << std::endl;
    std::cout << "Our vector after .erase() :" << std::endl;

    for (int i = 0; i < vector.size(); i++)
    {
        if (vector[i] % 2 == 0)
        {
            vector.erase(vector.begin()+i);
        }
    }

    for (int i = 0; i < vector.size(); i++)
    {
        std::cout << vector[i] << " ";
    }

    std::cout << " " << std::endl;
    std::cout << "Our vector size after .clear() :" << std::endl;

    vector.clear();

    std::cout << vector.size() << " ";



}

