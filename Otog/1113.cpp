#include <iostream>
#include <vector>

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n,m; std::cin >> n >> m;
    std::vector<int> hori(n), vert(n) , diagl(n) , diagr(n);

    std::vector<std::vector<int>> v(n , std::vector<int>(m,0));

    int t;
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            std::cin >> v[i][j];
        }
    }

    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {

        }
    }
}