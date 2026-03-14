#include <iostream>
#include <vector>
#include <queue>

#define pii std::pair<int , int>

int move[8][2] = {
    {-1,-1},
    {-1,0},
    {-1,1},
    {0,-1},
    {0,1},
    {1,-1},
    {1,0},
    {1,1}
};

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n,m; std::cin >> n >> m;

    std::vector<std::string> v(n);
    std::vector<std::vector<bool>> visited(n ,std::vector<bool>(m , false));
    for (int i = 0 ; i < n ; i++) std::cin >> v[i];

    int ans = 0;

    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            if (v[i][j] == '1' && !visited[i][j]) {
                ans++;

                std::queue<pii> q;
                q.emplace(i,j);
                visited[i][j] = true;

                while (!q.empty()) {
                    auto [y,x] = q.front();
                    q.pop();

                    for (int k = 0 ; k < 8 ; k++) {
                        int ny = y+move[k][0];
                        int nx = x+move[k][1];

                        if (ny >= 0 && ny < n && nx >= 0 && nx < m && v[ny][nx] == '1' && !visited[ny][nx]) {
                            visited[ny][nx] = true;
                            q.emplace(ny,nx);
                        }
                    }
                }
            }
        }
    }

    std::cout << ans;
}