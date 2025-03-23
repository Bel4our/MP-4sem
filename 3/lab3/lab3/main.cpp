#include <iostream>
#include <limits>

using namespace std;

#define INF INT_MAX
const int N = 5; 


int costMatrix[N][N] = {
    {INF, 20, 32, INF, 10},
    {10, INF, 25, 58, 74},
    {12, 30, INF, 86, 59},
    {27, 48, 40, INF, 30},
    {83, 76, 52, 23, INF}
};

bool visited[N] = { false };
int bestCost = INF;
int bestPath[N + 1]; 
int currentPath[N];  

int reduceMatrix(int matrix[N][N], int rowReduction[N], int colReduction[N]) 
{
    int reductionCost = 0;

    for (int i = 0; i < N; i++) 
    {
        rowReduction[i] = INF;
        for (int j = 0; j < N; j++)
        {
            if (matrix[i][j] < rowReduction[i]) 
            {
                rowReduction[i] = matrix[i][j];
            }
        }
        if (rowReduction[i] != INF && rowReduction[i] != 0)
        {
            for (int j = 0; j < N; j++) {
                if (matrix[i][j] != INF) {
                    matrix[i][j] -= rowReduction[i];
                }
            }
            reductionCost += rowReduction[i];
        }
    }

    for (int j = 0; j < N; j++)
    {
        colReduction[j] = INF;
        for (int i = 0; i < N; i++) 
        {
            if (matrix[i][j] < colReduction[j]) 
            {
                colReduction[j] = matrix[i][j];
            }
        }
        if (colReduction[j] != INF && colReduction[j] != 0)
        {
            for (int i = 0; i < N; i++)
            {
                if (matrix[i][j] != INF)
                {
                    matrix[i][j] -= colReduction[j];
                }
            }
            reductionCost += colReduction[j];
        }
    }

    return reductionCost;
}

void branchAndBound(int matrix[N][N], int currentCost, int level, int currentCity) 
{
    if (level == N) 
    {
        if (matrix[currentCity][0] != INF) 
        {
            int totalCost = currentCost + matrix[currentCity][0];
            if (totalCost < bestCost) 
            {
                bestCost = totalCost;

                for (int i = 0; i < N; i++) {
                    bestPath[i] = currentPath[i];
                }
                bestPath[N] = 0; 
            }
        }
        return;
    }

    int tempMatrix[N][N];
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < N; j++) 
        {
            tempMatrix[i][j] = matrix[i][j];
        }
    }

    int rowReduction[N], colReduction[N];
    int reducedCost = reduceMatrix(tempMatrix, rowReduction, colReduction);

    for (int nextCity = 0; nextCity < N; ++nextCity) 
    {
        if (!visited[nextCity] && matrix[currentCity][nextCity] != INF) 
        {
            visited[nextCity] = true;
            currentPath[level] = nextCity;

            int nextMatrix[N][N];
            for (int i = 0; i < N; i++) 
            {
                for (int j = 0; j < N; j++) 
                {
                    nextMatrix[i][j] = tempMatrix[i][j];
                }
            }

            for (int i = 0; i < N; i++) 
            {
                nextMatrix[currentCity][i] = INF;
                nextMatrix[i][nextCity] = INF;
            }
            nextMatrix[nextCity][currentCity] = INF;

            branchAndBound(nextMatrix, currentCost + matrix[currentCity][nextCity] + reducedCost, level + 1, nextCity);

            visited[nextCity] = false;
        }
    }
}

int main() 
{
    setlocale(LC_ALL, "rus");
    visited[0] = true;
    currentPath[0] = 0;

    int tempMatrix[N][N];
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < N; j++)
        {
            tempMatrix[i][j] = costMatrix[i][j];
        }
    }

    int rowReduction[N], colReduction[N];
    int initialCost = reduceMatrix(tempMatrix, rowReduction, colReduction);

    branchAndBound(tempMatrix, initialCost, 1, 0);

    cout << "Минимальная стоимость: " << bestCost << endl;
    cout << "Путь: ";
    for (int i = 0; i <= N; i++) 
    {
        cout << bestPath[i] + 1 << " ";
    }
    cout << endl;

    return 0;
}