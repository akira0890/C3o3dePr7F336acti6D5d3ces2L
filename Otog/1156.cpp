#include <iostream>

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n; std::cin >> n;
    int ans = 0,t,r;
    for (int i = 0 ; i < n ; i++) {
        std::cin >> t >> r;
        if (r - t >= 2) ans++;
    }
    std::cout << ans;
}