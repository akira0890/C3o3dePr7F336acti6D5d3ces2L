#include <iostream>

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n;
    char c;
    std::cin >> n >> c;
    std::cout << (char)(c+n);
}