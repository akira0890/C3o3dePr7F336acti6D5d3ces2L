#include <iostream>
#include <vector>
#include <queue>
#include <climits>

class DSU {
    std::vector<int> parent;
public:
    DSU(int n) {
        parent.resize(n+1);
        for (int i = 0 ; i <= n ; i++) parent[i] = i;
    }

    int find(int n) {
        if (parent[n] == n)
            return n;
        return parent[n] = find(parent[n]);
    }

    void unite(int u , int v) {
        int pu = find(u);
        int pv = find(v);
        if (pu != pv) parent[pu] = pv;
    }
};

int moves[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

int main() {
//    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n,m,k ;std::cin >> n >> m >> k;
    std::vector<std::vector<int>> v(n , std::vector<int>(m));

    std::priority_queue<std::pair<long long , std::pair<int,int>>> pq;
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            std::cin >> v[i][j];
            pq.emplace(v[i][j] , std::make_pair(i,j));
        }
    }

    std::vector<std::vector<int>> time(n , std::vector<int>(m, INT_MAX));
    std::queue<std::pair<int,int>> q;

    int y,x;
    for (int i = 0 ; i < k ; i++) {
        std::cin >> y >> x;
        y--;
        x--;
        time[y][x] = std::min(time[y][x] , i+1);
        q.emplace(y,x);
    }

    while (!q.empty()) {
        auto pos = q.front();
        int y = pos.first;
        int x = pos.second;
        q.pop();

        for (int i = 0 ; i < 4 ; i++) {
            int ny = y + moves[i][0];
            int nx = x + moves[i][1];
            if (ny >= 0 && ny < n && nx >= 0 && nx < m && time[y][x]+1 < time[ny][nx]) {
                time[ny][nx] = time[y][x]+1;
                q.emplace(ny,nx);
            }
        }
    }

    DSU dsu(n*m+k);
    long long sum = 0;
    while (!pq.empty()) {
        auto p = pq.top();
        long long value = p.first;
        auto pos = p.second;
        int y = pos.first;
        int x = pos.second;
        pq.pop();

//        std::cout << y << ' ' << x << ' ' << time[y][x] << ' ';
        int target = dsu.find(time[y][x]);
//        std::cout << target << ' ' << time[y][x] << '\n';
        if (target > 0) {
            sum += value;
            dsu.unite(target , target-1);
        }
    }

    std::cout << sum;
}