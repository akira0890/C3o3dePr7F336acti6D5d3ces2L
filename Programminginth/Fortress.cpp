#include <iostream>

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    for (int i = 0 ; i < 20 ; i++) {
        int n,m;
        std::cin >> n >> m;

        if (n % 2 != 0 || n/2 < m) {
            std::cout << 0 << '\n';
            continue;
        }

        int b = (n/2) - m;
        int ac = m - b;

        if (ac < 0) std::cout << 0 << '\n';
        else {
            std::cout << ac+1 << '\n';
        }
    }
}