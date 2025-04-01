#include <cmath>
#include <memory.h>
#include <iostream>
#include <chrono> 
#include "MultiMatrix.h"   

#define N 6
int main()
{
    int Mc[N + 1] = { 100,15,20,43,70,40,71 }, Ms[N][N], r = 0, rd = 0;

    memset(Ms, 0, sizeof(int) * N * N);

    auto start = std::chrono::high_resolution_clock::now();
    r = OptimalM(1, N, N, Mc, OPTIMALM_PARM(Ms));
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    setlocale(LC_ALL, "rus");
    std::cout << std::endl;
    std::cout << std::endl << "-- расстановка скобок (рекурсивное решение) "
        << std::endl;
    std::cout << "Время выполнения: " << elapsed.count() << " микросекунд" << std::endl;
    std::cout << std::endl << "размерности матриц: ";
    for (int i = 1; i <= N; i++) std::cout << "(" << Mc[i - 1] << "," << Mc[i] << ") ";
    std::cout << std::endl << "минимальное количество операций умножения: " << r;
    std::cout << std::endl << std::endl << "матрица S" << std::endl;
    for (int i = 0; i < N; i++)
    {
        std::cout << std::endl;
        for (int j = 0; j < N; j++)  std::cout << Ms[i][j] << "  ";
    }
    std::cout << std::endl;

    memset(Ms, 0, sizeof(int) * N * N);

    start = std::chrono::high_resolution_clock::now();
    rd = OptimalMD(N, Mc, OPTIMALM_PARM(Ms));
    end = std::chrono::high_resolution_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::cout << std::endl
        << "-- расстановка скобок (динамическое программирование) " << std::endl;
    std::cout << "Время выполнения: " << elapsed.count() << " микросекунд" << std::endl;
    std::cout << std::endl << "размерности матриц: ";
    for (int i = 1; i <= N; i++)
        std::cout << "(" << Mc[i - 1] << "," << Mc[i] << ") ";
    std::cout << std::endl << "минимальное количество операций умножения: "
        << rd;
    std::cout << std::endl << std::endl << "матрица S" << std::endl;
    for (int i = 0; i < N; i++)
    {
        std::cout << std::endl;
        for (int j = 0; j < N; j++)  std::cout << Ms[i][j] << "  ";
    }
    std::cout << std::endl << std::endl;
    system("pause");

    return 0;
}