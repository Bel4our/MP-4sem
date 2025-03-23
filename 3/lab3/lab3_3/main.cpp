// --- main 
#include <iostream>
#include <iomanip> 
#include "salesman.h"
#define N 5
int main()
{
    setlocale(LC_ALL, "rus");
    int d[N][N] = { //1   2    3    4     5        
                  {  INF,  20, 32,  INF,   10},    //  1
                  { 10,   INF,  25,  58,  74},    //  2
                  { 12,  30,   INF,  86,   59},    //  3 
                  { 27,  48,  40,   INF,   30},    //  4
                  { 83,  76,  52,  23,    INF} };   //  5  
    int r[N];                     // результат 
    int s = salesman(
        N,          // [in]  количество городов 
        (int*)d,          // [in]  массив [n*n] расстояний 
        r           // [out] массив [n] маршрут 0 x x x x  

    );
    std::cout << std::endl << "-- Задача коммивояжера -- ";
    std::cout << std::endl << "-- количество  городов: " << N;
    std::cout << std::endl << "-- матрица расстояний : ";
    for (int i = 0; i < N; i++)
    {
        std::cout << std::endl;
        for (int j = 0; j < N; j++)
            if (d[i][j] != INF) std::cout << std::setw(3) << d[i][j] << " ";
            else std::cout << std::setw(3) << "INF" << " ";
    }
    std::cout << std::endl << "-- оптимальный маршрут: ";
    for (int i = 0; i < N; i++) std::cout << r[i] + 1 << "-->"; std::cout << 1;
    std::cout << std::endl << "-- длина маршрута     : " << s;
    std::cout << std::endl;
    system("pause");
    return 0;
}
