#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

struct Node {
    int y , x;

    Node(int y , int x) : y(y) , x(x) {}
};

int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int f,n,m; std::cin >> f >> n >> m;
    std::vector<std::string> v(n);
    std::vector<long long> Sum;

    for (int floor = 0 ; floor < f ; floor++) {
        for (int i = 0 ; i < n ; i++) std::cin >> v[i];

        std::vector<std::vector<bool>> visited(n ,std::vector<bool>(m,false));
        long long maxSum = 0;

        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < m ; j++) {
                if (!visited[i][j] && v[i][j] != '#') {
                    long long currsum = (v[i][j] == 'X' ? 1 : 0);

                    std::queue<Node> q;
                    q.emplace(i,j);
                    visited[i][j] = true;

                    while (!q.empty()) {
                        Node curr = q.front();
                        q.pop();

                        for (int k = 0 ; k < 4 ; k++) {
                            int ny = curr.y + dir[k][0];
                            int nx = curr.x + dir[k][1];

                            if (ny >= 0 && ny < n && nx >= 0 && nx < m && !visited[ny][nx] && v[ny][nx] != '#') {
                                visited[ny][nx] = true;
                                if (v[ny][nx] == 'X') currsum++;
                                q.emplace(ny,nx);
                            }
                        }
                    }

                    maxSum = std::max(maxSum , currsum);
                }
            }
        }

        Sum.emplace_back(maxSum);
    }

    std::sort(Sum.begin() , Sum.end() , std::greater<long long>());

    for (int i = 1 ; i < Sum.size() ; i++) {
        Sum[i] += Sum[i-1];
    }

    int target;
    int t; std::cin >> t;

    for (int i = 0 ; i < t ; i++) {
        std::cin >> target;

        auto it = std::lower_bound(Sum.begin() , Sum.end() , target);
        
        if (it == Sum.end()) std::cout << "-1\n";
        else std::cout << it - Sum.begin() + 1 << '\n';
    }
}