#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n,q; std::cin >> n >> q;
    std::vector<long long> v(n);
    std::cin >> v[0];
    for (int i = 1 ; i < n ; i++) std::cin >> v[i];

    std::sort(v.begin() , v.end());
    for (int i = 1 ; i < n ; i++) v[i] += v[i-1];

    long long target;
    for (int i = 0 ; i < q ; i++) {
        std::cin >> target;

        std::cout << std::upper_bound(v.begin() , v.end() , target) - v.begin() << '\n';
    }
}