#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

struct Node {
    int u,v;
    long long w;

    Node(int _u , int _v , long long _w) : u(_u) , v(_v) , w(_w) {}

    bool operator<(const Node& other) const {
        return w < other.w;
    }
};

class DSU {
    std::vector<int> parent , rank;
public:
    DSU(int n) {
        parent.resize(n+1);
        rank.resize(n+1,1);
        for (int i = 1 ; i <= n ; i++) parent[i] = i;
    }

    int find(int p) {
        if (parent[p] == p)
            return p;
        return parent[p] = find(parent[p]);
    }

    void unite(int u , int v) {
        int pu = find(u);
        int pv = find(v);

        if (pu == pv) return;

        if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else if (rank[pv] < rank[pu]) {
            parent[pv] = pu;
        } else {
            parent[pu] = pv;
            rank[pv]++;
        }
    }
};

class Graph {
    std::vector<Node> g;
    std::vector<long long> height;
    std::vector<std::vector<int>> mst_adj;
    int vertex;
public:
    Graph(int n) {
        // g.resize(n+1);
        mst_adj.resize(n+1);
        height.resize(n+1);
        vertex = n+1;
    }

    void addNode(int u , int v) {
        g.emplace_back(v,u,std::max(height[u] , height[v]));
        // g.emplace_back(u,v,std::max(height[u] , height[v]));
    }

    void setHeight(int idx , long long h) {
        height[idx] = h;
    }

    std::vector<long long> getH() {
        return height;
    }

    void prim() {
        std::vector<int> visited(vertex, false);
        
        DSU dsu(vertex+1);

        long long total_weight = 0;
        int edges_count = 0;

        for (const auto& edge : g) {
            if (dsu.find(edge.u) != dsu.find(edge.v)) {
                dsu.unite(edge.u, edge.v);
                total_weight += edge.w; 

                mst_adj[edge.u].push_back(edge.v);
                mst_adj[edge.v].push_back(edge.u);
                edges_count++;
            }
        }
        
        bool found = false;
        int leaf;
        std::vector<bool> visited(vertex+1 , false);
        findLeafsDFS(1 , visited , leaf , found);
    }

    void findLeafsDFS(int u, std::vector<bool>& visited, int& leaf , bool& found) {
        visited[u] = true;
        if (found) return;

        if (mst_adj[u].size() == 1) {
            leaf = u;
            found = true;
            return;
        } else if (vertex == 1) {
             leaf = u;
             found = true;
             return;
        }

        for (int v : mst_adj[u]) {
            if (!visited[v]) {
                findLeafsDFS(v, visited, leaf , found);
            }
        }
    }
};

int main() {
    // std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n,m; std::cin >> n >> m;

    long long h;
    Graph g(n);

    for (int i = 0 ; i < n ; i++) {
        std::cin >> h;
        g.setHeight(i+1 , h);
    }

    int u,v;
    for (int i = 0 ; i < m ; i++) {
        std::cin >> u >> v;
        g.addNode(u,v);
    }

    std::cout << g.prim();
}