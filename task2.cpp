#include <iostream>


int get_first_digit(int n) {
    while (n > 9) {
        n /= 10;
    }
    return n;
}

int get_digit_multiplication(int n) {
    int m = 1; // все равно числа натуральные
    while (n > 0) {
        m *= (n % 10);
        n /= 10;
    }
    return m;
}

bool worth_sort(int ni, int nj,
                int first_digit_i, int first_digit_j,
                int digits_multiplication_i, int digits_multiplication_j) {
                    if (first_digit_j == first_digit_j & 
                        digits_multiplication_j == digits_multiplication_i & 
                        nj < ni) return true;
                    if (first_digit_j == first_digit_i & 
                        digits_multiplication_j < digits_multiplication_i) return true;
                    if (first_digit_j < first_digit_i) return true;
                    return false;
                }


int main() {
    /*2. Ввести последовательность натуральных чисел {Aj}j=1...n (n<=1000). 
    Упорядочить последовательность по неубыванию первой цифры числа,
    числа с одинаковыми первыми цифрами дополнительно упорядочить 
    по неубыванию произведения цифр числа, 
    числа с одинаковыми первыми цифрами и одинаковыми произведениями цифр 
    дополнительно упорядочить по неубыванию самого числа.*/
    std::cout << "2." << std::endl;
     
    const int NMAX = 10000;
    int first_digits[NMAX];
    int digits_multiplication[NMAX];
    
    /*
    int n = 8;
    int m[NMAX] = {11, 12, 21, 22, 123, 132};
    */
    
    int m[NMAX];
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> m[i];
    }
    
    for (int i = 0; i < n; i++) {
        first_digits[i] = get_first_digit(m[i]);
        digits_multiplication[i] = get_digit_multiplication(m[i]);
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (worth_sort(m[i], m[j],
                           first_digits[i], first_digits[j], 
                           digits_multiplication[i], digits_multiplication[j])) {
                std::swap(m[i], m[j]);
                std::swap(first_digits[i], first_digits[j]);
                std::swap(digits_multiplication[i], digits_multiplication[j]);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        std::cout << m[i] << " " << first_digits[i] << " " << digits_multiplication[i] << std::endl;
    }
    
    return 0;
}
