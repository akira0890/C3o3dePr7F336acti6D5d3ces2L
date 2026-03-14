#include <iostream>
#include <vector>

int n,m;
int v[7][7] , ans = 0;
bool visited[7][7];
int dirs[4][2] = {{0,1},{1,0},{-1,0},{0,-1}};

void recursive(int y , int x , int sum) {
    if (sum <= 0) return;
    if (y == n-1 && x == m-1) {
        ans = std::max(ans , sum);
        return;
    }

    for (int i = 0 ; i < 4 ; i++) {
        int ny = y + dirs[i][0];
        int nx = x + dirs[i][1];
        if (ny >= 0 && ny < n && nx >= 0 && nx < m && !visited[ny][nx]) {
            visited[ny][nx] = true;
            recursive(ny , nx , sum + v[ny][nx]);
            visited[ny][nx] = false;
        }
    }
}

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    std::cin >> n >> m;
    char cmd;
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            std::cin >> cmd;
            if (cmd == '*') v[i][j] = 1;
            else if (cmd == 'X') v[i][j] = -1;
            else v[i][j] = 0;
        }
    }

    visited[0][0] = true;
    recursive(0,0,3);

    std::cout << ans;
    
}