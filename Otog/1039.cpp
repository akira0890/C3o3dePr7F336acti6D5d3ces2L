#include <iostream>
#include <vector>
#include <climits>

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n,q; std::cin >> n >> q;
    std::vector<long long> W(n) , C(n) , actW(n,0) , sum(n,0);

    W[0] = 0;
    for (int i = 1 ; i < n ; i++) std::cin >> W[i];
    for (int i = 1 ; i < n ; i++) W[i] += W[i-1];
    for (int i = 0 ; i < n ; i++) std::cin >> C[i];
    for (int i = 1 ; i < n ; i++) actW[i] = W[i] - W[i-1];

    sum[n-2] = C[n-1] * actW[n-1];
    for (int i = n-3 ; i >= 0 ; i--) {
        sum[i] = sum[i+1] + C[i+1] * actW[i+1];
    }

    int u , v;
    while (q--) {
        std::cin >> u >> v;

        long long minsum = LLONG_MAX;
        if (u < v) {
            for (int i = 0 ; i <= u ; i++) {
                minsum = std::min(minsum , sum[i]-sum[u] + C[i]*(W[v]-W[i]));
            }
        } else {
            minsum = sum[v] - sum[u];
        }

        std::cout << minsum << '\n';
    }
}