#include <iostream>
#include <cmath>
#include <algorithm>

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n; std::cin >> n;

    int mid = n/2;

    for (int i = 0 ; i < n ; i++) {
        int spaces = std::abs(mid - i);
        std::cout << std::string(spaces , ' ');

        int diamondwidth = n - (std::abs(mid - i) * 2);
        for (int j = 0 ;j < diamondwidth ; j++) {
            int realJ = j + spaces;

            if (i == mid && realJ == mid) std::cout << 'N';
            else {
                int distfromCenter = std::abs(mid - i) + std::abs(mid - realJ);
                int layerfromOutside = mid - distfromCenter;

                if (layerfromOutside % 2 == 0) std::cout << '*';
                else std::cout << '^';
            }
        }
        std::cout << '\n';
    }
}