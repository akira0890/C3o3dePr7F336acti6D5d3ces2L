#include <iostream>
#include <cmath>

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n; std::cin >> n;
    unsigned long long ans = 0 , t;

    for (int i = 0 ; i < n ; i++) {
        std::cin >> t;
        ans += int(std::log2(t)) + 1;
    }

    std::cout << ans;
}