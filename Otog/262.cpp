#include <iostream>
#include <vector>
#include <queue>

struct Node {
    int y,x,t;

    Node(int y , int x , int t) : y(y) , x(x) , t(t) {}
};

int move[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n,m; std::cin >> n >> m;

    std::vector<std::vector<char>> v(n , std::vector<char>(m));

    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            std::cin >> v[i][j];
        }
    }

    std::vector<std::vector<bool>> visited(n , std::vector<bool>(m,false));
    std::queue<Node> q;
    q.emplace(0,0,1);

    int currt = 50000000;
    int cy , cx;

    while (!q.empty()) {
        Node curr = q.front();
        q.pop();

        if (curr.y >= n || curr.x >= m) continue;

        if (visited[curr.y][curr.x]) {
            if (curr.t < currt) {
                currt = curr.t;
                cy = curr.y+1;
                cx = curr.x+1;
            }
        }

        visited[curr.y][curr.x] = true;

        if (v[curr.y][curr.x] == 'B') {
            q.emplace(curr.y+1 , curr.x , curr.t+1);
            q.emplace(curr.y , curr.x+1 , curr.t+1);
        } else if (v[curr.y][curr.x] == 'R') {
            q.emplace(curr.y , curr.x+1 , curr.t+1);
        } else if (v[curr.y][curr.x] == 'D') {
            q.emplace(curr.y+1 , curr.x , curr.t+1);
        }

        if (curr.y-1 >= 0 && !visited[curr.y-1][curr.x] && v[curr.y-1][curr.x] == 'D') {
            q.emplace(curr.y-1 , curr.x , curr.t+1);
        }
        if (curr.x-1 >= 0 && !visited[curr.y][curr.x-1] && v[curr.y][curr.x-1] == 'R') {
            q.emplace(curr.y , curr.x-1 , curr.t+1);
        }
    }

    std::cout << currt << '\n';
    std::cout << cy << ' ' << cx;
}