#include <iostream>
#include <vector>
#include <cmath>

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n; std::cin >> n;

    std::vector<std::string> grid(n, std::string(n,'-'));
    float cx = n/2,cy = n/2;
    int r=n/2;
    std::cout << cx << ' ' << cy << '\n';

    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            float nx = cx-j;
            float ny = cy-i;
            if (nx*nx + ny*ny >= r*r - r && nx*nx + ny*ny <= r*r+r) grid[i][j] = '#';
        }
    }

    for (std::string &s : grid) std::cout << s << '\n';
}