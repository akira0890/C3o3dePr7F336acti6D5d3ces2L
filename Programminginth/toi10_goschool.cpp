#include <iostream>
#include <vector>
#include <cstdint>

#define int long long

int32_t main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n,m,k; std::cin >> n >> m >> k;
    std::vector<std::vector<int>> v(n+1 , std::vector<int>(m+1,0));
    std::vector<std::vector<bool>> canGo(n+1 , std::vector<bool>(m+1 , true));

    int y,x;
    for (int i = 0 ; i < k ; i++) {
        std::cin >> y >> x;
        canGo[y][x] = false;
    }
    v[1][1] = 1;

    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= m ; j++) {
            if (canGo[i][j]) {
                if (i > 1) v[i][j] += v[i-1][j];
                if (j > 1) v[i][j] += v[i][j-1];
            }
            else v[i][j] = 0;
        }
    }

    std::cout << v[n][m];
}