#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>

#define pii std::pair<long long,int>

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n,m,k,p; std::cin >> n >> m >> k >> p;

    std::vector<int> gecko(k);
    std::vector<std::vector<pii>> g(n);

    int u,v,w;
    for (int i = 0 ; i < k ; i++) std::cin >> gecko[i];
    for (int i = 0 ; i < m ; i++) {
        std::cin >> u >> v >> w;
        g[u].emplace_back(v,w);
        g[v].emplace_back(u,w);
    }

    std::vector<long long> dist(n,LLONG_MAX);
    std::vector<int> parent(n,-1);

    std::priority_queue<pii , std::vector<pii> , std::greater<pii>> pq;

    pq.emplace(0,p);
    dist[p] = 0;

    while (!pq.empty()) {
        auto [distance , curr] = pq.top();
        pq.pop();

        if (dist[curr] < distance) continue;

        for (auto [dest , w] : g[curr]) {
            if (dist[dest] > dist[curr] + w) {
                parent[dest] = curr;
                dist[dest] = dist[curr] + w;
                pq.emplace(dist[dest] , dest);
            }
        }
    }

    std::set<pii> ans;
    for (int i = 0 ; i < k ; i++) {
        std::cout << dist[gecko[i]] << ' ';

        int curr = gecko[i];
        while (parent[curr] != -1)
        {
            ans.emplace(std::min(curr , parent[curr]) , std::max(curr , parent[curr]));
            curr = parent[curr];
        }
        
    }
    std::cout << '\n' << ans.size() << '\n';

    for (auto [a,b] : ans) {
        std::cout << a << ' ' << b << '\n';
    }
}