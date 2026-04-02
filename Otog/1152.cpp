#include <iostream>

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n,h,t,ans = 0; std::cin >> n >> h;
    for (int i = 0 ; i < n ; i++) std::cin >> t , ans += (t <= h) ? 1 : 2;
    std::cout << ans;
}