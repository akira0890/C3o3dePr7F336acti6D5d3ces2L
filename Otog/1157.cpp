#include <iostream>

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    long long n; std::cin >> n;
    if (n%2 == 1) std::cout << -(n/2 + 1);
    else std::cout << n/2;
}