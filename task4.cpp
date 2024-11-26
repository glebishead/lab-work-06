#include <iostream>

int main()
{
    /*4. Сначала введите последовательность. 
    Затем удалите и продублируйте элементы. 
    Затем выведите полученную последовательность (каждый элемент по одному разу). 
    Используйте в программе только один массив.*/
    std::cout << "4." << std::endl;
    
    const int NMAX = 100;
    int matrix[NMAX][NMAX];
    int n, m;
    std::cout << "Введите размерность матрицы n x m" << std::endl;
    std::cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> matrix[i][j];
        }
    }
    
    // удалить некоторые элементы
    matrix[0][0] = matrix[1][2] = matrix[2][3] = matrix[3][1] = 0;
    
    // продублировать некоторые элементы
    matrix[0][1] = matrix[1][0] = matrix[1][1];
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
