#include <iostream>
#include <queue>
#include <vector>

int main() {
    int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    int n, ans = 0;
    std::cin >> n;

    std::vector<std::vector<int>> table(n+2, std::vector<int>(n+2,0));
    for (int i = 1 ; i <= n ; i++) for (int j = 1 ; j  <= n ; j++) std::cin >> table[i][j];
    
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= n ; j++) {
            int val = table[i][j];
            bool isvalid = false;
            if (val == 0) continue;
            
            if (table[i][j+1] == val && table[i+1][j] == val) isvalid = true;
            else if (table[i-1][j] == val && table[i][j-1] == val) isvalid = true;
            else if (table[i][j-1] == val && table[i+1][j] == val) isvalid = true;
            else if (table[i-1][j] == val && table[i][j+1] == val) isvalid = true;
            
            std::vector<std::vector<bool>> visited(n+2 , std::vector<bool>(n+2 , false));
            std::queue<std::pair<int,int>> q;
            q.emplace(std::make_pair(i,j));
            visited[i][j] = true;
            int sum = 1;

            while (!q.empty()) {
                auto [y,x] = q.front();
                q.pop();

                for (auto [dy,dx] : dirs) {
                    int ny = y + dy;
                    int nx = x + dx;
                    if (table[ny][nx] == val && !visited[ny][nx]) {
                        q.emplace(std::make_pair(ny,nx));
                        visited[ny][nx] = true;
                        sum++;
                    }
                }
            }
            if (isvalid && sum == 3) ans++;
        }
    }
    std::cout << ans;
    return 0;
}