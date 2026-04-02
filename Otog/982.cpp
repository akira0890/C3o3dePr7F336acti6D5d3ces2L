#include <iostream>
#include <vector>
#include <queue>

struct Node {
    int v;
    long long w;

    Node (int _v , long long _w) : v(_v) , w(_w) {}

    bool operator<(const Node& other) const {
        return w < other.w;
    }

    bool operator>(const Node& other) const {
        return w > other.w;
    }
};

class Graph {
    std::vector<std::vector<Node>> g;
    int n;
public:
    Graph(int _n) {
        n = _n;
        g.resize(_n);
    }

    void addNode(int u , int v , long long w) {
        g[u].emplace_back(v,w);
        g[v].emplace_back(u,w);
    }

    std::pair<int , std::vector<int>> prim() {
        long long ans = 0;
        std::vector<bool> isMST(n,false);
        std::vector<int> parent(n,-1);
        std::vector<long long> minDist(n , 2e18);
        std::priority_queue<std::pair<long long , int> ,
                            std::vector<std::pair<long long , int>> ,
                            std::greater<std::pair<long long , int>>> pq;

                            minDist[0] = 0;
        pq.emplace(0,0);

        while (!pq.empty()) {
            long long w = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if (isMST[u]) continue;

            ans += w;
            isMST[u] = true;

            for (Node dest : g[u]) {
                if (!isMST[dest.v] && dest.w < minDist[dest.v]) {
                    minDist[dest.v] = dest.w;
                    parent[dest.v] = u;
                    pq.emplace(dest.w , dest.v);
                }
            }
        }

        return {ans , parent};
    }
};

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n,m; std::cin >> n >> m;

    Graph g(n);

    int u , v;
    long long w;
    for (int i = 0 ; i < m ; i++) {
        std::cin >> u >> v >> w;
        g.addNode(u,v,w);
    }

    std::pair<int , std::vector<int>> ans = g.prim();

    std::cout << ans.first << '\n';
    for (int i = 0 ; i < n ; i++) {
        std::cout << ans.second[i] << ' ';
    }
}