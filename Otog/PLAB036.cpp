#include <iostream>
#include <vector>
#include <queue>

int main() {
    int n,m,start,end; std::cin >> n >> m >> start >> end;
    std::vector<std::vector<int>> g(n , std::vector<int>(n,0));

    std::queue<std::pair<int,int>> q;
    q.emplace(start,0);

    int u,v;
    for (int i = 0 ; i < m ; i++) {
        std::cin >> u >> v;
        g[u][v] = 1;
    }

    while (!q.empty()) {
        auto [dest , dist] = q.front();
        q.pop();

        if (dest == end) {
            std::cout << dist;
            return 0 ;
        }

        for (int i = 0 ; i < n ; i++) {
            if (g[dest][i]) {
                q.emplace(i , dist+1);
            }
        }
    }
}