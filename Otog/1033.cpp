#include <iostream>
#include <vector>
#include <algorithm>

#define ull unsigned long long

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n,q; std::cin >> n >> q;
    std::vector<ull> v(n+2,0) , prefix(n);

    for (int i = 1 ; i <= n ; i++) std::cin >> v[i];

    for (int i = 1 ; i <= n ; i++) prefix[i-1] = v[i-1] + v[i] + v[i+1];

    std::sort(prefix.begin() , prefix.end());

    for (int i = 0 ; i < q ; i++) {
        ull l , r;
        std::cin >> l >> r;

        std::cout << std::upper_bound(prefix.begin() , prefix.end() , r) - std::lower_bound(prefix.begin() , prefix.end() , l) << '\n';
    }
}