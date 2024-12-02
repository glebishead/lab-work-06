#include <iostream>

int main()
{
    std::cout << "3." << std::endl;
    
    const int NMAX = 100;
    int min_sum, index;
    min_sum = index = 1000000;
    int sum_for_columns[NMAX] = {0};
    
    /*
    // 1
    int n, m;
    n = 3;
    m = 4;
    int matrix[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    */

    // 2
    int matrix[NMAX][NMAX];
    int n, m;
    std::cout << "Введите размерность матрицы n x m" << std::endl;
    std::cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> matrix[i][j];
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            sum_for_columns[j] += matrix[i][j];
        }
    }
    
    for (int i = 0; i < m; i++) {
        if (sum_for_columns[i] < min_sum) {
            min_sum = sum_for_columns[i];
            index = i;
        };
    }
    
    for (int i = 0; i < n; i++) {
        matrix[i][index] += 3;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
