// #include <iostream>

// int main() {
//     std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);
//     int dirs[8][2] = {{1,1},{1,0},{1,-1},{0,1},{0,-1},{-1,1},{-1,0},{-1,-1}};
//     int n,m;
//     std::cin >> n >> m;

//     char grid[n][m],c;
//     for (int i = 0 ; i < n ; i++) {
//         for (int j = 0 ; j < m ; j++) {
//             std::cin >> c;
//             grid[i][j] = std::tolower(c);
//         }
//     }

//     int q;
//     std::cin >> q;
//     std::string target;
//     for (int i = 0 ; i < q ; i++) {
//         std::cin >> target;
//         for (char &ch : target) ch = std::tolower(ch);
//         int  WordLength = target.length();
//         bool isfound    = false;

//         for (int i = 0 ; i < n ; i++) {
//             for (int j = 0 ; j < m ; j++) {
//                 if (grid[i][j] == target[0]) {
//                     for (int d = 0 ; d < 8 ; d++) {
//                         for (int indexc = 1 ; indexc < WordLength ; indexc++) {
//                             int ny = i + dirs[d][0] * indexc;
//                             int nx = j + dirs[d][1] * indexc;
//                             if (ny >= 0 && ny < n && nx >= 0 && nx < m) {
//                                 if (grid[ny][nx] != target[indexc]) break;
//                                 else if (indexc == WordLength-1) {isfound = true; std::cout << i << ' ' << j << '\n'; break;}
//                             }
//                         }
//                         if (isfound) break;
//                     }
//                 }
//                 if (isfound) break;
//             }
//             if (isfound) break;
//         }
//     }
// }

#include <iostream>

static constexpr int dirs[8][2] = {{1,1},{1,0},{1,-1},{0,1},{0,-1},{-1,1},{-1,0},{-1,-1}};

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);
    int n,m;
    std::cin >> n >> m;

    char grid[n][m],temp;
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            std::cin >> temp;
            grid[i][j] = tolower(temp);
        }
    }

    int q;
    std::cin >> q;
    while (q--) {
        std::string target;
        std::cin >> target;

        int len = target.length();
        bool found = false;
        
        for (int i = 0 ; i < len ; i++) target[i] = tolower(target[i]);

        for (int i = 0 ; i < n && !found ; i++) {
            for (int j = 0 ; j < m && !found ; j++) {
                if (grid[i][j] != target[0]) continue;

                for (auto &dir : dirs) {
                    bool ok = true;
                    for (int k = 1 ; k < len ; k++) {
                        int y = i + dir[0] * k;
                        int x = j + dir[1] * k;
                        if (x < 0 || x >= m || y < 0 || y >= n || grid[y][x] != target[k]) {
                            ok = false;
                            break;
                        }
                    }

                    if (ok) {
                        std::cout << i << ' ' << j << '\n';
                        found = true;
                        break;
                    }
                }
            }
        }
    }
}