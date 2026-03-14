#include <iostream>
#include <vector>
#include <algorithm>

struct Node {
    int shy , spark;

    Node () : shy(-1) , spark(-1) {}

    Node(int _shy , int _spark) : shy(_shy) , spark(_spark) {}

    bool operator<(const Node& other) const {
        if (shy == other.shy) return spark < other.spark;
        return shy < other.shy;
    }

    bool operator>(const Node& other) const {
        if (shy == other.shy) return spark > other.spark;
        return shy > other.shy;
    }
};

class DSU {
    std::vector<int> parent;
    std::vector<int> rank;
    std::vector<std::pair<Node , Node>> minmax;
public:
    DSU(int n , std::vector<Node> &v) {
        parent.resize(n+1);
        rank.resize(n+1,0);
        minmax.resize(n+1);
        for (int i = 1 ; i <= n ; i++) {
            minmax[i] = {v[i] , v[i]};
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

        Node newMin = std::min(minmax[pu].first , minmax[pv].first);
        Node newMax = std::max(minmax[pu].second , minmax[pv].second);

        if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
            minmax[pv] = {newMin , newMax};
        } else if (rank[pu] > rank[pv]) {
            parent[pv] = pu;
            minmax[pu] = {newMin , newMax};
        } else {
            parent[pv] = pu;
            minmax[pu] = {newMin , newMax};
            rank[pu]++;
        }
    }

    std::pair<Node , Node> getMinMax(int i) {
        return minmax[i];
    }

    bool sameGroup(int u , int v) {
        return find(u) == find(v);
    }
};

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n,m; std::cin >> n >> m;
    std::vector<Node> v(n+1);
    for (int i = 1 ; i <= n ; i++) {
        std::cin >> v[i].shy >> v[i].spark;
    }

    DSU dsu(n , v);

    int x,y;
    for (int i = 0 ; i < m ; i++) {
        std::cin >> x >> y;
        dsu.unite(x,y);
    }

    std::vector<std::pair<Node , Node>> interval;
    std::vector<bool> visited(n+1,0);
    for (int i = 1 ; i <= n ; i++) {
        int parentI = dsu.find(i);
        if (!visited[parentI]) {
            visited[parentI] = true;
            interval.emplace_back(dsu.getMinMax(parentI));
        }
    }

    std::sort(interval.begin() , interval.end());

    int ans = 0;
    Node currMax = interval[0].second;
    for (int i = 1 ; i < interval.size() ; i++) {
        if (interval[i].first < currMax) {
            ans++;

            if (interval[i].second > currMax) {
                currMax = interval[i].second;
            }
        } else {
            currMax = interval[i].second;
        }
    }

    std::cout << ans;
}