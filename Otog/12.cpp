#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    long long n; std::cin >> n;

    if (n < 10) {std::cout << n; return 0;}

    std::vector<int> v;
    for (int i = 9 ; i >= 2 ; i--) {
        while (n % i == 0) {
            v.emplace_back(i);
            n /= i;
        }
    }

    if (n > 1) {std::cout << -1;}
    else {
        std::sort(v.begin() , v.end());
        for (int x : v) std::cout << x;
    }
}