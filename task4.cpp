#include <iostream>

int main()
{
    std::cout << "4." << std::endl;
    
    const int NMAX = 100;
    int matrix[NMAX][NMAX];
    int n, m;
    std::cout << "Enter matrix n x m" << std::endl;
    std::cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> matrix[i][j];
        }
    }
    
    matrix[0][0] = matrix[1][2] = matrix[2][3] = matrix[3][1] = 0;
    
    matrix[0][1] = matrix[1][0] = matrix[1][1];
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
