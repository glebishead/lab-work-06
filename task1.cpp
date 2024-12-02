#include <iostream>
#include <algorithm>


bool is_last_digit_less(int n1, int n2) {
    if ((n1 % 10) < (n2 % 10)) return true;
    return false;
}

int main() {
    std::cout << "1." << std::endl;
     
    const int NMAX = 10000;
    int m[NMAX]  {1, 2, 3, 7, 8, 8, 11, 13, 12, 14}; // 1 test
    // int m[NMAX]  {1, 2, 3, 7, 8, 11, 13, 12, 14}; // 2 test
    int M[NMAX];
    std::copy(std::begin(m), std::end(m), std::begin(M));
    
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
