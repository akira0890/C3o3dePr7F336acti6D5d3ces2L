#include <iostream>
#include <vector>
#include <queue>

struct Node {
    int y,x;

    Node(int ny, int nx) : y(ny) , x(nx) {}
};

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n,m,Q, x, y, k; std::cin >> n >> m >> Q;

    std::vector<std::string> grid(n , std::string(m,'.'));
    std::vector<std::vector<int>> max_k(n , std::vector<int>(m,0));
    std::queue<Node> que;

    int dirs[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

    for (int i = 0 ; i < Q ; i++) {
        std::cin >> y >> x >> k;
        grid[y][x] = '#';
    
        que.emplace(y,x);
        max_k[y][x] = std::max(max_k[y][x] , k+1);
    }

    while (!que.empty()) {
        auto [cy,cx] = que.front();
        que.pop();

        int currk = max_k[cy][cx];
        if (currk <= 0) continue;

        for (int i = 0 ; i < 4 ; i++) {
            int ny = cy + dirs[i][0];
            int nx = cx + dirs[i][1];
            if (ny >= 0 && ny < n && nx >= 0 && nx < m && currk-1 > max_k[ny][nx]) {
                if (grid[ny][nx] == '.') grid[ny][nx] = '*';
                que.emplace(ny,nx);
                max_k[ny][nx] = currk-1;
            }
        }
    }

    for (auto &s : grid) std::cout << s << '\n';
}