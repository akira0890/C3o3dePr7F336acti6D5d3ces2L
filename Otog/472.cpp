#include <iostream>
#include <vector>
#include <queue>
#include <climits>

int move[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n,m; std::cin >> n >> m;
    std::vector<std::string> v(n);
    for (int i = 0 ; i < n ; i++) std::cin >> v[i];

    std::vector<std::vector<int>> dist(n , std::vector<int>(m,INT_MAX));
    std::queue<std::pair<int,int>> q;

    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            if (v[i][j] == 'X') {
                dist[i][j] = 0;
                q.emplace(i,j);
            }
        }
    }

    int success = 0;
    int minDist = 0;

    while (!q.empty()) {
        auto [y,x] = q.front();
        q.pop();

        if (v[y][x] == 'A') {
            success++;
            minDist += dist[y][x]*2;
        }

        for (int i = 0 ; i < 4 ; i++) {
            int ny = y + move[i][0];
            int nx = x + move[i][1];

            if (ny >= 0 && ny < n && nx >= 0 && nx < m &&
                v[ny][nx] != 'W' && dist[ny][nx] == INT_MAX) {
                    q.emplace(ny,nx);
                    dist[ny][nx] = dist[y][x]+1;
                }
        }
    }

    std::cout << success << ' ' << minDist;
}