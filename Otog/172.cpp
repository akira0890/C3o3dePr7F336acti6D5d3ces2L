#include <iostream>
#include <vector>

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n,m; std::cin >> n >> m;

    std::vector<std::vector<int>> v(n+1 ,std::vector<int>(m+1)) , ans(n+1 ,std::vector<int>(m+1));

    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= m ; j++) {
            std::cin >> v[i][j];
        }
    }

    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= m ; j++) {
            ans[i][j] = std::max(ans[i-1][j] + v[i][j] , ans[i][j-1] + v[i][j]);
        }
    }

    std::cout << ans[n][m];
}