#include <iostream>
#include <vector>
#include <queue>

struct Node {
    int dist , y , x;

    Node (int d, int Y, int X) : dist(d) , y(Y) , x(X) {}
};

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n,m; std::cin >> n >> m;

    std::vector<std::string> v(n);
    std::vector<std::vector<bool>> visited(n , std::vector<bool>(m , false));
    for (int i = 0 ; i < n ; i++) std::cin >> v[i];

    int sy,sx,ty,tx; std::cin >> sy >> sx >> ty >> tx;
    sy--;sx--;ty--;tx--;

    std::queue<Node> q;
    q.emplace(Node{0,sy,sx});
    visited[sy][sx] = true;

    int d[8][2] = {{-2,-1},{-1,-2},{-2,1},{1,-2},{2,-1},{-1,2},{1,2},{2,1}};

    while (!q.empty()) {
        auto [dist , cy , cx] = q.front();
        q.pop();

        if (cy == ty && cx == tx) {
            std::cout << dist;
            return 0;
        }

        for (int i = 0 ; i < 8 ; i++) {
            int ny = cy + d[i][0];
            int nx = cx + d[i][1];
            if (ny >= 0 && ny < n && nx >= 0 && nx < m && v[ny][nx] != 'X' && !visited[ny][nx]) {
                q.emplace(Node{dist+1 , ny , nx});
                visited[ny][nx] = true;
            }
        }
    }

    std::cout << -1;
}