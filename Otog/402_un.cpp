#include <iostream>
#include <vector>
#include <queue>

struct Node {
    int y , x , sum , ix;

    Node(int Y, int X, int SUM , int IX) : y(Y) , x(X) , sum(SUM) , ix(IX) {}
};

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n,m,start; std::cin >> n >> m >> start;

    int my[3] = {-1,0,1};

    std::vector<std::vector<int>> v(n , std::vector<int>(m));
    std::vector<std::vector<long long>> sumv(2 , std::vector<long long>(n , 1e15));
    std::vector<std::vector<std::vector<int>>> save(2 , std::vector<std::vector<int>>(n)); 

    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            std::cin >> v[i][j];
        }
    }

    std::vector<int> ans;
    std::queue<Node> q;
    q.emplace(Node(start-1 , 0 , v[start-1][0] , 1));
    save[0][start-1].emplace_back(v[start-1][0]);

    long long minsum = 1e15 , idx = 1;

    while (!q.empty()) {
        auto [y , x , sum , ix] = q.front();
        q.pop();

        if (ix > idx) {
            std::swap(save[0] , save[1]) , idx++;
            for (int i = 0 ; i < n ; i++) sumv[1][i] = 1e15;
        }
        if (idx == m) break;
        
        for (int i = 0 ; i < 3 ; i++) {
            int ny = y+my[i];
            int nx = x+1;
            if (nx < m && ny >= 0 && ny < n) {
                int nsum = sum + v[ny][nx];

                if (sumv[1][ny] > nsum) {
                    sumv[1][ny] = nsum;
                    q.emplace(Node(ny , nx , nsum , ix+1));
                    save[1][ny] = save[0][y];
                    save[1][ny].emplace_back(v[ny][nx]);
                }
            }
        }
    }

    for (int i = 0 ; i < n ; i++) {
        if (minsum > sumv[0][i]) {
            minsum = sumv[0][i];
            ans = save[0][i];
        }
    }

    std::cout << minsum << '\n';
    for (int x : ans) std::cout << x << ' ';
}