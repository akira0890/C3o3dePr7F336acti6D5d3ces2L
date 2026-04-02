#include <iostream>
#include <vector>

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n,q; std::cin >> n >> q;
    std::vector<long long> prefixodd(n+4,0) , prefixeven(n+4,0);

    long long val;
    std::cin >> prefixodd[1];
    if (n >= 2) std::cin >> prefixeven[2];
    prefixodd[2] = prefixodd[1];
    prefixeven[3] = prefixeven[2];
    for (int i = 3 ; i <= n ; i++) {
        std::cin >> val;
        if (i % 2 == 1) {
            prefixodd[i] += prefixodd[i-2] + val;
            prefixodd[i+1] = prefixodd[i];
        } else {
            prefixeven[i] += prefixeven[i-2] + val;
            prefixeven[i+1] = prefixeven[i];
        }
    }

    int l , r;
    for (int i = 0 ; i < q ; i++) {
        std::cin >> l >> r;

        long long ans;
        // std::cout << l << ' ' << r << ' ' << l%2 << ' ';
        if (l%2 == 0) {
            ans = prefixeven[r] - prefixeven[l-1] - (prefixodd[r] - prefixodd[l-1]);
            // std::cout << "odd " << prefixeven[r] - prefixeven[l-1] << ' ' << (prefixodd[r] - prefixodd[l-1]) << " ans ";
        } else {
            ans = prefixodd[r] - prefixodd[l-1] - (prefixeven[r] - prefixeven[l-1]);
            // std::cout << "even " << prefixodd[r] - prefixodd[l-1] << ' ' << (prefixeven[r] - prefixeven[l-1]) << " ans ";
        }
        std::cout << ans << '\n';
    }
}