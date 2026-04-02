#include <iostream>
#include <vector>
#include <queue>

#define priorityQ std::priority_queue<long long , std::vector<long long> , std::greater<long long>>

struct DSU {
    std::vector<int> parent , sz;

    DSU(int n) {
        sz.resize(n+1,1);
        parent.resize(n+1);
        for (int i = 1 ; i <= n ; i++) parent[i]=i;
    }

    int find(int n) {
        if (parent[n] == n)
            return n;
        return parent[n] = find(n);
    }

    void unite(int u , int v) {
        int pu = find(u);
        int pv = find(v);

        if (pu == pv) return;

        if (sz[pu] < sz[pv]) {
            parent[pu] = pv;
        } else if (sz[pu] > sz[pv]) {
            parent[pv] = pu;
        } else {
            parent[pu] = pv;
            sz[pv]++;
        }
    }
};

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n,m,k; std::cin >> n >> m >> k;

    std::vector<std::vector<std::pair<int , long long>>> g(n+1);
    DSU dsu(n);

    int u , v;
    long long w;
    for (int i = 0 ; i < m ; i++) {
        std::cin >> u >> v >> w;
        g[u].emplace_back(v,w);
        g[v].emplace_back(u,w);

        dsu.unite(u,v);
    }

    std::vector<bool> visited(n+1,false);
    std::vector<priorityQ> mst(2005);
    int currMst = 0;

    for (int i = 1 ; i <= n ; i++) {
        if (!visited[dsu.find(i)]) {
            
        }
    }
}