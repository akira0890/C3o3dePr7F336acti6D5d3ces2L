#include <iostream>
#include <climits>
#include <vector>
#include <queue>

#define pii std::pair<long long , long long>

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n,m; std::cin >> n >> m;

    std::vector<std::vector<pii>> g(n);
    int u,v;
    long long w;
    for (int i = 0 ; i < m ; i++) {
        std::cin >> u >> v >> w;
        g[u].emplace_back(v,w);
        g[v].emplace_back(u,w);
    }

    
}