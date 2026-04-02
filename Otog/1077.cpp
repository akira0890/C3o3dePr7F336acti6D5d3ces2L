#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    long long n,q; std::cin >> n >> q;

    std::vector<long long> v(n);
    for (int i = 0 ; i < n ; i++) std::cin >> v[i];

    std::sort(v.begin() , v.end());

    long long start , increase , maxprice;
    for (int i = 0 ; i < q ; i++) {
        std::cin >> start >> maxprice >> increase;

        auto its = std::lower_bound(v.begin() , v.end() , start - increase);
        auto ite = std::upper_bound(v.begin() , v.end() , maxprice - increase);

        if (its > ite) std::cout << "0\n";
        else std::cout << ite - its << '\n';
    }
}