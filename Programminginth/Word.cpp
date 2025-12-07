#include <iostream>

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);
    int dirs[8][2] = {{1,1},{1,0},{1,-1},{0,1},{0,-1},{-1,1},{-1,0},{-1,-1}};
    int n,m;
    std::cin >> n >> m;

    char grid[n][m],c;
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            std::cin >> c;
            grid[i][j] = std::tolower(c);
        }
    }

    int q;
    std::cin >> q;
    std::string target;
    for (int i = 0 ; i < q ; i++) {
        std::cin >> target;
        for (char &ch : target) ch = std::tolower(ch);
        int  WordLength = target.length();
        bool isfound    = false;

        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < m ; j++) {
                if (grid[i][j] == target[0]) {
                    for (int d = 0 ; d < 8 ; d++) {
                        for (int indexc = 1 ; indexc < WordLength ; indexc++) {
                            int ny = i + dirs[d][0] * indexc;
                            int nx = j + dirs[d][1] * indexc;
                            if (ny >= 0 && ny < n && nx >= 0 && nx < m) {
                                if (grid[ny][nx] != target[indexc]) break;
                                else if (indexc == WordLength-1) {isfound = true; std::cout << i << ' ' << j << '\n'; break;}
                            }
                        }
                        if (isfound) break;
                    }
                }
                if (isfound) break;
            }
            if (isfound) break;
        }
    }

}