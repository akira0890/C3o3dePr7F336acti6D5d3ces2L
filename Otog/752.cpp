#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n,q,t,x; std::cin >> n >> q;
    int sum = 0;

    std::vector<int> v(n+1,0);
    for (int i = 1 ; i <= n ; i++) {
        std::cin >> t;
        sum += t;
        v[i] = std::max(v[i-1] , sum);
    }

    for (int i = 0 ; i < q ; i++) {
        std::cin >> x;
        auto it = std::lower_bound(v.begin() , v.end() , x);

        if (it == v.end()) std::cout << -1 << '\n';
        else std::cout << it-v.begin()-1 << '\n';
    }
}