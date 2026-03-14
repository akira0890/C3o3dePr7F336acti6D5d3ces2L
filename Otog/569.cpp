#include <iostream>
#include <vector>

class DSU {
    std::vector<int> parent , sz;
public:
    int reachable_count;
    int edge_node;

    DSU(int y, int x) {
        int total = y*x;
        edge_node = total;
        parent.resize(total+1);
        sz.resize(total+1,1);
        sz[edge_node] = 0;
        reachable_count = 0;
        for (int i = 0 ; i < total+1 ; i++) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            if (rootX == find(edge_node) || rootY == find(edge_node)) {
                if (rootX == find(edge_node)) reachable_count += sz[rootY];
                else reachable_count += sz[rootX];
            }

            if (sz[rootX] < sz[rootY]) std::swap(rootX , rootY);
            parent[rootY] = rootX;
            sz[rootX] += sz[rootY];
        }
    }
};

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n,m,q;
    std::cin >> n >> m >> q;
    std::vector<std::pair<int,int>> obt(q);
    std::vector<std::vector<int>> grid(n , std::vector<int>(m,0));
    
    for (int i = 0 ; i < q ; i++) {  
        std::cin >> obt[i].first >> obt[i].second;
        grid[obt[i].first][obt[i].second] = 1;
    }

    DSU dsu(n,m);

    auto getID = [&](int a, int b) { return a*m+b; };

    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            if (grid[i][j] == 0) {
                int curr = getID(i,j);

                if (i==0 || i==n-1 || j==0 || j==m-1) {
                    if (dsu.find(curr) != dsu.find(dsu.edge_node)) {
                        dsu.unite(curr , dsu.edge_node);
                    }
                }

                int md[2][2] = {{1,0},{0,1}};
                for (int k = 0 ; k < 2 ; k++) {
                    int ny = i + md[k][0] , nx = j + md[k][1];
                    if (ny < n && nx < m && grid[ny][nx] == 0) {
                        dsu.unite(curr , getID(ny,nx));
                    }
                }
            }
        }
    }

    std::vector<int> res;
    for (int i = q-1 ; i >= 0 ; i--) {
        res.emplace_back(dsu.reachable_count);

        int y = obt[i].first , x = obt[i].second;
        grid[y][x] = 0;
        int curr = getID(y,x);

        if (y==0 || y==n-1 || x==0 || x==m-1) {
            dsu.unite(curr , dsu.edge_node);
        }

        int md[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};
        for (int k = 0 ; k < 4 ; k++) {
            int ny = y+md[k][0] , nx = x+md[k][1];
            if (ny>=0 && ny<n && nx>=0 && nx<m && grid[ny][nx] == 0) {
                dsu.unite(curr , getID(ny,nx));
            }
        }
    }

    for (int i = q-1 ; i >= 0 ; i--) {
        std::cout << res[i] << '\n';
    }
}