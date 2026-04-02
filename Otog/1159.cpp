#include <iostream>
#include <vector>
#include <queue>
#include <climits>

#define pli std::pair<long long , int>

int height[305];

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n,m; std::cin >> n >> m;
    for (int i = 0 ; i < n ; i++) std::cin >> height[i];

    std::vector<std::vector<int>> g(n);
    int u,v;

    for (int i = 0 ; i < m ; i++) {
        std::cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }


    long long minMST = LLONG_MAX;
    int idx = 0;
    for (int i = 0 ; i < n ; i++) {
        int tempHeight = height[i];
        for (int j = 0 ; j < g[i].size() ; j++) {
            height[i] = height[g[i][j]];
            std::priority_queue<pli , std::vector<pli> , std::greater<pli>> pq;
            std::vector<bool> visited(n,false);
            long long MST = 0;
    
            pq.emplace(0,0);
            // if (i == 0) pq.emplace(0,1);
            // else pq.emplace(0,0);
    
            while (!pq.empty()) {
                auto [dist , curr] = pq.top();
                pq.pop();
    
                if (visited[curr]) continue;
                MST += dist;
                visited[curr] = true;
    
                for (int dest : g[curr]) {
                    if (!visited[dest]) {
                        pq.emplace(std::abs(height[curr] - height[dest]) , dest);
                    }
                }
            }
    
            if (MST < minMST) {
                minMST = MST;
                idx = i;
            }
        }
        height[i] = tempHeight;
    }

    std::cout << idx;
}