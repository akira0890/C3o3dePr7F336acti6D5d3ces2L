#include <iostream>

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n; std::cin >> n;
    for (int i = 0 ; i < n ; i++) std::cout << std::string(i,'-') << std::string(n-i , '*') << '\n';
}