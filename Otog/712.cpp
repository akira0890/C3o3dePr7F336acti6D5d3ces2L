#include <iostream>
#include <vector>
#include <queue>

struct Node {
    int y,x;

    Node(int Y , int X) : y(Y) , x(X) {}
};

int grid[2005][2005];
int dist[2005][2005];

int move[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n,m; std::cin >> n >> m;

    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            std::cin >> grid[i][j];
        }
    }

    std::queue<Node> q;
    q.emplace(0,0);
    dist[0][0] = 0;

    while (!q.empty()) {
        auto [y , x] = q.front();
        q.pop();

        for (int i = 0 ; i < 4 ; i++) {
            int ny = y + move[i][0];
            int nx = x + move[i][1];

            if (ny >= 0 && ny < n && nx >= 0 && nx < m && grid[ny][nx] != 0 && dist[ny][nx] == 0) {
                if (grid[ny][nx] % 2 == 1) {
                    dist[ny][nx] = dist[y][x]+1;
                    q.emplace(ny , nx);
                }
            }
        }
    }

    if (dist[n-1][m-1] != 0) std::cout << dist[n-1][m-1];
    else std::cout << -1;
}