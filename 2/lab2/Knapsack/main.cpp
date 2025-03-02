#include <iostream>
#include "../Subsets/Combi.cpp"
#include "knapsack_s.h"
#include <ctime>
#include <random>
#define NN 20

int main()
{
    setlocale(LC_ALL, "rus"); // Устанавливаем локаль для корректного отображения русских символов
    int* v = new int[NN]; // Массив для хранения весов предметов
    int* c = new int[NN]; // Массив для хранения стоимостей предметов
    int V = 300; // Вместимость рюкзака
    srand(time(0)); // Инициализация генератора случайных чисел

    // Заполнение массивов случайными значениями
    for (int i = 0; i < NN; i++)\
    {
        v[i] = rand() % 290 + 10; // Вес предмета от 10 до 300
    }
    for (int i = 0; i < NN; i++) 
    {
        c[i] = rand() % 50 + 5; // Стоимость предмета от 5 до 55
    }

    short m[NN]; // Массив для хранения выбранных предметов (0 или 1)

    clock_t t1 = 0, t2 = 0;
    t1 = clock(); // Начало отсчёта времени

    // Вызов функции для решения задачи о рюкзаке
    int maxcc = knapsack_s(
        V,   // Вместимость рюкзака
        NN,  // Количество предметов
        v,   // Массив весов предметов
        c,   // Массив стоимостей предметов
        m    // Массив для хранения выбранных предметов
    );

    t2 = clock(); // Конец отсчёта времени

    // Вывод результатов
    std::cout << std::endl << "-------- Результат работы программы --------- ";
    std::cout << std::endl << "- Количество предметов: " << NN;
    std::cout << std::endl << "- Вместимость рюкзака: " << V;
    std::cout << std::endl << "- Веса предметов: ";
    for (int i = 0; i < NN; i++) std::cout << v[i] << " ";
    std::cout << std::endl << "- Стоимости предметов: ";
    for (int i = 0; i < NN; i++) std::cout << c[i] << " ";
    std::cout << std::endl << "- Максимальная стоимость рюкзака: " << maxcc;
    std::cout << std::endl << "- Вес выбранных предметов: ";
    int s = 0;
    for (int i = 0; i < NN; i++) s += m[i] * v[i];
    std::cout << s;
    std::cout << std::endl << "- Выбранные предметы: " << std::endl;
    for (int i = 0; i < NN; i++) {
        if (m[i] > 0) {
            std::cout << "( Стоимость: " << c[i] << ")";
            std::cout << "( Вес: " << v[i] << ")";
            std::cout << "( id: " << i << ")" << std::endl;
        }
    }
    std::cout << std::endl << std::endl;
    std::cout << std::endl << "Затраченное время (мс): " << (t2 - t1);
    std::cout << std::endl << "                  (сек): " << ((double)(t2 - t1)) / ((double)CLOCKS_PER_SEC);
    std::cout << std::endl;

    system("pause");
    return 0;
}