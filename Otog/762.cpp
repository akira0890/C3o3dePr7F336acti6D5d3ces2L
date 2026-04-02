#include <iostream>
#include <vector>
#include <queue>

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int q,n,m; std::cin >> q;
    
    for (int i = 0 ; i < q ; i++) {
        std::cin >> n >> m;
        std::vector<std::vector<int>> g(n);
        std::vector<int> type(n,-1);

        int u,v;
        for (int i = 0 ; i < m ; i++) {
            std::cin >> u >> v;
            g[u].emplace_back(v);
            g[v].emplace_back(u);
        }

        std::queue<int> q;
        bool answer = false;
        
        for (int i = 0 ; i < n ; i++) {
            if (type[i] == -1) {
                q.emplace(i);
                type[i] = 0;
                while (!q.empty()) {
                    int curr = q.front();
                    q.pop();
        
                    for (int dest : g[curr]) {
                        if (type[dest] == -1) {
                            type[dest] = (type[curr] ? 0 : 1);
                            q.emplace(dest);
                        } else {
                            // std::cout << "d " << curr << ' ' << dest << '\n';
                            if (type[curr] == type[dest]) {
                                answer = true;
                                goto finds;
                            }
                        }
                    }
                }
            }
        }

        finds:

        if (answer) std::cout << "Gay found!\n";
        else std::cout << "Gay not found!\n";
    }
}