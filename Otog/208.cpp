#include <iostream>
#include <vector>

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n,q,l,r; std::cin >> n >> q;
    std::vector<unsigned long long> prefix(n+1,0);
    unsigned long long t;

    for (int i = 1 ; i <= n ; i++) std::cin >> t , prefix[i] = prefix[i-1]+t;

    for (int i = 0 ; i < q ; i++) {
        std::cin >> l >> r;
        std::cout << prefix[r] - prefix[l-1] << '\n';
    }
}