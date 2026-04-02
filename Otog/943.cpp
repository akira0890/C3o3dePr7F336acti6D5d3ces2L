#include <iostream>
#include <vector>
#include <queue>

const int offset = 200;
int move[4][2] = {{1,0} , {0,1} , {-1,0} , {0,-1}};

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n,m,b,l,Q; std::cin >> n >> m >> b >> l >> Q;
    std::vector<std::vector<int>> v(n+offset, std::vector<int>(m+offset));

    for (int i = offset ; i < n+offset ; i++) {
        for (int j = offset ; j < m+offset ; j++) {
            std::cin >> v[i][j];
        }
    }

    std::vector<std::vector<int>> diff(n+offset, std::vector<int>(m+offset,0));

    int y,x;
    for (int i = 0 ; i < b ; i++) {
        std::cin >> y >> x;
        for (int len = 0 ; len < l+1 ; len++) {
            diff[y-l+len][x-len] += 1;
            diff[y+len+1][x+l+1-len] -= 1;
        }
    }

    for (int i = n-1 ; i >= 0 ; i--) {
        for (int j = 1 ; j < n-1-i ; j++) {
            diff[i][j] += diff[i-1][j-1];
        }
    }

    for (int i = 0 ; i < Q ; i++) {
        std::cin >> y >> x;
        std::cout << v[y+offset][x+offset]-diff[y][x] << '\n';
    }
}