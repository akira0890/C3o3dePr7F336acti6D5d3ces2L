/*
The problem is to find highest temperature on the incraese adjacency path

To find answer just do bfs or dfs on the unvisited path and the temperature on that position is more than previous
and update answer when temperature at that position is more than currnet
*/

#include <iostream>
#include <queue>

int main() {
    int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    int n,x,y, ans = -100;
    std::cin >> n >> x >> y;

    int grid[n][n];
    bool visited[n][n];
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            std::cin >> grid[i][j];
            visited[i][j] = false;
        }
    }

    ans = grid[y-1][x-1];

    std::queue<std::pair<int,int>> q;
    q.emplace(std::make_pair(y-1,x-1));

    while (!q.empty()) {
        auto [my,mx] = q.front();
        q.pop();

        for (auto [dy,dx] : dir) {
            int ny = my + dy;
            int nx = mx + dx;
            if (ny >= 0 && ny < n && nx >= 0 && nx < n && !visited[ny][nx] && grid[ny][nx] > grid[my][mx] && grid[ny][nx] != 100) {
                q.emplace(std::make_pair(ny,nx));
                visited[ny][nx] = true;
                if (grid[ny][nx] > ans) ans = grid[ny][nx];
            }
        }
    }
    std::cout << ans;
}