// #include <iostream>
// #include <vector>
// #include <queue>

// constexpr int maxn = 105;
// constexpr int maxm = 105;

// struct Node {
//     int dist,cy,cx;

//     Node(int Dist , int cY, int cX) :
//         dist(Dist) , cy(cY),cx(cX) {}
// };

// bool visited[105][105][2525];

// int move[2][6][2] = {
//     {{-1,0},{-1,1},{0,1},{0,-1},{1,0},{1,1}},
//     {{-1,-1},{-1,0},{0,-1},{0,1},{1,-1},{1,0}}
// };

// int main() {
//     // std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);
    
//     int n,m;
//     std::cin >> n >> m;
//     std::vector<std::vector<int>> g(n,std::vector<int>(m));

//     for (int i = 0 ; i < n ; i++) {
//         for (int j = 0 ; j < m ; j++) {
//             std::cin >> g[i][j];
//         }
//     }

//     int targetn = (n-1)/2;

//     std::queue<Node> q;

//     for (auto r : {targetn-1 , targetn , targetn+1}) {
//         if (g[r][0] && 1 % g[r][0] == 0) {
//             visited[r][0][1] = true;
//             q.emplace(1 , r , 0);
//         }
//     }

//     while (!q.empty()) {
//         auto [dist,cy,cx] = q.front();
//         q.pop();
//         int nt = dist+1;

//         if (cy == targetn && cx == m-1) {
//             std::cout << dist;
//             break;
//         }
//         for (int i = 0 ; i < 6 ; i++) {
//             int ny = cy + move[cy % 2][i][0];
//             int nx = cx + move[cy % 2][i][1];
//             if (ny >= 0 && ny < n && nx >= 0 && nx < m) {
//                 if (!visited[ny][nx][nt % 2525] && (g[ny][nx] > 0 && g[ny][nx] % (nt) == 0)) {
//                     std::cout << ny << ' ' << nx << '\n';
//                     visited[ny][nx][nt % 2525] = true;
//                     q.emplace(nt,ny,nx);
//                 }
//             }
//         }
//     }
// }

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node {
    int dist, cy, cx;
};

// ใช้ 2520 เพราะเป็น LCM ของ 1-9
bool visited[105][105][2520];
int g[105][105];

// แยกตาม cx % 2 (คอลัมน์คู่/คี่)
int move_set[2][6][2] = {
    // คอลัมน์คู่ (Even column: 0, 2, 4...)
    {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}},
    // คอลัมน์คี่ (Odd column: 1, 3, 5...)
    {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {1, -1}, {1, 1}}
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int m, n; // m แถว, n คอลัมน์
    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) cin >> g[i][j];
    }

    int start_r = (m - 1) / 2;
    queue<Node> q;

    // ก้าวที่ 1 (t=1) เดินเข้าคอลัมน์ 0 ได้ 3 ช่อง
    for (int r : {start_r - 1, start_r, start_r + 1}) {
        if (r >= 0 && r < m && g[r][0] != 0 && 1 % g[r][0] == 0) {
            visited[r][0][1 % 2520] = true;
            q.push({1, r, 0});
        }
    }

    while (!q.empty()) {
        Node curr = q.front(); q.pop();

        // เป้าหมาย: แถวกลาง คอลัมน์สุดท้าย
        if (curr.cy == start_r && curr.cx == n - 1) {
            cout << curr.dist << endl;
            return 0;
        }

        int nt = curr.dist + 1;
        for (int i = 0; i < 6; i++) {
            int ny = curr.cy + move_set[curr.cx % 2][i][0];
            int nx = curr.cx + move_set[curr.cx % 2][i][1];

            if (ny >= 0 && ny < m && nx >= 0 && nx < n && g[ny][nx] != 0) {
                if (nt % g[ny][nx] == 0 && !visited[ny][nx][nt % 2520]) {
                    visited[ny][nx][nt % 2520] = true;
                    q.push({nt, ny, nx});
                }
            }
        }
    }

    return 0;
}