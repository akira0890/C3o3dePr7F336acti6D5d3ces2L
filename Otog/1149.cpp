#include <iostream>
#include <vector>
#include <queue>

const int INF = 1e9;
int moves[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};

int n, m;
inline bool checkBorder(int a , int b) {
    return (a > 0 && a <= n && b > 0 && b <= m);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    if (!(std::cin >> n >> m)) return 0;
    
    std::vector<std::vector<char>> v(n+2 , std::vector<char>(m+2, 0));
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= m ; j++) {
            std::cin >> v[i][j];
        }
    }
    
    std::vector<std::vector<int>> dist(n+2, std::vector<int>(m+2, INF));
    std::queue<std::pair<int,int>> q;
    
    q.emplace(1, 1);
    dist[1][1] = 0;

    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0 ; i < 4 ; i++) {
            int dy = moves[i][0];
            int dx = moves[i][1];
            int ny = y + dy;
            int nx = x + dx;

            if (!checkBorder(ny, nx) || v[ny][nx] == '#') continue;

            if (v[ny][nx] == 'U' && dy == -1) {
                if (v[ny-1][nx] != '#') ny--;
            } 
            else if (v[ny][nx] == 'D' && dy == 1) {
                if (v[ny+1][nx] != '#') ny++;
            } 
            else if (v[ny][nx] == 'L' && dx == -1) {
                if (v[ny][nx-1] != '#') nx--;
            } 
            else if (v[ny][nx] == 'R' && dx == 1) {
                if (v[ny][nx+1] != '#') nx++;
            }

            if (!checkBorder(ny, nx)) continue;

            if (dist[y][x] + 1 < dist[ny][nx]) {
                dist[ny][nx] = dist[y][x] + 1;
                q.emplace(ny, nx);
            }
        }
    }

    if (dist[n][m] != INF) std::cout << dist[n][m];
    else std::cout << -1;
}


// #include <iostream>
// #include <vector>
// #include <queue>

// const int INF = 1e9;
// int moves[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};

// int n, m;
// inline bool checkBorder(int a , int b) {
//     return (a > 0 && a <= n && b > 0 && b <= m);
// }

// int main() {
//     std::ios_base::sync_with_stdio(false);
//     std::cin.tie(NULL);

//     if (!(std::cin >> n >> m)) return 0;
    
//     std::vector<std::vector<char>> v(n+2 , std::vector<char>(m+2, 0));
//     for (int i = 1 ; i <= n ; i++) {
//         for (int j = 1 ; j <= m ; j++) {
//             std::cin >> v[i][j];
//         }
//     }
    
//     std::vector<std::vector<bool>> visited(n+2, std::vector<int>(m+2, false));
//     std::queue<std::pair<int,int>> q;
    
//     q.emplace(1, 1);
//     visited[1][1] = 0;

//     while (!q.empty()) {
//         int y = q.front().first;
//         int x = q.front().second;
//         q.pop();

//         for (int i = 0 ; i < 4 ; i++) {
//             int dy = moves[i][0];
//             int dx = moves[i][1];
//             int ny = y + dy;
//             int nx = x + dx;

//             if (!checkBorder(ny, nx) || v[ny][nx] == '#') continue;

//             if (v[ny][nx] == 'U' && dy == -1) {
//                 if (v[ny-1][nx] != '#') ny--;
//             } 
//             else if (v[ny][nx] == 'D' && dy == 1) {
//                 if (v[ny+1][nx] != '#') ny++;
//             } 
//             else if (v[ny][nx] == 'L' && dx == -1) {
//                 if (v[ny][nx-1] != '#') nx--;
//             } 
//             else if (v[ny][nx] == 'R' && dx == 1) {
//                 if (v[ny][nx+1] != '#') nx++;
//             }

//             if (!checkBorder(ny, nx)) continue;

//             if (dist[y][x] + 1 < dist[ny][nx]) {
//                 dist[ny][nx] = dist[y][x] + 1;
//                 q.emplace(ny, nx);
//             }
//         }
//     }

//     if (dist[n][m] != INF && (v[n][m] != 'R' && v[n][m] != 'D')) std::cout << dist[n][m];
//     else std::cout << -1;
// }