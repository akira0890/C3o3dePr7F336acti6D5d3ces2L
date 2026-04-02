#include <iostream>

int v[] = {
    4,7,44,47,74,77,444,447,474,477,744,747,774,777
};

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    // for (int i = 1 ; i <= 1000 ; i++) {
    //     int j = i;
    //     bool t = true;
    //     while (j) {
    //         if (j % 10 != 4 && j % 10 != 7) {
    //             t = false; break;
    //         }
    //         j /= 10;
    //     }
    //     if (t) std::cout  << i << ",";
    // }
    int n; std::cin >> n;

    int sizes = (sizeof(v) / sizeof(int));
    for (int i = 0 ; i < sizes ; i++) {
        if (n % v[i] == 0) {
            std::cout << "YES";
            return 0;
        }
    }
    std::cout << "NO";
}