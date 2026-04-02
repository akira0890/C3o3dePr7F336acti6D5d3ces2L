#include <iostream>
#include <vector>
#include <algorithm>

struct Node {
    int source, dest;
    long long w;

    Node() {}
    Node(int Source , int Dest , long long W) : source(Source) , dest(Dest) , w(W) {}

    bool operator<(const Node& other) const {
        return w < other.w;
    }
};

class DSU {
    std::vector<int> parent , rank;
public:
    DSU(int n) {
        parent.resize(n+1);
        rank.resize(n+1,0);
        for (int i = 0 ; i < n ; i++) {
            parent[i] = i;
        }
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
        } else if (rank[pu] > rank[pv]) {
            parent[pv] = pu;
        } else {
            parent[pu] = pv;
            rank[pv]++;
        }
    }
};

class Graph {
    std::vector<Node> g;
    int vertex;
    int edge;
public:
    Graph(int n,int m) {
        // g.resize(m);
        edge = m;
        vertex = n;
    }

    void addNode(int u , int v , long long w) {
        g.emplace_back(u,v,w);
        g.emplace_back(v,u,w);
    }

    int kruskal() {
        std::sort(g.begin() , g.end());
        DSU dsu(vertex);
        int mst = 0;

        for (int i = 0 ; i < g.size() ; i++) {
            if (dsu.find(g[i].source) == dsu.find(g[i].dest)) continue;
            // std::cout << g[i].w << ' ' << g[i].source << ' ' << g[i].dest<< " work6\n";

            mst += g[i].w;
            dsu.unite(g[i].source , g[i].dest);
            // std::cout << "wokr\n";
        }

        return mst;
    }
};

int main() {
    // std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n,m; std::cin >> n >> m;
    int u,v;
    long long w;

    Graph g(n,m);

    for (int i = 0 ; i < m ; i++) {
        std::cin >> u >> v >> w;
        g.addNode(u,v,w);
    }

    int ans = g.kruskal();

    std::cout << ans << '\n' << ans*100;
}