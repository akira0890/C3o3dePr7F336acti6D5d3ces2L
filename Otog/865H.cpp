#include <iostream>
#include <vector>
#include <queue>

#define INF 1e9 
#define DMAX 2000005

long long count[DMAX];
long long sum[DMAX];
long long extra[DMAX];

int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n,m,k,Q; std::cin >> n >> m >> k >> Q;

    std::vector<std::vector<long long>> dist(n , std::vector<long long>(m,INF));
    std::queue<std::pair<int,int>> q;

    int y,x;
    for (int i = 1 ; i <= k ; i++) {
        int size = q.size();
        while (size--) {
            auto [cy,cx] = q.front();
            q.pop();
            
            for (int j = 0 ; j < 4 ; j++) {
                int ny = cy + dir[j][0];
                int nx = cx + dir[j][1];
                
                if (ny >= 0 && ny < n && nx >= 0 && nx < m && dist[ny][nx] == INF) {
                    dist[ny][nx] = dist[cy][cx] + 1;
                    q.emplace(ny,nx);
                }
            }
        }
        
        std::cin >> y >> x;

        if (dist[y][x] <= i) {
            extra[i] = 1;
        } else {
            dist[y][x] = i;
            q.emplace(y,x);
            extra[i] = 0;
        }
    }

    while (!q.empty()) {
        auto [cy,cx] = q.front();
        q.pop();
        
        for (int j = 0 ; j < 4 ; j++) {
            int ny = cy + dir[j][0];
            int nx = cx + dir[j][1];
            
            if (ny >= 0 && ny < n && nx >= 0 && nx < m && dist[ny][nx] == INF) {
                dist[ny][nx] = dist[cy][cx] + 1;
                q.emplace(ny,nx);
            }
        }
    }

    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            if (dist[i][j] != INF) {
                count[dist[i][j]]++;
                sum[dist[i][j]] += dist[i][j];
            }
        }
    }

    for (int i = 1 ; i < DMAX ; i++) {
        count[i] += count[i-1];
        sum[i] += sum[i-1];
        extra[i] += extra[i-1];
    }

    long long D;
    while (Q--) {
        std::cin >> D;

        std::cout << (D+1) * count[D] - sum[D] + extra[D] << '\n';
    }
}