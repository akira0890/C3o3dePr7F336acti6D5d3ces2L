#include <iostream>
#include <vector>

class DSU {
    std::vector<int> parent , rank;
public:
    DSU(int n) {
        rank.resize(n+1 , 0);
        parent.resize(n+1);
        for (int i = 0 ; i <= n ; i++) {
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

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n,m;
    std::cin >> n >> m;
    DSU dsu(n);

    int u , v;
    for (int i = 0 ; i < m ; i++) {
        std::cin >> u >> v;
        dsu.unite(u,v);
    }

    int q;
    std::cin >> q;
    for (int i = 0 ; i < q ; i++) {
        std::cin >> u >> v;
        int findu = dsu.find(u);
        int findv = dsu.find(v);

        if (findu == findv) std::cout << "true\n";
        else std::cout << "false\n";
    }
}