#include <iostream>
#include <vector>

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int k,n,m,t; std::cin >> k >> n >> m;

    std::vector<std::vector<int>> v(n , std::vector<int>(m));
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            std::cin >> v[i][j];
        }
    }
    std::cin >> t;

    for (int i = 0 ; i < n ; i++) {
        bool found = true;
        for (int j = 0 ; j < m ; j++) {
            if (v[i][j] == t) {
                found = false;
                break;
            }
        }
        if (found) {
            std::cout << i+1 ;
            break;
        }
    }

}