#include <iostream>
#include <algorithm>


bool is_last_digit_less(int n1, int n2) {
    if ((n1 % 10) < (n2 % 10)) return true;
    return false;
}

int main() {
    /*1. Дана последовательность натуральных чисел {aj}j=1...n (n<=10000). 
    Если в последовательности есть два одинаковых числа, 
    упорядочить последовательность по невозрастанию последней цифры числа.*/
    std::cout << "1." << std::endl;
     
    const int NMAX = 10000;
    int m[NMAX]  {1, 2, 3, 7, 8, 8, 11, 13, 12, 14}; // 1 test
    // int m[NMAX]  {1, 2, 3, 7, 8, 11, 13, 12, 14}; // 2 test
    int M[NMAX];
    std::copy(std::begin(m), std::end(m), std::begin(M));
    /* сделал копию исходного массива, 
    чтобы, если не найдется повторяющихся элементов, вывести исходный*/
    int n = 10;
    bool flag = false;
    
    for (int i = 0; i < NMAX; i++) {
        for (int j = i; j < NMAX; j++) {
            if (not flag) {
                if (i == 0 & m[i] == m[j] & i != j) flag = true;
            }
            if (is_last_digit_less(m[i], m[j])) std::swap(m[i], m[j]);
        }
        if (not flag) break;
        /*если нет повторяющихся, прекратить сортировку, 
        ибо все равно выведется исходный массив. Фрагмент заметно ускоряет работу кода,
        если повторяющихся элементов нет, 
        но в ином случае добавляет проверку каждые NMAX раз.*/
    }
    if (flag) {
        for (int i = 0; i < n; i++) {
            std::cout << m[i] << " ";
        }
    }
    else {
        for (int i = 0; i < n; i++) {
            std::cout << M[i] << " ";
        }
    }
    
    return 0;
}
