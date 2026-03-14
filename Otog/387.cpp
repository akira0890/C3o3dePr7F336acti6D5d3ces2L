#include <iostream>

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    unsigned long long n;

    std::cin >> n;
    n++;
    std::cout << n << '\n' << n*2 << '\n' << n;
}