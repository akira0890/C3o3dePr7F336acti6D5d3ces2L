#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n,m; std::cin>> n >> m;

    std::vector<std::vector<int>> v(n , std::vector<int>(m,0));
    std::vector<int> pre(m+1,0) , curr(m+1,0);

    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            std::cin >> v[i][j];
        }
    }

    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= m ; j++) {
            curr[j] = std::max(curr[j-1] + v[i-1][j-1] , pre[j] + v[i-1][j-1]);
        }

        std::swap(pre,curr);
    }

    std::cout << pre[m];
}