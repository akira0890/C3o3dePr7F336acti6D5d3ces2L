#include <iostream>
#include <queue>

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n,m;
    std::cin >> n >> m;

    std::string grid[2005];
    for (int i = 0 ; i < n ; i++) std::cin >> grid[i];

    int dir[8][2] = {{1,1},{1,0},{1,-1},{0,1},{0,-1},{-1,1},{-1,0},{-1,-1}};
    std::queue<std::pair<int,int>> q;
    
    int ans = 0;
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            if (grid[i][j] == '1') {
                ans++;
                q.emplace(std::make_pair(i,j));

                while (!q.empty()) {
                    auto [y,x] = q.front();
                    q.pop();

                    for (auto [dy,dx] : dir) {
                        int ny = y+dy;
                        int nx = x+dx;
                        if (ny >= 0 && ny < n && nx >= 0 && nx < m && grid[ny][nx] == '1') {
                            q.emplace(std::make_pair(ny,nx));
                            grid[ny][nx] = '0';
                        }
                    }
                }
            }
        }
    }
    std::cout << ans;
}