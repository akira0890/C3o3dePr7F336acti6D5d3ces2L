#include <iostream>
#include <vector>
#include <bitset>
#include <queue>

std::bitset<1000005> dp[105];
int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n,m,s; std::cin >> n >> m >> s;

    std::vector<std::vector<std::pair<int,int>>> g(n);

    int u,v,w;
    for (int i = 0 ; i < m ; i++) {
        std::cin >> u >> v >> w;
        g[u].emplace_back(v,w);
        g[v].emplace_back(u,w);
    }

    for (int i = 1 ; i <= n ; i++) {
        dp[i][0] = 1;
    }

    for (int iter = 0 ; iter < n ; iter++) {
        for (int i = 1 ; i <= n ; i++) {
            if (dp[i].none()) continue;
            for (auto [dest , dist] : g[i]) {
                dp[dest] |= (dp[i] << dist);
            }
        }
    }

    bool ans = false;
    for (int i = 1 ; i <= n ; i++) {
        if (dp[i][s]) ans = true;
    }

    std::cout << ans;
}