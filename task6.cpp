#include <iostream>


const int NMAX = 100000;

bool is_all_digits_differ(int n) {
    int m[NMAX] = {0};
    int i = 0;
    while (n > 0) {
        m[i] = n % 10;
        n /= 10;
        i++;
    }
    for (int j = 0; j < i; j++) {
        for (int k = j + 1; k < i; k++) {
            if (m[j] == m[k]) return false;
        }
    }
    return true;
}

int main()
{
    /*5. Дана последовательность натуральных чисел {Aj}j=1...n (n<=10000). 
    Удалить из последовательности числа, 
    все цифры которых различны, а среди оставшихся 
    продублировать числа, произведение которых кратно 14.*/
    std::cout << "5." << std::endl;
    
    int matrix[NMAX] = {0};
    int n;
    std::cout << "Введите количество элементов последовательности - n" << std::endl;
    std::cin >> n;
    
    for (int i = 0; i < n; i++) {
            std::cin >> matrix[i];
    }
    
    for (int i = 0; i < n; i++) {
        if (not is_all_digits_differ(matrix[i])) {
            matrix[i] = 0;
            // заменим неподходящие на 0 
        }
    }
    
    // перенесем 0 в конец
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (matrix[i] != 0 & matrix[j] != 0) break;
            if (matrix[i] == 0 & matrix[j] != 0) {
                matrix[i] = matrix[j];
                matrix[j] = 0;
            }
        }
    }
    
    // удалим 0
    for (int i = 0; i < n; i++) {
        if (matrix[i] == 0) {
            n = i;
            break;
        }
    }
    
    // добавим в конец пары чисел, произведение которых кратно 14
    int n_copy = n;
    for (int i = 0; i < n_copy; i++) {
        for (int j = i + 1; j < n_copy; j++) {
            if ((matrix[i] * matrix[j]) % 14 == 0) {
                matrix[n] = matrix[i];
                matrix[n + 1] = matrix[j];
                n += 2;
            } 
        }
    }
    
    for (int i = 0; i < n; i++) {
            std::cout << matrix[i] << " ";
    }
    return 0;
}
