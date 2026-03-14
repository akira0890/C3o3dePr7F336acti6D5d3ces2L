#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n,q; std::cin >> n >> q;
    long long t , sum = 0;

    std::vector<long long> v(n+1,0) , best(n+1,0);
    for (int i = 1 ; i <= n ; i++) {
        std::cin >> t;
        v[i] = v[i-1]+t;
    }

    best[n] = v[n];
    for (int i = n-1 ; i > 0 ; i--) {
        best[i] = std::min(best[i+1] , v[i]);
    }

    long long target;
    while (q--) {
        std::cin >> target;
        std::cout << (std::upper_bound(best.begin() , best.end() , target) - best.begin())-1 << '\n';
    }
}